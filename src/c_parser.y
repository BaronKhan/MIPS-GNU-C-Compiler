%{
#include <iostream>
#include <cstdlib>
#include "c_ast.hpp"
#include <cstring>

using namespace std;

int yylex();
int yyerror(const char* s);
void indent(int n);

int n = 0;
Type_Node* currentType = NULL;	//Used for chaining types through declarations

int variable_count = 0;		//count the number of variables in function, and increment fp accordingly
int global_variable_count = 0;
%}

%union{
	int num;
	double fp;
	char* str;
	char ch;
	struct Node* NodePtr;
	struct Function_Node* Func_NodePtr;
	struct ID_Node* ID_NodePtr;
	struct Block_Node* Block_NodePtr;
	struct Op_Node* Op_NodePtr;
	struct Type_Node* Type_NodePtr;
	struct Parameter_Node* Parameter_NodePtr;
	struct Call_Node* Call_NodePtr;
}

//only used in lexer
%token	CONSTANT
%token	KEYWORD
%token	OPERATOR
%token	STRINGLITERAL
//only used in lexer^^

%token 	INTCONST
%token 	FLOATCONST
%token 	STRING
%token	IDENTIFIER
%token	INVALID

%token 	FOR IF ELSE TYPEDEF WHILE DO RETURN CONST EXTERN CONTINUE DEFAULT GOTO SWITCH 
%token 	INT CHAR FLOAT DOUBLE LONG SHORT UNSIGNED VOID STATIC REGISTER BREAK AUTO UNION 
%token 	ENUM SIGNED CASE VOLATILE STRUCT

%token 	ADD SUB MUL DIV MOD LEFT RIGHT EQ COMP NOTEQ LTEQ GTEQ GT LT SQUARELEFT SQUARERIGHT PERIOD
%token 	SCOPELEFT SCOPERIGHT SEMI COLON COMMA INC DEC QUES BWNOT LOGICNOT BWAND LOGICAND BWOR LOGICOR XOR SIZEOF
%token 	SHIFTL SHIFTR POINTER

%token	ADDASSIGN SUBASSIGN MULASSIGN DIVASSIGN MODASSIGN ANDASSIGN ORASSIGN XORASSIGN SHIFTLASSIGN SHIFTRASSIGN 


%type<str> 	IDENTIFIER STRING
%type<num> 	INTCONST ArrayDecl
%type<fp>	FLOATCONST


%type<NodePtr>	File Block Function Statement Expr PrimaryExpr Declaration GlobalDeclaration Call Argument
%type<NodePtr>	Assignment Value PostFixExpr ConditionalExpr TernaryExpr
%type<NodePtr>	ExprStatement ReturnStatement IfStatement ElseStatement WhileStatement ForStatement DoWhileStatement
%type<NodePtr> 	DeclStatement GlobalDeclStatement CompoundStatement CompoundStatement2

%type<Op_NodePtr>	OpAssign OpCond

%type<Op_NodePtr>	OpManipulate OpManipulate2 OpManipulate3 OpManipulate4 OpManipulate5 OpManipulate6 OpManipulate7 OpManipulate8

%type<NodePtr>		UnaryExpr UnaryExpr2 UnaryExpr3 UnaryExpr4 UnaryExpr5 UnaryExpr6 UnaryExpr7 UnaryExpr8

%type<Type_NodePtr>	CompoundType

%type<Parameter_NodePtr>	Parameter

%type<str>	OpUnary


%type<str> 	ADD SUB MUL DIV MOD LEFT RIGHT EQ COMP NOTEQ LTEQ GTEQ GT LT SQUARELEFT SQUARERIGHT PERIOD
%type<str> 	SCOPELEFT SCOPERIGHT SEMI COLON COMMA INC DEC QUES BWNOT LOGICNOT BWAND LOGICAND BWOR LOGICOR XOR SIZEOF
%type<str> 	SHIFTL SHIFTR POINTER
%type<str>	ADDASSIGN SUBASSIGN MULASSIGN DIVASSIGN MODASSIGN ANDASSIGN ORASSIGN XORASSIGN SHIFTLASSIGN SHIFTRASSIGN
%type<str>	Type

