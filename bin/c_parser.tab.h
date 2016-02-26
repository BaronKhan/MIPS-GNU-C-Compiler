/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CONSTANT = 258,
     KEYWORD = 259,
     OPERATOR = 260,
     STRINGLITERAL = 261,
     INTCONST = 262,
     FLOATCONST = 263,
     STRING = 264,
     IDENTIFIER = 265,
     INVALID = 266,
     FOR = 267,
     IF = 268,
     ELSE = 269,
     TYPEDEF = 270,
     WHILE = 271,
     DO = 272,
     RETURN = 273,
     CONST = 274,
     EXTERN = 275,
     CONTINUE = 276,
     DEFAULT = 277,
     GOTO = 278,
     SWITCH = 279,
     INT = 280,
     CHAR = 281,
     FLOAT = 282,
     DOUBLE = 283,
     LONG = 284,
     SHORT = 285,
     UNSIGNED = 286,
     VOID = 287,
     STATIC = 288,
     REGISTER = 289,
     BREAK = 290,
     AUTO = 291,
     UNION = 292,
     ENUM = 293,
     SIGNED = 294,
     CASE = 295,
     VOLATILE = 296,
     STRUCT = 297,
     ADD = 298,
     SUB = 299,
     MUL = 300,
     DIV = 301,
     MOD = 302,
     LEFT = 303,
     RIGHT = 304,
     EQ = 305,
     COMP = 306,
     NOTEQ = 307,
     LTEQ = 308,
     GTEQ = 309,
     GT = 310,
     LT = 311,
     SQUARELEFT = 312,
     SQUARERIGHT = 313,
     PERIOD = 314,
     SCOPELEFT = 315,
     SCOPERIGHT = 316,
     SEMI = 317,
     COLON = 318,
     COMMA = 319,
     INC = 320,
     DEC = 321,
     QUES = 322,
     BWNOT = 323,
     LOGICNOT = 324,
     BWAND = 325,
     LOGICAND = 326,
     BWOR = 327,
     LOGICOR = 328,
     XOR = 329,
     SIZEOF = 330,
     SHIFTL = 331,
     SHIFTR = 332,
     ADDASSIGN = 333,
     SUBASSIGN = 334,
     MULASSIGN = 335,
     DIVASSIGN = 336,
     MODASSIGN = 337,
     ANDASSIGN = 338,
     ORASSIGN = 339,
     XORASSIGN = 340,
     SHIFTLASSIGN = 341,
     SHIFTRASSIGN = 342
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 14 "src/c_parser.y"

	int num;
	double fp;
	char* str;



/* Line 1685 of yacc.c  */
#line 146 "bin/c_parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


