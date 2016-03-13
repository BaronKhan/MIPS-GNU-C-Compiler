%option noyywrap

%{
#include "c_parser.tab.hpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


struct token{
	int tokClass;
	string tokType;
	string tokRaw;
	int line_num;
	int string_count;
	string srcFile;
	int srcLine;
};

int line_num = 1;

string tokType;
int tokClass;
int string_count = 0;

string srcFile = "";
int srcLine = 1;
istringstream linemarker;
bool pre_processed = false;

/*
enum {
	CONSTANT=256,
	IDENTIFIER,
	KEYWORD,
	OPERATOR,
	STRINGLITERAL,
	INVALID,
	NEW_LINE,
	COMMENT,
	PREPROC,
	NEWLINE,
	LINEMARKER,
	SPACE,
	
	
	INTCONST=300,
	FLOATCONST,
	FOR, IF, ELSE, TYPEDEF, WHILE, DO, RETURN, CONST, EXTERN, CONTINUE, DEFAULT, GOTO, SWITCH, 
	INT, CHAR, FLOAT, DOUBLE, LONG, SHORT, UNSIGNED, VOID, STATIC, REGISTER, BREAK, AUTO, UNION, 
	ENUM, SIGNED, CASE, VOLATILE, STRUCT, SIZEOF,
	
	ADD, SUB, MUL, DIV, MOD, LEFT, RIGHT, EQ, COMP, NOTEQ, LTEQ, GTEQ, GT, LT, SQUARELEFT, SQUARERIGHT,
	SCOPELEFT, SCOPERIGHT, SEMI, COLON, COMMA, INC, DEC, QUES, BWNOT, LOGICNOT ,BWAND ,LOGICAND ,BWOR ,LOGICOR ,XOR,
	SHIFTL, SHIFTR,

	ADDASSIGN ,SUBASSIGN ,MULASSIGN ,DIVASSIGN ,MODASSIGN ,ANDASSIGN ,ORASSIGN, XORASSIGN ,SHIFTLASSIGN ,SHIFTRASSIGN,
	
	POINTER
};
*/

%}

TDigit	[0-9]
TChar	[a-zA-Z]
TAdd	[+]
TSub	[-]
TMul	[*]
TDiv	[/]
TMod	[%]
TLeft	[(]
TRight	[)]
TQuote	["]
TEq		[=]
TLT		[<]
TGT		[>]
TSemi	[;]
TColon	[:]
TComma	[,]
TPeriod	[.]
TBLeft	[{]
TBRight	[}]
TSLeft	[\[]
TSRight	[\]]
TExclam	[!]
TAmp	[&]
TOR		[|]
TXOR	[\^]
TQues	[?]
TTilde	[~]
TApost	[']


%%

"//"([^\n])+"\n"		{string s=yytext; line_num+=count(s.begin(), s.end(), '\n'); }
"/*"[^"*/"]*"*/"	{string s=yytext; line_num+=count(s.begin(), s.end(), '\n'); }

{TQuote}(\\.|[^"])*{TQuote}		{string_count++; /*tokType=yytext;*/ tokType = "TString"; tokClass = STRINGLITERAL; return STRING;}
{TApost}[\\]?[^']{TApost}		{tokType = "TChar"; tokClass = STRINGLITERAL; yylval.str = strdup(yytext); return STRING;}
{TApost}([\\]?[^'][^']+)?{TApost}	{tokClass = INVALID; return INVALID;}

[#]+[ ]*{TDigit}+[ ]*{TQuote}[^"]*{TQuote}([ ]*{TDigit})*	{
																if(!pre_processed) {
																	pre_processed = true;
																}
																linemarker.str(string());
																linemarker.str(yytext);
																string text = yytext;
																string hash;
																linemarker >> hash >> srcLine;
																srcLine--;
																//extract srcFile
																srcFile = text.substr(text.find(" \"")+1, text.find("\" ")-text.find(" \"")+1);
															}

[#]+[ ]*("include"|"define"|"pragma")[ ]*(.)*"\n"	{line_num++;}

(0x[0-9a-fA-F]+)|({TDigit}+)			{/*tokType=yytext;*/ tokType = "TInt"; tokClass = CONSTANT; yylval.num = atoi(strdup(yytext)); return INTCONST;}
{TDigit}+[.]?{TDigit}*([eE][+-]?{TDigit}+)?[flFL]?|{TDigit}*[.]{TDigit}+([eE][+-]?{TDigit}+)?[flFL]? 	{/*tokType=yytext;*/ tokType = "TFloat"; tokClass = CONSTANT; yylval.fp = atof(strdup(yytext)); return FLOATCONST;}


"for"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return FOR; }
"if"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return IF; }
"else"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return ELSE; }
"typedef"						{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return TYPEDEF; }
"while"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return WHILE; }
"do"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return DO; }
"return"						{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return RETURN; }
"const"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return CONST; }
"extern"						{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return EXTERN; }
"continue"						{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return CONTINUE; }
"default"						{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return DEFAULT; }
"goto"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return GOTO; }
"switch"						{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return SWITCH; }
"int"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return INT; }
"char"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return CHAR; }
"float"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return FLOAT; }
"double"						{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return DOUBLE; }
"long"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return LONG; }
"short"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return SHORT; }
"unsigned"						{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return UNSIGNED; }
"void"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return VOID; }
"static"						{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return STATIC; }
"register"						{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return REGISTER; }
"break"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return BREAK; }
"auto"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return AUTO; }
"union"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return UNION; }