%type<str>	TYPEDEF CONST EXTERN
%type<str>	INT CHAR FLOAT DOUBLE LONG SHORT UNSIGNED VOID STATIC REGISTER AUTO UNION 
%type<str>	ENUM SIGNED VOLATILE STRUCT


%right	ADD SUB 

%{
File_Node* root = new File_Node;
%}


%start	File

%%


File		: 	GlobalDeclStatement File	{root->file_list.push_back($1);}
		|	Function File			{root->file_list.push_back($1);}
		| 	GlobalDeclStatement		{root->file_list.push_back($1);}
		|	Function			{root->file_list.push_back($1);}
		;
		
Function	:	CompoundType IDENTIFIER LEFT Parameter RIGHT Block	{ID_Node* id = new ID_Node($2); Function_Node* func = new Function_Node(id,$4,$6,variable_count); $$ = func; variable_count = 0;}
		|	CompoundType IDENTIFIER LEFT RIGHT Block		{ID_Node* id = new ID_Node($2); Function_Node* func = new Function_Node(id,NULL,$5,variable_count); $$ = func; variable_count = 0;}
		|	CompoundType IDENTIFIER LEFT Parameter RIGHT SEMI	{ID_Node* id = new ID_Node($2); Node* decl = new Decl_Node(currentType, id, false, NULL, NULL); $$ = decl; global_variable_count++;}
		|	CompoundType IDENTIFIER LEFT RIGHT SEMI			{ID_Node* id = new ID_Node($2); Node* decl = new Decl_Node(currentType, id, false, NULL, NULL); $$ = decl; global_variable_count++;}
		;

Block		:	StartScope CompoundStatement EndScope	{Block_Node* block = new Block_Node($2); $$ = block;}
		|	StartScope EndScope			{Block_Node* block = new Block_Node(NULL); $$ = block;}
		;
		
StartScope	:	SCOPELEFT	
		;
		
EndScope	:	SCOPERIGHT	
		;


Parameter	:	CompoundType IDENTIFIER COMMA Parameter	{ID_Node* id = new ID_Node($2); Parameter_Node* p = new Parameter_Node($1,id,$4); $$ = p; variable_count++;}
		|	CompoundType IDENTIFIER			{ID_Node* id = new ID_Node($2); Parameter_Node* p = new Parameter_Node($1,id,NULL); $$ = p; variable_count++;}
		;

CompoundStatement:	DeclStatement CompoundStatement		{Node* compound = new CompoundStatement_Node($1,$2); $$ = compound;}
		|	Block CompoundStatement2		{Node* compound = new CompoundStatement_Node($1,$2); $$ = compound;}
		|	CompoundStatement2			{Node* compound = new CompoundStatement_Node($1,NULL); $$ = compound;}
		|	DeclStatement				{Node* compound = new CompoundStatement_Node($1,NULL); $$ = compound;}
		;

CompoundStatement2:	Block CompoundStatement2		{Node* compound = new CompoundStatement_Node($1,$2); $$ = compound;}
		|	Statement CompoundStatement2		{Node* compound = new CompoundStatement_Node($1,$2); $$ = compound;}
		|	Statement				{Node* compound = new CompoundStatement_Node($1,NULL); $$ = compound;}
		;
		
DeclStatement	:	CompoundType Declaration SEMI		{Node* declStatement = new DeclStatement_Node($1, $2, false); $$ = declStatement;}
		|	CompoundType MUL Declaration SEMI	{Node* declStatement = new DeclStatement_Node($1, $3, true); $$ = declStatement;}
		;

