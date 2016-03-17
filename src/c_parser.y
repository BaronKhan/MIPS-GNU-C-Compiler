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
%type<num> 	INTCONST
%type<fp>	FLOATCONST


%type<NodePtr>	File Block Function Statement Expr PrimaryExpr Declaration
%type<NodePtr>	Assignment Value UnaryExpr UnaryExpr2 PostFixExpr
%type<NodePtr>	ExprStatement ReturnStatement 
%type<NodePtr> 	DeclStatement CompoundStatement CompoundStatement2

%type<Op_NodePtr>	OpAssign OpManipulate OpManipulate2

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


File		: 	DeclStatement File	{root->file_list.push_back($1);}
		|	Function File		{root->file_list.push_back($1);}
		| 	DeclStatement		{root->file_list.push_back($1);}
		|	Function		{root->file_list.push_back($1);}
		;
		
Function	:	CompoundType IDENTIFIER LEFT Parameter RIGHT Block	{ID_Node* id = new ID_Node($2); Function_Node* func = new Function_Node(id,$4,$6,variable_count); $$ = func; variable_count = 0;}
		|	CompoundType IDENTIFIER LEFT RIGHT Block		{ID_Node* id = new ID_Node($2); Function_Node* func = new Function_Node(id,NULL,$5,variable_count); $$ = func; variable_count = 0;}
		;

Block		:	StartScope CompoundStatement EndScope	{Block_Node* block = new Block_Node($2); $$ = block;}
		|	StartScope EndScope			{Block_Node* block = new Block_Node(NULL); $$ = block;}
		;
		
StartScope	:	SCOPELEFT	
		;
		
EndScope	:	SCOPERIGHT	
		;


Parameter	:	CompoundType IDENTIFIER COMMA Parameter	{ID_Node* id = new ID_Node($2); Parameter_Node* p = new Parameter_Node($1,id,$4); $$ = p;}
		|	CompoundType IDENTIFIER			{ID_Node* id = new ID_Node($2); Parameter_Node* p = new Parameter_Node($1,id,NULL); $$ = p;}
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
		
DeclStatement	:	CompoundType {currentType = $1;} Declaration SEMI		{Node* declStatement = new DeclStatement_Node($1, $3, false); $$ = declStatement;}
		|	CompoundType {currentType = $1;} MUL Declaration SEMI		{Node* declStatement = new DeclStatement_Node($1, $4, true); $$ = declStatement;}
		;

Declaration	:	IDENTIFIER COMMA Declaration			{ID_Node* id = new ID_Node($1); Node* decl = new Decl_Node(currentType, id, false, NULL, $3); $$ = decl; variable_count++;}
		|	IDENTIFIER ArrayDecl COMMA Declaration	
		|	IDENTIFIER EQ Expr				{ID_Node* id = new ID_Node($1); Node* decl = new Decl_Node(currentType, id, true, $3, NULL); $$ = decl; variable_count++;}
		|	IDENTIFIER EQ Expr COMMA Declaration		{ID_Node* id = new ID_Node($1); Node* decl = new Decl_Node(currentType, id, true, $3, $5); $$ = decl; variable_count++;}
		|	IDENTIFIER					{ID_Node* id = new ID_Node($1); Node* decl = new Decl_Node(currentType, id, false, NULL, NULL); $$ = decl; variable_count++;}
		|	IDENTIFIER ArrayDecl			
		;


Statement	:	ExprStatement				{Node* new_statement = new Statement_Node($1); $$ = new_statement;}
		|	IfStatement
		|	WhileStatement
		|	ForStatement
		|	ReturnStatement				{Node* new_statement = new Statement_Node($1); $$ = new_statement;}
		;

ExprStatement	:	Expr SEMI				{Node* new_expr_statement = new ExprStatement_Node($1); $$ = new_expr_statement;}
		;


IfStatement	:	IF LEFT Expr RIGHT Statement
		|	IF LEFT Expr RIGHT Block
		|	IF LEFT Expr RIGHT Statement ElseStatement
		|	IF LEFT Expr RIGHT Block ElseStatement
		;

ElseStatement	:	ELSE Statement
		|	ELSE Block
		;
		
WhileStatement	:	WHILE LEFT Expr RIGHT Statement
		|	WHILE LEFT Expr RIGHT Block
		;
		