"enum"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return ENUM; }
"signed"						{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return SIGNED; }
"case"							{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return CASE; }
"volatile"						{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return VOLATILE; }
"struct"						{ tokType=yytext; tokClass = KEYWORD; yylval.str = strdup(yytext); return STRUCT; }

"sizeof"				{tokType="Tsizeof"; tokClass = OPERATOR; return SIZEOF; }


({TChar}|_)+({TDigit}|{TChar}|_)*	{tokType=yytext; yylval.str = strdup(yytext); tokClass = IDENTIFIER; return IDENTIFIER; }

{TAdd}					{tokType="TAdd";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return ADD;} 
{TSub}					{tokType="TSub"; 	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return SUB;}
{TMul}					{tokType="TMul";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return MUL;} 
{TDiv}					{tokType="TDiv";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return DIV;}
{TMod}					{tokType="TMod";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return MOD;}
{TLeft}					{tokType="TLeft";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return LEFT;}
{TRight}				{tokType="TRight"; 	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return RIGHT;}
{TEq}					{tokType="TEq";		tokClass = OPERATOR;	yylval.str = strdup(yytext);	return EQ;}
{TEq}{TEq}				{tokType="TComp";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return COMP;}
{TExclam}{TEq}				{tokType="TNotEq";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return NOTEQ;}
{TLT}{TEq}				{tokType="TLTEq";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return LTEQ;}
{TGT}{TEq}				{tokType="TGTEq";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return GTEQ;}
{TGT}					{tokType="TGT";		tokClass = OPERATOR;	yylval.str = strdup(yytext);	return GT;}
{TLT}					{tokType="TLT";		tokClass = OPERATOR;	yylval.str = strdup(yytext);	return LT;}
{TSLeft}				{tokType="TSquareLeft"; 	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return SQUARELEFT;}
{TSRight}				{tokType="TSquareRight"; 	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return SQUARERIGHT;}
{TBLeft}				{tokType="TScopeLeft"; 		tokClass = OPERATOR;	yylval.str = strdup(yytext);	return SCOPELEFT;}
{TBRight}				{tokType="TScopeRight"; 	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return SCOPERIGHT;}
{TSemi}					{tokType="TSemi"; 	tokClass = OPERATOR;		yylval.str = strdup(yytext);return SEMI;}
{TColon}				{tokType="TColon"; 	tokClass = OPERATOR;		yylval.str = strdup(yytext);return COLON;}
{TComma}				{tokType="TComma"; 	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return COMMA;}
{TPeriod}				{tokType="TPeriod"; 	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return PERIOD;}
{TAdd}{TAdd}			{tokType="TInc"; 	tokClass = OPERATOR;		yylval.str = strdup(yytext);return INC;}
{TSub}{TSub}			{tokType="TDec"; 	tokClass = OPERATOR;		yylval.str = strdup(yytext);return DEC;}
{TQues}					{tokType="TQues";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return QUES;}

{TTilde}				{tokType="TBWNOT";	tokClass = OPERATOR;		yylval.str = strdup(yytext); return BWNOT;}
{TExclam}				{tokType="TLogicNOT";	tokClass = OPERATOR;		yylval.str = strdup(yytext); return LOGICNOT;}
{TAmp}					{tokType="TBWAND";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return BWAND;}
{TAmp}{TAmp}			{tokType="TLogicAND";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return LOGICAND;}
{TOR}					{tokType="TBWOR";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return BWOR;}
{TOR}{TOR}				{tokType="TLogicOR";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return LOGICOR;}
{TXOR}					{tokType="TXOR";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return XOR;}

{TLT}{TLT}				{tokType="TShiftL";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return SHIFTL;}
{TGT}{TGT}				{tokType="TShiftR";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return SHIFTR;}

{TAdd}{TEq}				{tokType="TAddAssign";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return ADDASSIGN;}
{TSub}{TEq}				{tokType="TSubAssign";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return SUBASSIGN;}
{TMul}{TEq}				{tokType="TMulAssign";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return MULASSIGN;}
{TDiv}{TEq}				{tokType="TDivAssign";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return DIVASSIGN;}
{TMod}{TEq}				{tokType="TModAssign";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return MODASSIGN;}
{TAmp}{TEq}				{tokType="TANDAssign";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return ANDASSIGN;}
{TOR}{TEq}				{tokType="TORAssign";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return ORASSIGN;}
{TXOR}{TEq}				{tokType="TXORAssign";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return XORASSIGN;}
{TLT}{TLT}{TEq}				{tokType="TShiftLAssign";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return SHIFTLASSIGN;}
{TGT}{TGT}{TEq}				{tokType="TShiftRAssign";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return SHIFTRASSIGN;}