Declaration	:	IDENTIFIER COMMA Declaration			{ID_Node* id = new ID_Node($1); Node* decl = new Decl_Node(currentType, id, false, NULL, $3); $$ = decl; variable_count++;}
		|	IDENTIFIER ArrayDecl COMMA Declaration		{ID_Node* id = new ID_Node($1); Node* decl = new Decl_Node(currentType, id, false, NULL, $4, $2); $$ = decl; variable_count+=$2;}
		|	IDENTIFIER EQ Expr				{ID_Node* id = new ID_Node($1); Node* decl = new Decl_Node(currentType, id, true, $3, NULL); $$ = decl; variable_count++;}
		|	IDENTIFIER EQ Expr COMMA Declaration		{ID_Node* id = new ID_Node($1); Node* decl = new Decl_Node(currentType, id, true, $3, $5); $$ = decl; variable_count++;}
		|	IDENTIFIER					{ID_Node* id = new ID_Node($1); Node* decl = new Decl_Node(currentType, id, false, NULL, NULL); $$ = decl; variable_count++;}
		|	IDENTIFIER ArrayDecl				{ID_Node* id = new ID_Node($1); Node* decl = new Decl_Node(currentType, id, false, NULL, NULL, $2); $$ = decl; variable_count+=$2;}
		;
		
		
GlobalDeclStatement	:	CompoundType GlobalDeclaration SEMI		{Node* declStatement = new DeclStatement_Node($1, $2, false); $$ = declStatement;}
			|	CompoundType MUL GlobalDeclaration SEMI		{Node* declStatement = new DeclStatement_Node($1, $3, true); $$ = declStatement;}
			;
		
GlobalDeclaration	:	IDENTIFIER COMMA GlobalDeclaration			{ID_Node* id = new ID_Node($1); Node* decl = new Decl_Node(currentType, id, false, NULL, $3); $$ = decl; global_variable_count++;}
			|	IDENTIFIER ArrayDecl COMMA GlobalDeclaration		{ID_Node* id = new ID_Node($1); Node* decl = new Decl_Node(currentType, id, false, NULL, $4, $2); $$ = decl; global_variable_count+=$2;}
			|	IDENTIFIER EQ Expr					{ID_Node* id = new ID_Node($1); Node* decl = new Decl_Node(currentType, id, true, $3, NULL); $$ = decl; global_variable_count++;}
			|	IDENTIFIER EQ Expr COMMA GlobalDeclaration		{ID_Node* id = new ID_Node($1); Node* decl = new Decl_Node(currentType, id, true, $3, $5); $$ = decl; global_variable_count++;}
			|	IDENTIFIER						{ID_Node* id = new ID_Node($1); Node* decl = new Decl_Node(currentType, id, false, NULL, NULL); $$ = decl; global_variable_count++;}
			|	IDENTIFIER ArrayDecl					{ID_Node* id = new ID_Node($1); Node* decl = new Decl_Node(currentType, id, false, NULL, NULL, $2); $$ = decl; global_variable_count+=$2;}
			;


Statement	:	ExprStatement				{Node* new_statement = new Statement_Node($1); $$ = new_statement;}
		|	IfStatement				{Node* new_statement = new Statement_Node($1); $$ = new_statement;}
		|	WhileStatement				{Node* new_statement = new Statement_Node($1); $$ = new_statement;}
		|	ForStatement				{Node* new_statement = new Statement_Node($1); $$ = new_statement;}
		|	ReturnStatement				{Node* new_statement = new Statement_Node($1); $$ = new_statement;}
		|	DoWhileStatement				{Node* new_statement = new Statement_Node($1); $$ = new_statement;}
		;

ExprStatement	:	Expr SEMI				{Node* new_expr_statement = new ExprStatement_Node($1); $$ = new_expr_statement;}
		;


IfStatement	:	IF LEFT Expr RIGHT Statement			{Node* new_if_statement = new IfStatement_Node($3, $5, NULL); $$ = new_if_statement;}
		|	IF LEFT Expr RIGHT Block			{Node* new_if_statement = new IfStatement_Node($3, $5, NULL); $$ = new_if_statement;}
		|	IF LEFT Expr RIGHT Statement ElseStatement	{Node* new_if_statement = new IfStatement_Node($3, $5, $6); $$ = new_if_statement;}
		|	IF LEFT Expr RIGHT Block ElseStatement		{Node* new_if_statement = new IfStatement_Node($3, $5, $6); $$ = new_if_statement;}
		;

