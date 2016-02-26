%option noyywrap

%{
#include "c_parser.tab.h"

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

	ADDASSIGN ,SUBASSIGN ,MULASSIGN ,DIVASSIGN ,MODASSIGN ,ANDASSIGN ,ORASSIGN, XORASSIGN ,SHIFTLASSIGN ,SHIFTRASSIGN
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
{TApost}[\\]?[^']{TApost}		{tokType = "TChar"; tokClass = STRINGLITERAL; return STRING;}
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

(0x)?{TDigit}+			{/*tokType=yytext;*/ tokType = "TInt"; tokClass = CONSTANT; return INTCONST;}
{TDigit}+[.]?{TDigit}*([eE][+-]?{TDigit}+)?[flFL]?|{TDigit}*[.]{TDigit}+([eE][+-]?{TDigit}+)?[flFL]? 	{/*tokType=yytext;*/ tokType = "TFloat"; tokClass = CONSTANT; return FLOATCONST;}


"for"							{ tokType=yytext; tokClass = KEYWORD; return FOR; }
"if"							{ tokType=yytext; tokClass = KEYWORD; return IF; }
"else"							{ tokType=yytext; tokClass = KEYWORD; return ELSE; }
"typedef"						{ tokType=yytext; tokClass = KEYWORD; return TYPEDEF; }
"while"							{ tokType=yytext; tokClass = KEYWORD; return WHILE; }
"do"							{ tokType=yytext; tokClass = KEYWORD; return DO; }
"return"						{ tokType=yytext; tokClass = KEYWORD; return RETURN; }
"const"							{ tokType=yytext; tokClass = KEYWORD; return CONST; }
"extern"						{ tokType=yytext; tokClass = KEYWORD; return EXTERN; }
"continue"						{ tokType=yytext; tokClass = KEYWORD; return CONTINUE; }
"default"						{ tokType=yytext; tokClass = KEYWORD; return DEFAULT; }
"goto"							{ tokType=yytext; tokClass = KEYWORD; return GOTO; }
"switch"						{ tokType=yytext; tokClass = KEYWORD; return SWITCH; }
"int"							{ tokType=yytext; tokClass = KEYWORD; return INT; }
"char"							{ tokType=yytext; tokClass = KEYWORD; return CHAR; }
"float"							{ tokType=yytext; tokClass = KEYWORD; return FLOAT; }
"double"						{ tokType=yytext; tokClass = KEYWORD; return DOUBLE; }
"long"							{ tokType=yytext; tokClass = KEYWORD; return LONG; }
"short"							{ tokType=yytext; tokClass = KEYWORD; return SHORT; }
"unsigned"						{ tokType=yytext; tokClass = KEYWORD; return UNSIGNED; }
"void"							{ tokType=yytext; tokClass = KEYWORD; return VOID; }
"static"						{ tokType=yytext; tokClass = KEYWORD; return STATIC; }
"register"						{ tokType=yytext; tokClass = KEYWORD; return REGISTER; }
"break"							{ tokType=yytext; tokClass = KEYWORD; return BREAK; }
"auto"							{ tokType=yytext; tokClass = KEYWORD; return AUTO; }
"union"							{ tokType=yytext; tokClass = KEYWORD; return UNION; }

"enum"							{ tokType=yytext; tokClass = KEYWORD; return ENUM; }
"signed"						{ tokType=yytext; tokClass = KEYWORD; return SIGNED; }
"case"							{ tokType=yytext; tokClass = KEYWORD; return CASE; }
"volatile"						{ tokType=yytext; tokClass = KEYWORD; return VOLATILE; }
"struct"						{ tokType=yytext; tokClass = KEYWORD; return STRUCT; }

"sizeof"				{tokType="Tsizeof"; tokClass = OPERATOR; return SIZEOF; }


({TChar}|_)+({TDigit}|{TChar}|_)*	{tokType=yytext; yylval.str = strdup(yytext); tokClass = IDENTIFIER; return IDENTIFIER; }

{TAdd}					{tokType="TAdd";	tokClass = OPERATOR;	return ADD;} 
{TSub}					{tokType="TSub";	tokClass = OPERATOR;	return SUB;}
{TMul}					{tokType="TMul";	tokClass = OPERATOR;	return MUL;} 
{TDiv}					{tokType="TDiv";	tokClass = OPERATOR;	return DIV;}
{TMod}					{tokType="TMod";	tokClass = OPERATOR;	return MOD;}
{TLeft}					{tokType="TLeft";	tokClass = OPERATOR;	return LEFT;}
{TRight}				{tokType="TRight"; 	tokClass = OPERATOR;	return RIGHT;}
{TEq}					{tokType="TEq";		tokClass = OPERATOR;	return EQ;}
{TEq}{TEq}				{tokType="TComp";	tokClass = OPERATOR;	return COMP;}
{TExclam}{TEq}			{tokType="TNotEq";	tokClass = OPERATOR;	return NOTEQ;}
{TLT}{TEq}				{tokType="TLTEq";	tokClass = OPERATOR;	return LTEQ;}
{TGT}{TEq}				{tokType="TGTEq";	tokClass = OPERATOR;	return GTEQ;}
{TGT}					{tokType="TGT";		tokClass = OPERATOR;	return GT;}
{TLT}					{tokType="TLT";		tokClass = OPERATOR;	return LT;}
{TSLeft}				{tokType="TSquareLeft"; 	tokClass = OPERATOR;	return SQUARELEFT;}
{TSRight}				{tokType="TSquareRight"; 	tokClass = OPERATOR;	return SQUARERIGHT;}
{TBLeft}				{tokType="TScopeLeft"; 		tokClass = OPERATOR;	return SCOPELEFT;}
{TBRight}				{tokType="TScopeRight"; 	tokClass = OPERATOR;	return SCOPERIGHT;}
{TSemi}					{tokType="TSemi"; 	tokClass = OPERATOR;	return SEMI;}
{TColon}				{tokType="TColon"; 	tokClass = OPERATOR;	return COLON;}
{TComma}				{tokType="TComma"; 	tokClass = OPERATOR;	return COMMA;}
{TPeriod}				{tokType="TPeriod"; 	tokClass = OPERATOR;	return PERIOD;}
{TAdd}{TAdd}			{tokType="TInc"; 	tokClass = OPERATOR;	return INC;}
{TSub}{TSub}			{tokType="TDec"; 	tokClass = OPERATOR;	return DEC;}
{TQues}					{tokType="TQues";	tokClass = OPERATOR;	return QUES;}

{TTilde}				{tokType="TBWNOT";	tokClass = OPERATOR;	return BWNOT;}
{TExclam}				{tokType="TLogicNOT";	tokClass = OPERATOR;	return LOGICNOT;}
{TAmp}					{tokType="TBWAND";	tokClass = OPERATOR;	return BWAND;}
{TAmp}{TAmp}			{tokType="TLogicAND";	tokClass = OPERATOR;	return LOGICAND;}
{TOR}					{tokType="TBWOR";	tokClass = OPERATOR;	return BWOR;}
{TOR}{TOR}				{tokType="TLogicOR";	tokClass = OPERATOR;	return LOGICOR;}
{TXOR}					{tokType="TXOR";	tokClass = OPERATOR;	return XOR;}

{TLT}{TLT}				{tokType="TShiftL";	tokClass = OPERATOR;	return SHIFTL;}
{TGT}{TGT}				{tokType="TShiftR";	tokClass = OPERATOR;	return SHIFTR;}

{TAdd}{TEq}				{tokType="TAddAssign";	tokClass = OPERATOR;	return ADDASSIGN;}
{TSub}{TEq}				{tokType="TSubAssign";	tokClass = OPERATOR;	return SUBASSIGN;}
{TMul}{TEq}				{tokType="TMulAssign";	tokClass = OPERATOR;	return MULASSIGN;}
{TDiv}{TEq}				{tokType="TDivAssign";	tokClass = OPERATOR;	return DIVASSIGN;}
{TMod}{TEq}				{tokType="TModAssign";	tokClass = OPERATOR;	return MODASSIGN;}
{TAmp}{TEq}				{tokType="TANDAssign";	tokClass = OPERATOR;	return ANDASSIGN;}
{TOR}{TEq}				{tokType="TORAssign";	tokClass = OPERATOR;	return ORASSIGN;}
{TXOR}{TEq}				{tokType="TXORAssign";	tokClass = OPERATOR;	return XORASSIGN;}
{TLT}{TLT}{TEq}				{tokType="TShiftLAssign";	tokClass = OPERATOR;	return SHIFTLASSIGN;}
{TGT}{TGT}{TEq}				{tokType="TShiftRAssign";	tokClass = OPERATOR;	return SHIFTRASSIGN;}



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