ForStatement	:	FOR LEFT ExprStatement ExprStatement Expr RIGHT Statement
		|	FOR LEFT ExprStatement ExprStatement Expr RIGHT Block
		;
		
		
ReturnStatement	:	RETURN Expr SEMI		{Node* new_return_statement = new ReturnStatement_Node($2); $$ = new_return_statement;}
		|	RETURN SEMI			{Node* new_return_statement = new ReturnStatement_Node(NULL); $$ = new_return_statement;}
		;
		

Expr		:	Expr COMMA Assignment
		|	Assignment					{$$ = $1;}
		|	Call
		;

Assignment	:	Assignment OpAssign UnaryExpr			{Node* new_node = new Assignment_Node($1, $2, $3); $$ = new_node;}
		|	Assignment OpAssign ConditionalExpr
		|	ConditionalExpr
		|	UnaryExpr					{$$ = $1;}
		;
		
ConditionalExpr	:	UnaryExpr OpCond UnaryExpr
		|	UnaryExpr QUES UnaryExpr COLON UnaryExpr
		;

UnaryExpr	:	UnaryExpr2					{$$ = $1;}
		|	UnaryExpr OpManipulate UnaryExpr2		{Node* new_node = new Expr_Node($1, $2, $3); $$ = new_node;}
		;


UnaryExpr2	:	UnaryExpr2 OpManipulate2 PostFixExpr		{Node* new_node = new Expr_Node($1, $2, $3); $$ = new_node;}
		|	INC PostFixExpr
		|	DEC PostFixExpr
		|	SIZEOF PostFixExpr
		|	SIZEOF LEFT Type RIGHT
		|	OpUnary PostFixExpr				{if (strcmp($1,"SUB") == 0) { ($2)->is_negative = true; } $$=$2;}
		|	Cast PostFixExpr
		|	PostFixExpr					{$$ = $1;}
		;

Cast		:	LEFT Type RIGHT
		;
		
PostFixExpr	:	PrimaryExpr					{$$ = $1;}
		|	PostFixExpr SQUARELEFT Expr SQUARERIGHT
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
		
		

		
ArrayDecl	:	SQUARELEFT INTCONST SQUARERIGHT
		;


		
Call		:	IDENTIFIER LEFT RIGHT
		|	IDENTIFIER LEFT Argument RIGHT
		;
		

		
Argument	:	IDENTIFIER COMMA Argument
		|	IDENTIFIER
		|	Value COMMA Argument
		|	Value
		;

Value		:	INTCONST 		{Node* new_node = new IntConst_Node($1); $$ = new_node;}
		| 	FLOATCONST 
		| 	STRING
		;

CompoundType	:	Type CompoundType	{Type_Node* new_type = new Type_Node($1,$2); $$ = new_type;}
		|	Type			{Type_Node* new_type = new Type_Node($1,NULL); $$ = new_type;}
		;

Type		:	TYPEDEF|CONST| EXTERN|
			INT| CHAR| FLOAT| DOUBLE| LONG| SHORT| UNSIGNED| VOID| STATIC| REGISTER| AUTO| UNION| 
			ENUM| SIGNED| VOLATILE| STRUCT
		;

OpAssign	: 	ADDASSIGN {Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	SUBASSIGN {Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	MULASSIGN {Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	DIVASSIGN {Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	MODASSIGN {Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	ANDASSIGN {Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	ORASSIGN {Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	XORASSIGN {Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	SHIFTLASSIGN {Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	SHIFTRASSIGN  {Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	EQ {Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		;


OpManipulate	:	ADD 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	SUB 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		;


OpManipulate2	: 	MUL 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	DIV 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	MOD 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	BWNOT 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	LOGICNOT 	{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	BWAND 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	LOGICAND 	{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	BWOR 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	LOGICOR 	{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	XOR		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	SHIFTL 		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		| 	SHIFTR		{Op_Node* new_node = new Op_Node($1); $$ = new_node;}
		;
		

		

		
OpUnary		:	BWNOT		//~
		|	LOGICNOT	//!
		|	ADD	
		|	SUB	{strcpy($$,"SUB");}
		|	BWAND	//&
		|	MUL
		;
		
OpCond		:	COMP| NOTEQ| LTEQ| GTEQ| GT| LT
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