ElseStatement	:	ELSE Statement					{$$ = $2;}
		|	ELSE Block					{$$ = $2;}
		;
		
WhileStatement	:	WHILE LEFT Expr RIGHT Statement			{Node* new_while_statement = new WhileStatement_Node($3, $5); $$ = new_while_statement;}
		|	WHILE LEFT Expr RIGHT Block			{Node* new_while_statement = new WhileStatement_Node($3, $5); $$ = new_while_statement;}
		;
		
ForStatement	:	FOR LEFT ExprStatement ExprStatement Expr RIGHT Statement	{Node* new_for_statement = new ForStatement_Node($3,$4,$5,$7); $$ = new_for_statement;}
		|	FOR LEFT ExprStatement ExprStatement Expr RIGHT Block		{Node* new_for_statement = new ForStatement_Node($3,$4,$5,$7); $$ = new_for_statement;}
		;
		
		
ReturnStatement	:	RETURN Expr SEMI		{Node* new_return_statement = new ReturnStatement_Node($2); $$ = new_return_statement;}
		|	RETURN SEMI			{Node* new_return_statement = new ReturnStatement_Node(NULL); $$ = new_return_statement;}
		;
		
DoWhileStatement:	DO Block WHILE LEFT Expr RIGHT SEMI		{Node* new_do_while_statement = new DoWhileStatement_Node($5, $2); $$ = new_do_while_statement;}
		|	DO Statement WHILE LEFT Expr RIGHT SEMI		{Node* new_do_while_statement = new DoWhileStatement_Node($5, $2); $$ = new_do_while_statement;}
		;
		

Expr		:	Expr COMMA Assignment
		|	Assignment					{$$ = $1;}
		;

Assignment	:	Assignment OpAssign UnaryExpr			{Node* new_node = new Assignment_Node($1, $2, $3); $$ = new_node;}
		|	Assignment OpAssign ConditionalExpr		{Node* new_node = new Assignment_Node($1, $2, $3); $$ = new_node;}
		|	Assignment OpAssign TernaryExpr			{Node* new_node = new Assignment_Node($1, $2, $3); $$ = new_node;}
		|	TernaryExpr					{$$ = $1;}
		|	ConditionalExpr					{$$ = $1;}
		|	UnaryExpr					{$$ = $1;}
		;
		
TernaryExpr	:	ConditionalExpr QUES UnaryExpr COLON UnaryExpr	{Node* new_node = new Ternary_Node($1,$3,$5); $$ = new_node;}
		;
		
ConditionalExpr	:	UnaryExpr OpCond UnaryExpr			{Node* new_node = new Expr_Node($1, $2, $3); $$ = new_node;}
		;

UnaryExpr	:	UnaryExpr2					{$$ = $1;}
		|	UnaryExpr OpManipulate UnaryExpr2		{Node* new_node = new Expr_Node($1, $2, $3); $$ = new_node;}
		;
		
UnaryExpr2	:	UnaryExpr3					{$$ = $1;}
		|	UnaryExpr2 OpManipulate2 UnaryExpr3		{Node* new_node = new Expr_Node($1, $2, $3); $$ = new_node;}
		;
		
UnaryExpr3	:	UnaryExpr4					{$$ = $1;}
		|	UnaryExpr3 OpManipulate3 UnaryExpr4		{Node* new_node = new Expr_Node($1, $2, $3); $$ = new_node;}
		;
		
UnaryExpr4	:	UnaryExpr5					{$$ = $1;}
		|	UnaryExpr4 OpManipulate4 UnaryExpr5		{Node* new_node = new Expr_Node($1, $2, $3); $$ = new_node;}
		;