{TSub}{TGT}				{tokType="TPointer";	tokClass = OPERATOR;	yylval.str = strdup(yytext);	return POINTER;}



"\n"					{line_num++; if(pre_processed){srcLine++;}}
" "|"\t"				{/*ignore spaces and tabs*/}


.					{tokClass = INVALID; return INVALID;}


%%

/*

int main()
{
	vector<token> tokens;
	int lexcode = yylex();
	while(lexcode != 0){
		if(tokClass == CONSTANT || tokClass == IDENTIFIER || tokClass == KEYWORD || tokClass == STRINGLITERAL
		|| tokClass == OPERATOR || tokClass == INVALID) {
			token currentToken;
			currentToken.tokClass = tokClass;
			currentToken.tokType = tokType;
			currentToken.tokRaw = yytext;
			currentToken.line_num = line_num;
			currentToken.string_count = string_count;
			if (pre_processed) {
				currentToken.srcFile = srcFile;
				currentToken.srcLine = srcLine;
			}
			tokens.push_back(currentToken);
		}
		lexcode = yylex();
	}


	for (int i=0;i<tokens.size();i++) {
		if(tokens[i].tokClass == CONSTANT){
			if (!pre_processed) {
				cout << tokens[i].tokRaw << " Constant " << tokens[i].tokType << " " << tokens[i].line_num << endl;
			}
			else {
				cout << tokens[i].tokRaw << " Constant " << tokens[i].tokType << " " << tokens[i].line_num << " " << tokens[i].srcFile << " " << tokens[i].srcLine << endl;
			}
		}
		else if(tokens[i].tokClass == IDENTIFIER){
			if (!pre_processed) {
				//cout << tokens[i].tokRaw << " Identifier T_" << tokens[i].tokType << " " << tokens[i].line_num << endl;
				cout << tokens[i].tokRaw << " Identifier TIdentifier " << tokens[i].line_num << endl;
			}
			else {
				//cout << tokens[i].tokRaw << " Identifier T_" << tokens[i].tokType << " " << tokens[i].line_num << " " << tokens[i].srcFile << " " << tokens[i].srcLine << endl;
				cout << tokens[i].tokRaw << " Identifier TIdentifier " << tokens[i].line_num << " " << tokens[i].srcFile << " " << tokens[i].srcLine << endl;
			}

		}
		else if(tokens[i].tokClass == KEYWORD){
			if (!pre_processed) {
				cout << tokens[i].tokRaw << " Keyword T" << tokens[i].tokType << " " << tokens[i].line_num << endl;
			}
			else {
				cout << tokens[i].tokRaw << " Keyword T" << tokens[i].tokType << " " << tokens[i].line_num << " " << tokens[i].srcFile << " " << tokens[i].srcLine << endl;
			}
		}
		else if (tokens[i].tokClass == STRINGLITERAL){
			if (!pre_processed) {
				//cout << tokens[i].tokRaw << " StringLiteral TString_" << string_count << " " << tokens[i].line_num << endl;
				cout << tokens[i].tokRaw << " StringLiteral " << tokens[i].tokType << " " << tokens[i].line_num << endl;
			}
			else {
				//cout << tokens[i].tokRaw << " StringLiteral TString_" << string_count << " " << tokens[i].line_num << " " << tokens[i].srcFile << " " << tokens[i].srcLine << endl;
				cout << tokens[i].tokRaw << " StringLiteral " << tokens[i].tokType << " " << tokens[i].line_num << " " << tokens[i].srcFile << " " << tokens[i].srcLine << endl;
			}
		}
		else if (tokens[i].tokClass == OPERATOR){
			if (!pre_processed) {
				cout << tokens[i].tokRaw << " Operator " << tokens[i].tokType << " " << tokens[i].line_num << endl;
			}
			else {
				cout << tokens[i].tokRaw << " Operator " << tokens[i].tokType << " " << tokens[i].line_num << " " << tokens[i].srcFile << " " << tokens[i].srcLine << endl;
			}
		}
		else if (tokens[i].tokClass == INVALID){
			if (!pre_processed) {
				cout << tokens[i].tokRaw << " Invalid TInvalid " << tokens[i].line_num << endl;
			}
			else {
				cout << tokens[i].tokRaw << " Invalid TInvalid " << tokens[i].line_num << " " << tokens[i].srcFile << " " << tokens[i].srcLine << endl;
			}
		}
	}


    
    
    return 0;
}


*/
