%{
#include <iostream>
#include <cstdlib>

using namespace std;

int yylex();
int yyerror(const char* s);
void indent(int n);

int n = 0;
%}

%union{
	int num;
	double fp;
	char* str;
}

%token	CONSTANT
%token	KEYWORD
%token	OPERATOR
%token	STRINGLITERAL

%token 	INTCONST
%token 	FLOATCONST
%token 	STRING
%token	IDENTIFIER
%token	INVALID

%token 	FOR IF ELSE TYPEDEF WHILE DO RETURN CONST EXTERN CONTINUE DEFAULT GOTO SWITCH 
%token 	INT CHAR FLOAT DOUBLE LONG SHORT UNSIGNED VOID STATIC REGISTER BREAK AUTO UNION 
%token 	ENUM SIGNED CASE VOLATILE STRUCT

%token 	ADD SUB MUL DIV MOD LEFT RIGHT EQ COMP NOTEQ LTEQ GTEQ GT LT SQUARELEFT SQUARERIGHT
%token 	SCOPELEFT SCOPERIGHT SEMI COLON COMMA INC DEC QUES BWNOT LOGICNOT BWAND LOGICAND BWOR LOGICOR XOR SIZEOF
%token 	SHIFTL SHIFTR

%token	ADDASSIGN SUBASSIGN MULASSIGN DIVASSIGN MODASSIGN ANDASSIGN ORASSIGN XORASSIGN SHIFTLASSIGN SHIFTRASSIGN

/* Non-terminals:
%type File Function Parameter Block Statement ExprStatement CompoundStatement IfStatement WhileStatement ElseStatement ForStatement
%type Operator Const CompoundType Type Assignment Declaration Call Value Argument ReturnStatement StartScope EndScope
*/

%type<str> IDENTIFIER

%start File

%%

File		: 	Statement File
		|	Function File
		|	Block File
		| 	Statement
		|	Function
		|	Block
		;

Block		:	StartScope CompoundStatement EndScope
		|	StartScope EndScope
		;
		
StartScope	:	SCOPELEFT	{indent(n); cout << "SCOPE" << endl; n++;}
		;
		
EndScope	:	SCOPERIGHT	{n--;}
		;

Function	:	CompoundType IDENTIFIER LEFT {indent(n); cout << "FUNCTION : " << $2 << endl;} Parameter RIGHT Block
		|	CompoundType IDENTIFIER LEFT {indent(n); cout << "FUNCTION : " << $2 << endl;} RIGHT Block		
		;

Parameter	:	CompoundType IDENTIFIER {indent(n); cout << "    PARAMETER : " << $2 << endl;} COMMA Parameter
		|	CompoundType IDENTIFIER	{indent(n); cout << "    PARAMETER : " << $2 << endl;}		
		;

CompoundStatement:	Block CompoundStatement
		|	Statement CompoundStatement
		|	Statement
		;

Statement	:	ExprStatement
		|	IfStatement
		|	WhileStatement
		|	ForStatement
		|	ReturnStatement
		;

ExprStatement	:	Expr SEMI
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
		
		
ReturnStatement	:	RETURN Expr SEMI
		|	RETURN Value SEMI
		|	RETURN SEMI
		|	RETURN IDENTIFIER SEMI
		;
		

Expr		:	CompoundType Declaration
		|	Assignment
		|	Call
		;

Declaration	:	IDENTIFIER COMMA Declaration		{indent(n); cout << "VARIABLE : " << $1 << endl;}
		|	IDENTIFIER EQ Value COMMA Declaration	{indent(n); cout << "VARIABLE : " << $1 << endl;}
		|	IDENTIFIER EQ Value			{indent(n); cout << "VARIABLE : " << $1 << endl;}
		|	IDENTIFIER EQ Call			{indent(n); cout << "VARIABLE : " << $1 << endl;}
		|	IDENTIFIER				{indent(n); cout << "VARIABLE : " << $1 << endl;}
		;
		

Assignment	:	IDENTIFIER Operator Function		
		|	IDENTIFIER Operator IDENTIFIER
		|	IDENTIFIER Operator Value
		|	IDENTIFIER INC
		|	IDENTIFIER DEC
		;
		
Call		:	IDENTIFIER LEFT RIGHT
		|	IDENTIFIER LEFT Argument RIGHT
		;
		

		
Argument	:	IDENTIFIER COMMA Argument
		|	IDENTIFIER
		|	Value COMMA Argument
		|	Value
		;

Value		:	INTCONST | FLOATCONST | STRING
		;

CompoundType	:	Type CompoundType
		|	Type
		;

Type		:	TYPEDEF|CONST| EXTERN|
			INT| CHAR| FLOAT| DOUBLE| LONG| SHORT| UNSIGNED| VOID| STATIC| REGISTER| AUTO| UNION| 
			ENUM| SIGNED| VOLATILE| STRUCT
		;

Operator	: 	ADD| SUB| MUL| DIV| MOD| LEFT| RIGHT| EQ| COMP| NOTEQ| LTEQ| GTEQ| GT| LT| SQUARELEFT| SQUARERIGHT|
			SCOPELEFT| SCOPERIGHT| SEMI| COLON| COMMA| INC| DEC| QUES| BWNOT| LOGICNOT| BWAND| LOGICAND| BWOR| LOGICOR| XOR| SIZEOF|
			SHIFTL| SHIFTR | ADDASSIGN | SUBASSIGN | MULASSIGN | DIVASSIGN |MODASSIGN |ANDASSIGN |ORASSIGN |XORASSIGN |SHIFTLASSIGN |SHIFTRASSIGN
		;


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

int main() {
	yyparse();
}