UnaryExpr5	:	UnaryExpr6					{$$ = $1;}
		|	UnaryExpr5 OpManipulate5 UnaryExpr6		{Node* new_node = new Expr_Node($1, $2, $3); $$ = new_node;}
		;
		
UnaryExpr6	:	UnaryExpr7					{$$ = $1;}
		|	UnaryExpr6 OpManipulate6 UnaryExpr7		{Node* new_node = new Expr_Node($1, $2, $3); $$ = new_node;}
		;
		
UnaryExpr7	:	UnaryExpr8					{$$ = $1;}
		|	UnaryExpr7 OpManipulate7 UnaryExpr8		{Node* new_node = new Expr_Node($1, $2, $3); $$ = new_node;}
		;

UnaryExpr8	:	UnaryExpr8 OpManipulate8 PostFixExpr		{Node* new_node = new Expr_Node($1, $2, $3); $$ = new_node;}
		|	INC PostFixExpr					{$$ = $2;}	//temporary
		|	DEC PostFixExpr					{$$ = $2;}	//temporary
		|	SIZEOF PostFixExpr				{$$ = $2;}	//temporary
		|	SIZEOF LEFT Type RIGHT				{$$ = $$;}	//temporary
		|	OpUnary PostFixExpr				{if (strcmp($1,"SUB") == 0) { ($2)->is_negative = true; } $$=$2;}
		|	Cast PostFixExpr				{$$ = $2;}	//temporary
		|	PostFixExpr					{$$ = $1;}
		|	Call						{$$ = $1;}
		;

Cast		:	LEFT Type RIGHT
		;
		
PostFixExpr	:	PrimaryExpr					{$$ = $1;}
		|	PostFixExpr SQUARELEFT Expr SQUARERIGHT		{if (($1)->node_type == NODE_ID) {((ID_Node*)$1)->array_offset = $3;} $$ = $1;}
		|	PostFixExpr LEFT RIGHT				
		|	PostFixExpr LEFT Argument RIGHT
		|	PostFixExpr PERIOD IDENTIFIER
		|	PostFixExpr POINTER IDENTIFIER
		|	PostFixExpr INC
		|	PostFixExpr DEC
		;
		
PrimaryExpr	:	IDENTIFIER		{Node* new_node = new ID_Node($1); $$ = new_node;}
		|	Value			{$$ = $1;}
		|	LEFT Expr RIGHT		{$$ = $2;}
		;
		
		

		
ArrayDecl	:	SQUARELEFT INTCONST SQUARERIGHT		{$$ = $2;}
		;


		
Call		:	IDENTIFIER LEFT RIGHT			{ID_Node* id = new ID_Node($1); Node* new_call = new Call_Node(id, NULL); $$ = new_call;}
		|	IDENTIFIER LEFT Argument RIGHT		{ID_Node* id = new ID_Node($1); Node* new_call = new Call_Node(id, $3); $$ = new_call;}
		;
		

		
Argument	:	UnaryExpr COMMA Argument		{Node* a = new Argument_Node($1,$3); $$ = a;}
		|	UnaryExpr				{Node* a = new Argument_Node($1,NULL); $$ = a;}
		;

Value		:	INTCONST 		{Node* new_node = new IntConst_Node($1); $$ = new_node;}
		| 	FLOATCONST 		{Node* new_node = new FloatConst_Node($1); $$ = new_node;}
		| 	STRING			{Node* new_node = new String_Node($1); $$ = new_node;}
		;

CompoundType	:	Type CompoundType	{Type_Node* new_type = new Type_Node($1,$2); $$ = new_type; currentType = $$;}
		|	Type			{Type_Node* new_type = new Type_Node($1,NULL); $$ = new_type; currentType = $$; }
		;

Type		:	TYPEDEF|CONST| EXTERN|
			INT| CHAR| FLOAT| DOUBLE| LONG| SHORT| UNSIGNED| VOID| STATIC| REGISTER| AUTO| UNION| 
			ENUM| SIGNED| VOLATILE| STRUCT
		;

OpAssign	: 	ADDASSIGN	{Op_Node* new_node = new Op_Node($1,"+"); $$ = new_node;}
		| 	SUBASSIGN 	{Op_Node* new_node = new Op_Node($1,"-"); $$ = new_node;}
		| 	MULASSIGN 	{Op_Node* new_node = new Op_Node($1,"*"); $$ = new_node;}
		| 	DIVASSIGN 	{Op_Node* new_node = new Op_Node($1,"/"); $$ = new_node;}
		| 	MODASSIGN 	{Op_Node* new_node = new Op_Node($1,"%"); $$ = new_node;}
		| 	ANDASSIGN 	{Op_Node* new_node = new Op_Node($1,"&"); $$ = new_node;}
		| 	ORASSIGN 	{Op_Node* new_node = new Op_Node($1,"|"); $$ = new_node;}
		| 	XORASSIGN 	{Op_Node* new_node = new Op_Node($1,"^"); $$ = new_node;}
		| 	SHIFTLASSIGN 	{Op_Node* new_node = new Op_Node($1,"<<"); $$ = new_node;}
		| 	SHIFTRASSIGN  	{Op_Node* new_node = new Op_Node($1,">>"); $$ = new_node;}
		| 	EQ		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		;

		

OpManipulate	:	LOGICOR 	{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		;

OpManipulate2	:	LOGICAND 	{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		;
		
OpManipulate3	:	BWOR 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		;
		
OpManipulate4	:	XOR 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		;
		
OpManipulate5	:	BWAND 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		;
		
OpManipulate6	:	SHIFTL 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	SHIFTR		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		;

OpManipulate7	:	ADD 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	SUB 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		;

OpManipulate8	: 	MUL 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	DIV 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	MOD 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		;
		

		

		
OpUnary		:	BWNOT		//~
		|	LOGICNOT	//!
		|	ADD	
		|	SUB	{strcpy($$,"SUB");}
		|	BWAND	//&
		|	MUL
		;
		
OpCond		:	COMP	{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	NOTEQ	{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		|	LTEQ	{Op_Node* new_node = new Op_Node($1); $$ = new_node;}	
		| 	GTEQ	{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	GT	{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	LT	{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		;
		

		


/*
Operator	: 	ADD| SUB| MUL| DIV| MOD| LEFT| RIGHT| EQ| COMP| NOTEQ| LTEQ| GTEQ| GT| LT| SQUARELEFT| SQUARERIGHT|
			SCOPELEFT| SCOPERIGHT| SEMI| COLON| COMMA| INC| DEC| QUES| BWNOT| LOGICNOT| BWAND| LOGICAND| BWOR| LOGICOR| XOR| SIZEOF|
			SHIFTL| SHIFTR | ADDASSIGN | SUBASSIGN | MULASSIGN | DIVASSIGN |MODASSIGN |ANDASSIGN |ORASSIGN |XORASSIGN |SHIFTLASSIGN |SHIFTRASSIGN |
			POINTER
		;
*/



%%

void indent(int n) {
	if (n<=0) return;
	for(int i=0;i<n;i++){cout<<"    ";}
}

int yyerror(const char* s){ 
    indent(n);
    cout << s << endl;
    return -1;
}


int main(int argc, char* argv[]) {
	yyparse();
	
	root->file_name = argv[0];
	
	Environment env;
	
	env.global_variable_count = global_variable_count;
	
	root->renderASM(env, cout);
	
/*
	//Debugging symbol table:
	
	cout << "symbol table:" << endl;
	typedef map<string, int>::iterator it_type;
	for(it_type iterator = env.symbol_table.begin(); iterator != env.symbol_table.end(); iterator++) {
	    // iterator->first = key
	    // iterator->second = value
	    cout << iterator->first << ": " << iterator->second << endl;
	}
	cout << "-------------" << endl;
*/
	
	return 0;

}
