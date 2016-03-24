/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "src/c_parser.y"

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


/* Line 189 of yacc.c  */
#line 92 "src/c_parser.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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
     POINTER = 333,
     ADDASSIGN = 334,
     SUBASSIGN = 335,
     MULASSIGN = 336,
     DIVASSIGN = 337,
     MODASSIGN = 338,
     ANDASSIGN = 339,
     ORASSIGN = 340,
     XORASSIGN = 341,
     SHIFTLASSIGN = 342,
     SHIFTRASSIGN = 343
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 20 "src/c_parser.y"

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



/* Line 214 of yacc.c  */
#line 233 "src/c_parser.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */

/* Line 264 of yacc.c  */
#line 95 "src/c_parser.y"

File_Node* root = new File_Node;


/* Line 264 of yacc.c  */
#line 250 "src/c_parser.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   587

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  168
/* YYNRULES -- Number of states.  */
#define YYNSTATES  265

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   343

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    13,    20,    26,    33,
      39,    43,    46,    48,    50,    55,    58,    61,    64,    66,
      68,    71,    74,    76,    80,    85,    89,    94,    98,   104,
     106,   109,   113,   118,   122,   127,   131,   137,   139,   142,
     144,   146,   148,   150,   152,   154,   157,   163,   169,   176,
     183,   186,   189,   195,   201,   209,   217,   221,   224,   232,
     240,   244,   246,   250,   254,   258,   260,   262,   264,   270,
     274,   276,   280,   282,   286,   288,   292,   294,   298,   300,
     304,   306,   310,   312,   316,   320,   323,   326,   329,   334,
     337,   340,   342,   344,   348,   350,   355,   359,   364,   368,
     372,   375,   378,   380,   382,   386,   390,   394,   399,   403,
     405,   407,   409,   411,   414,   416,   418,   420,   422,   424,
     426,   428,   430,   432,   434,   436,   438,   440,   442,   444,
     446,   448,   450,   452,   454,   456,   458,   460,   462,   464,
     466,   468,   470,   472,   474,   476,   478,   480,   482,   484,
     486,   488,   490,   492,   494,   496,   498,   500,   502,   504,
     506,   508,   510,   512,   514,   516,   518,   520,   522
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      90,     0,    -1,   100,    90,    -1,    91,    90,    -1,   100,
      -1,    91,    -1,   129,    10,    48,    95,    49,    92,    -1,
     129,    10,    48,    49,    92,    -1,   129,    10,    48,    95,
      49,    62,    -1,   129,    10,    48,    49,    62,    -1,    93,
      96,    94,    -1,    93,    94,    -1,    60,    -1,    61,    -1,
     129,    10,    64,    95,    -1,   129,    10,    -1,    98,    96,
      -1,    92,    97,    -1,    97,    -1,    98,    -1,    92,    97,
      -1,   102,    97,    -1,   102,    -1,   129,    99,    62,    -1,
     129,    45,    99,    62,    -1,    10,    64,    99,    -1,    10,
     125,    64,    99,    -1,    10,    50,   110,    -1,    10,    50,
     110,    64,    99,    -1,    10,    -1,    10,   125,    -1,   129,
     101,    62,    -1,   129,    45,   101,    62,    -1,    10,    64,
     101,    -1,    10,   125,    64,   101,    -1,    10,    50,   110,
      -1,    10,    50,   110,    64,   101,    -1,    10,    -1,    10,
     125,    -1,   103,    -1,   104,    -1,   106,    -1,   107,    -1,
     108,    -1,   109,    -1,   110,    62,    -1,    13,    48,   110,
      49,   102,    -1,    13,    48,   110,    49,    92,    -1,    13,
      48,   110,    49,   102,   105,    -1,    13,    48,   110,    49,
      92,   105,    -1,    14,   102,    -1,    14,    92,    -1,    16,
      48,   110,    49,   102,    -1,    16,    48,   110,    49,    92,
      -1,    12,    48,   103,   103,   110,    49,   102,    -1,    12,
      48,   103,   103,   110,    49,    92,    -1,    18,   110,    62,
      -1,    18,    62,    -1,    17,    92,    16,    48,   110,    49,
      62,    -1,    17,   102,    16,    48,   110,    49,    62,    -1,
     110,    64,   111,    -1,   111,    -1,   111,   131,   114,    -1,
     111,   131,   113,    -1,   111,   131,   112,    -1,   112,    -1,
     113,    -1,   114,    -1,   113,    67,   114,    63,   114,    -1,
     114,   141,   114,    -1,   115,    -1,   114,   132,   115,    -1,
     116,    -1,   115,   133,   116,    -1,   117,    -1,   116,   134,
     117,    -1,   118,    -1,   117,   135,   118,    -1,   119,    -1,
     118,   136,   119,    -1,   120,    -1,   119,   137,   120,    -1,
     121,    -1,   120,   138,   121,    -1,   121,   139,   123,    -1,
      65,   123,    -1,    66,   123,    -1,    75,   123,    -1,    75,
      48,   130,    49,    -1,   140,   123,    -1,   122,   123,    -1,
     123,    -1,   126,    -1,    48,   130,    49,    -1,   124,    -1,
     123,    57,   110,    58,    -1,   123,    48,    49,    -1,   123,
      48,   127,    49,    -1,   123,    59,    10,    -1,   123,    78,
      10,    -1,   123,    65,    -1,   123,    66,    -1,    10,    -1,
     128,    -1,    48,   110,    49,    -1,    57,     7,    58,    -1,
      10,    48,    49,    -1,    10,    48,   127,    49,    -1,   114,
      64,   127,    -1,   114,    -1,     7,    -1,     8,    -1,     9,
      -1,   130,   129,    -1,   130,    -1,    15,    -1,    19,    -1,
      20,    -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1,
      29,    -1,    30,    -1,    31,    -1,    32,    -1,    33,    -1,
      34,    -1,    36,    -1,    37,    -1,    38,    -1,    39,    -1,
      41,    -1,    42,    -1,    79,    -1,    80,    -1,    81,    -1,
      82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,
      87,    -1,    88,    -1,    50,    -1,    73,    -1,    71,    -1,
      72,    -1,    74,    -1,    70,    -1,    76,    -1,    77,    -1,
      43,    -1,    44,    -1,    45,    -1,    46,    -1,    47,    -1,
      68,    -1,    69,    -1,    43,    -1,    44,    -1,    70,    -1,
      45,    -1,    51,    -1,    52,    -1,    53,    -1,    54,    -1,
      55,    -1,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   106,   107,   108,   111,   112,   113,   114,
     117,   118,   121,   124,   128,   129,   132,   133,   134,   135,
     138,   139,   140,   143,   144,   147,   148,   149,   150,   151,
     152,   156,   157,   160,   161,   162,   163,   164,   165,   169,
     170,   171,   172,   173,   174,   177,   181,   182,   183,   184,
     187,   188,   191,   192,   195,   196,   200,   201,   204,   205,
     209,   210,   213,   214,   215,   216,   217,   218,   221,   224,
     227,   228,   231,   232,   235,   236,   239,   240,   243,   244,
     247,   248,   251,   252,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   266,   269,   270,   271,   272,   273,   274,
     275,   276,   279,   280,   281,   287,   292,   293,   298,   299,
     302,   303,   304,   307,   308,   311,   311,   311,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     313,   313,   313,   313,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   331,   334,   337,   340,   343,
     346,   347,   350,   351,   354,   355,   356,   363,   364,   365,
     366,   367,   368,   371,   372,   373,   374,   375,   376
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONSTANT", "KEYWORD", "OPERATOR",
  "STRINGLITERAL", "INTCONST", "FLOATCONST", "STRING", "IDENTIFIER",
  "INVALID", "FOR", "IF", "ELSE", "TYPEDEF", "WHILE", "DO", "RETURN",
  "CONST", "EXTERN", "CONTINUE", "DEFAULT", "GOTO", "SWITCH", "INT",
  "CHAR", "FLOAT", "DOUBLE", "LONG", "SHORT", "UNSIGNED", "VOID", "STATIC",
  "REGISTER", "BREAK", "AUTO", "UNION", "ENUM", "SIGNED", "CASE",
  "VOLATILE", "STRUCT", "ADD", "SUB", "MUL", "DIV", "MOD", "LEFT", "RIGHT",
  "EQ", "COMP", "NOTEQ", "LTEQ", "GTEQ", "GT", "LT", "SQUARELEFT",
  "SQUARERIGHT", "PERIOD", "SCOPELEFT", "SCOPERIGHT", "SEMI", "COLON",
  "COMMA", "INC", "DEC", "QUES", "BWNOT", "LOGICNOT", "BWAND", "LOGICAND",
  "BWOR", "LOGICOR", "XOR", "SIZEOF", "SHIFTL", "SHIFTR", "POINTER",
  "ADDASSIGN", "SUBASSIGN", "MULASSIGN", "DIVASSIGN", "MODASSIGN",
  "ANDASSIGN", "ORASSIGN", "XORASSIGN", "SHIFTLASSIGN", "SHIFTRASSIGN",
  "$accept", "File", "Function", "Block", "StartScope", "EndScope",
  "Parameter", "CompoundStatement", "CompoundStatement2", "DeclStatement",
  "Declaration", "GlobalDeclStatement", "GlobalDeclaration", "Statement",
  "ExprStatement", "IfStatement", "ElseStatement", "WhileStatement",
  "ForStatement", "ReturnStatement", "DoWhileStatement", "Expr",
  "Assignment", "TernaryExpr", "ConditionalExpr", "UnaryExpr",
  "UnaryExpr2", "UnaryExpr3", "UnaryExpr4", "UnaryExpr5", "UnaryExpr6",
  "UnaryExpr7", "UnaryExpr8", "Cast", "PostFixExpr", "PrimaryExpr",
  "ArrayDecl", "Call", "Argument", "Value", "CompoundType", "Type",
  "OpAssign", "OpManipulate", "OpManipulate2", "OpManipulate3",
  "OpManipulate4", "OpManipulate5", "OpManipulate6", "OpManipulate7",
  "OpManipulate8", "OpUnary", "OpCond", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    90,    90,    90,    91,    91,    91,    91,
      92,    92,    93,    94,    95,    95,    96,    96,    96,    96,
      97,    97,    97,    98,    98,    99,    99,    99,    99,    99,
      99,   100,   100,   101,   101,   101,   101,   101,   101,   102,
     102,   102,   102,   102,   102,   103,   104,   104,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   111,   111,   111,   111,   112,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   122,   123,   123,   123,   123,   123,   123,
     123,   123,   124,   124,   124,   125,   126,   126,   127,   127,
     128,   128,   128,   129,   129,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   132,   133,   134,   135,   136,
     137,   137,   138,   138,   139,   139,   139,   140,   140,   140,
     140,   140,   140,   141,   141,   141,   141,   141,   141
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     6,     5,     6,     5,
       3,     2,     1,     1,     4,     2,     2,     2,     1,     1,
       2,     2,     1,     3,     4,     3,     4,     3,     5,     1,
       2,     3,     4,     3,     4,     3,     5,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     5,     5,     6,     6,
       2,     2,     5,     5,     7,     7,     3,     2,     7,     7,
       3,     1,     3,     3,     3,     1,     1,     1,     5,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     2,     2,     2,     4,     2,
       2,     1,     1,     3,     1,     4,     3,     4,     3,     3,
       2,     2,     1,     1,     3,     3,     3,     4,     3,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
       0,     5,     4,     0,   114,     1,     3,     2,    37,     0,
       0,   113,     0,     0,     0,     0,    38,    37,     0,    31,
       0,     0,     0,   110,   111,   112,   102,   159,   160,   162,
       0,     0,     0,   157,   158,   161,     0,    35,    61,    65,
      66,    67,    70,    72,    74,    76,    78,    80,    82,     0,
      91,    94,    92,   103,     0,     0,    33,     0,    32,    12,
       9,     7,     0,     0,    15,     0,     0,     0,   102,     0,
      85,    86,     0,    87,     0,   144,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,     0,     0,   163,   164,
     165,   166,   167,   168,   145,     0,     0,   146,     0,   147,
       0,   148,     0,   149,     0,   150,   151,     0,   152,   153,
       0,   154,   155,   156,     0,    90,     0,     0,     0,   100,
     101,     0,    89,   105,    34,     0,     0,     0,     0,     0,
      13,     0,    11,     0,    18,    19,    22,    39,    40,    41,
      42,    43,    44,     0,     0,     8,     6,     0,   106,   109,
       0,   104,     0,    93,     0,   102,    36,    60,    64,    63,
      62,     0,    71,    69,    73,    75,    77,    79,    81,    83,
      84,    96,     0,     0,    98,    99,     0,     0,     0,     0,
       0,    57,     0,     0,    17,    10,    16,    21,    45,    29,
       0,     0,    14,     0,   107,    88,     0,    97,    95,     0,
       0,     0,     0,     0,    56,    20,     0,     0,    30,     0,
      23,   108,    68,     0,     0,     0,     0,     0,    27,    25,
       0,    24,     0,    47,    46,    53,    52,     0,     0,     0,
      26,     0,     0,    49,    48,     0,     0,   102,    28,    55,
      54,    51,    50,    58,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,   203,    82,   152,    41,   153,   154,   155,
     211,    22,    30,   156,   157,   158,   253,   159,   160,   161,
     162,   163,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    36,    72,   170,    73,
      23,    24,   106,   115,   118,   120,   122,   124,   127,   130,
     134,    74,   116
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -202
static const yytype_int16 yypact[] =
{
     545,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
      34,   545,   545,     6,   545,  -202,  -202,  -202,    27,    31,
      24,  -202,   520,   418,    87,    31,    70,    73,    36,  -202,
      58,   101,   141,  -202,  -202,  -202,   106,  -202,  -202,  -202,
     334,    30,    30,  -202,  -202,  -202,    37,   114,    78,  -202,
     118,   273,   110,   119,   113,   127,   -23,    14,    93,    30,
     123,  -202,  -202,  -202,    30,   134,  -202,    31,  -202,  -202,
    -202,  -202,   206,   115,   129,   104,   -37,   149,  -202,   418,
     123,   123,   334,   123,   426,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,   418,   418,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,   418,   418,  -202,   418,  -202,
     418,  -202,   418,  -202,   418,  -202,  -202,   418,  -202,  -202,
     418,  -202,  -202,  -202,    30,   123,   348,   418,   189,  -202,
    -202,   190,   123,  -202,  -202,   154,   156,   157,    56,   376,
    -202,    56,  -202,   147,  -202,   270,    56,  -202,  -202,  -202,
    -202,  -202,  -202,    80,     7,  -202,  -202,   545,  -202,    82,
     160,  -202,   418,  -202,   161,    33,  -202,    78,  -202,   118,
     273,   -52,   110,   144,   119,   113,   127,   -23,    14,    93,
     123,  -202,   171,   -35,  -202,  -202,   418,   418,   418,   211,
     212,  -202,   122,    56,  -202,  -202,  -202,  -202,  -202,   126,
     219,   168,  -202,   418,  -202,  -202,   418,  -202,  -202,   418,
     -34,   -16,   193,   198,  -202,  -202,   418,   219,   188,   191,
    -202,  -202,   144,   418,    56,    56,   418,   418,   192,  -202,
     219,  -202,    12,   241,   241,  -202,  -202,    39,    53,   468,
    -202,    56,    56,  -202,  -202,   195,   196,    79,  -202,  -202,
    -202,  -202,  -202,  -202,  -202
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -202,    84,  -202,   -40,  -202,   107,    92,   108,  -132,  -202,
    -160,  -202,    -7,  -142,  -187,  -202,    17,  -202,  -202,  -202,
    -202,   -30,   -93,   158,   159,   -81,   153,   151,   142,   148,
     167,   146,   162,  -202,   -38,  -202,  -201,  -202,  -131,  -202,
     -22,   -43,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -38
static const yytype_int16 yytable[] =
{
      81,   177,    31,    57,   169,   192,   200,    87,   228,   219,
      42,   216,   171,    90,    91,   234,    28,   209,    93,   204,
      86,   114,    38,   218,   207,   180,   181,   172,    76,   172,
     172,   135,   233,   235,    25,   183,   142,    43,    44,    45,
      88,    37,   151,   166,    43,    44,    45,    88,   172,   174,
     229,    29,   210,   125,   126,   169,   228,   128,   129,    86,
     164,   251,    86,    43,    44,    45,    46,   239,   145,   146,
     144,   225,   147,   148,   149,    32,   172,    33,    89,   177,
     250,    85,   231,    33,    34,    92,    39,   176,   255,   258,
      34,    35,   244,   246,    75,   -37,   190,    35,    78,    47,
      48,    49,   256,   172,    50,    26,    27,   193,   199,   260,
     262,    43,    44,    45,    46,   151,    79,   172,    79,   202,
      80,    51,    52,    33,    53,    54,    55,    85,    95,   226,
      34,    56,   169,   164,    77,   232,    34,    35,   131,   132,
     133,   -29,   208,   227,   172,    42,   213,    47,    48,    49,
      83,    84,    50,   168,    85,   114,   177,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   220,   221,    51,
      52,   136,    53,    54,    55,    79,   226,   165,    94,    56,
     137,   117,   138,    34,   224,   107,   172,   121,   139,   140,
     227,   119,   143,   167,   243,   245,   238,   123,   173,   194,
     195,   141,   196,   242,   197,   198,   247,   248,   150,   214,
     215,   259,   261,    43,    44,    45,    46,   114,   145,   146,
     217,     1,   147,   148,   149,     2,     3,   222,   223,   209,
     230,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,   236,    14,    15,    16,    17,   237,    18,    19,    47,
      48,    49,   240,   241,    50,   252,   249,   263,   264,   212,
     205,   254,   185,   206,   178,   179,    79,   150,   182,   184,
     186,    51,    52,   188,    53,    54,    55,    43,    44,    45,
      46,    56,   145,   146,     0,     1,   147,   148,   149,     2,
       3,   187,   189,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
       0,    18,    19,    47,    48,    49,     0,     0,    50,     0,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
      79,     0,     0,     0,     0,    51,    52,     0,    53,    54,
      55,    43,    44,    45,    46,    56,   114,     0,     0,     1,
       0,     0,     0,     2,     3,    43,    44,    45,    46,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      14,    15,    16,    17,     0,    18,    19,    47,    48,    49,
       0,     0,    50,    43,    44,    45,    46,     0,     0,     0,
       0,    47,    48,    49,     0,     0,    50,   191,     0,    51,
      52,     0,    53,    54,    55,     0,     0,     0,     0,    56,
       0,     0,     0,    51,    52,     0,    53,    54,    55,    47,
      48,    49,     0,    56,    50,    43,    44,    45,    46,     0,
       0,     0,     0,    43,    44,    45,   175,     0,   201,     0,
       0,    51,    52,     0,    53,    54,    55,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,    48,    49,     0,     0,    50,     0,     0,    47,
      48,    49,     0,     0,    50,    43,    44,    45,   257,     0,
       0,     0,     0,    51,    52,     0,    53,    54,    55,     0,
       0,    51,    52,    56,    53,    54,    55,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,    48,    49,     0,     0,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,    52,     1,    53,    54,    55,     2,
       3,     0,     0,    56,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
       1,    18,    19,     0,     2,     3,     0,     0,     0,    40,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       0,    14,    15,    16,    17,     0,    18,    19
};

static const yytype_int16 yycheck[] =
{
      40,    94,    24,    33,    85,   136,   148,    50,   209,   196,
      32,    63,    49,    51,    52,    49,    10,    10,    56,   151,
      50,    73,    29,    58,   156,   106,   107,    64,    35,    64,
      64,    69,   219,    49,     0,   116,    74,     7,     8,     9,
      10,    10,    82,    83,     7,     8,     9,    10,    64,    92,
     210,    45,    45,    76,    77,   136,   257,    43,    44,    89,
      82,    49,    92,     7,     8,     9,    10,   227,    12,    13,
      77,   203,    16,    17,    18,    48,    64,    50,    48,   172,
     240,    48,   213,    50,    57,    48,    62,    94,    49,   249,
      57,    64,   234,   235,     7,    62,   134,    64,    62,    43,
      44,    45,    49,    64,    48,    21,    22,   137,   148,   251,
     252,     7,     8,     9,    10,   155,    60,    64,    60,   149,
      62,    65,    66,    50,    68,    69,    70,    48,    50,    50,
      57,    75,   213,   155,    64,   216,    57,    64,    45,    46,
      47,    62,    62,    64,    64,   167,    64,    43,    44,    45,
      49,    10,    48,    49,    48,    73,   249,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,   197,   198,    65,
      66,    48,    68,    69,    70,    60,    50,    62,    64,    75,
      57,    71,    59,    57,    62,    67,    64,    74,    65,    66,
      64,    72,    58,    64,   234,   235,   226,    70,    49,    10,
      10,    78,    48,   233,    48,    48,   236,   237,    61,    49,
      49,   251,   252,     7,     8,     9,    10,    73,    12,    13,
      49,    15,    16,    17,    18,    19,    20,    16,    16,    10,
      62,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    48,    36,    37,    38,    39,    48,    41,    42,    43,
      44,    45,    64,    62,    48,    14,    64,    62,    62,   167,
     153,   244,   120,   155,   106,   106,    60,    61,   115,   118,
     122,    65,    66,   127,    68,    69,    70,     7,     8,     9,
      10,    75,    12,    13,    -1,    15,    16,    17,    18,    19,
      20,   124,   130,    -1,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,    41,    42,    43,    44,    45,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      60,    -1,    -1,    -1,    -1,    65,    66,    -1,    68,    69,
      70,     7,     8,     9,    10,    75,    73,    -1,    -1,    15,
      -1,    -1,    -1,    19,    20,     7,     8,     9,    10,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    45,
      -1,    -1,    48,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    43,    44,    45,    -1,    -1,    48,    49,    -1,    65,
      66,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    70,    43,
      44,    45,    -1,    75,    48,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,     7,     8,     9,    10,    -1,    62,    -1,
      -1,    65,    66,    -1,    68,    69,    70,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    -1,    -1,    48,    -1,    -1,    43,
      44,    45,    -1,    -1,    48,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    70,    -1,
      -1,    65,    66,    75,    68,    69,    70,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    15,    68,    69,    70,    19,
      20,    -1,    -1,    75,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      15,    41,    42,    -1,    19,    20,    -1,    -1,    -1,    49,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    38,    39,    -1,    41,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    19,    20,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    36,    37,    38,    39,    41,    42,
      90,    91,   100,   129,   130,     0,    90,    90,    10,    45,
     101,   129,    48,    50,    57,    64,   125,    10,   101,    62,
      49,    95,   129,     7,     8,     9,    10,    43,    44,    45,
      48,    65,    66,    68,    69,    70,    75,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   126,   128,   140,     7,   101,    64,    62,    60,
      62,    92,    93,    49,    10,    48,   110,   130,    10,    48,
     123,   123,    48,   123,    64,    50,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,   131,    67,    51,    52,
      53,    54,    55,    56,    73,   132,   141,    71,   133,    72,
     134,    74,   135,    70,   136,    76,    77,   137,    43,    44,
     138,    45,    46,    47,   139,   123,    48,    57,    59,    65,
      66,    78,   123,    58,   101,    12,    13,    16,    17,    18,
      61,    92,    94,    96,    97,    98,   102,   103,   104,   106,
     107,   108,   109,   110,   129,    62,    92,    64,    49,   114,
     127,    49,    64,    49,   130,    10,   101,   111,   112,   113,
     114,   114,   115,   114,   116,   117,   118,   119,   120,   121,
     123,    49,   127,   110,    10,    10,    48,    48,    48,    92,
     102,    62,   110,    92,    97,    94,    96,    97,    62,    10,
      45,    99,    95,    64,    49,    49,    63,    49,    58,   103,
     110,   110,    16,    16,    62,    97,    50,    64,   125,    99,
      62,   127,   114,   103,    49,    49,    48,    48,   110,    99,
      64,    62,   110,    92,   102,    92,   102,   110,   110,    64,
      99,    49,    14,   105,   105,    49,    49,    10,    99,    92,
     102,    92,   102,    62,    62
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1464 of yacc.c  */
#line 105 "src/c_parser.y"
    {root->file_list.push_back((yyvsp[(1) - (2)].NodePtr));;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 106 "src/c_parser.y"
    {root->file_list.push_back((yyvsp[(1) - (2)].NodePtr));;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 107 "src/c_parser.y"
    {root->file_list.push_back((yyvsp[(1) - (1)].NodePtr));;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 108 "src/c_parser.y"
    {root->file_list.push_back((yyvsp[(1) - (1)].NodePtr));;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 111 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(2) - (6)].str)); Function_Node* func = new Function_Node(id,(yyvsp[(4) - (6)].Parameter_NodePtr),(yyvsp[(6) - (6)].NodePtr),variable_count); (yyval.NodePtr) = func; variable_count = 0;;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 112 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(2) - (5)].str)); Function_Node* func = new Function_Node(id,NULL,(yyvsp[(5) - (5)].NodePtr),variable_count); (yyval.NodePtr) = func; variable_count = 0;;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 113 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(2) - (6)].str)); Node* decl = new Decl_Node(currentType, id, false, NULL, NULL); (yyval.NodePtr) = decl; global_variable_count++;;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 114 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(2) - (5)].str)); Node* decl = new Decl_Node(currentType, id, false, NULL, NULL); (yyval.NodePtr) = decl; global_variable_count++;;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 117 "src/c_parser.y"
    {Block_Node* block = new Block_Node((yyvsp[(2) - (3)].NodePtr)); (yyval.NodePtr) = block;;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 118 "src/c_parser.y"
    {Block_Node* block = new Block_Node(NULL); (yyval.NodePtr) = block;;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 128 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(2) - (4)].str)); Parameter_Node* p = new Parameter_Node((yyvsp[(1) - (4)].Type_NodePtr),id,(yyvsp[(4) - (4)].Parameter_NodePtr)); (yyval.Parameter_NodePtr) = p; variable_count++;;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 129 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(2) - (2)].str)); Parameter_Node* p = new Parameter_Node((yyvsp[(1) - (2)].Type_NodePtr),id,NULL); (yyval.Parameter_NodePtr) = p; variable_count++;;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 132 "src/c_parser.y"
    {Node* compound = new CompoundStatement_Node((yyvsp[(1) - (2)].NodePtr),(yyvsp[(2) - (2)].NodePtr)); (yyval.NodePtr) = compound;;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 133 "src/c_parser.y"
    {Node* compound = new CompoundStatement_Node((yyvsp[(1) - (2)].NodePtr),(yyvsp[(2) - (2)].NodePtr)); (yyval.NodePtr) = compound;;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 134 "src/c_parser.y"
    {Node* compound = new CompoundStatement_Node((yyvsp[(1) - (1)].NodePtr),NULL); (yyval.NodePtr) = compound;;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 135 "src/c_parser.y"
    {Node* compound = new CompoundStatement_Node((yyvsp[(1) - (1)].NodePtr),NULL); (yyval.NodePtr) = compound;;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 138 "src/c_parser.y"
    {Node* compound = new CompoundStatement_Node((yyvsp[(1) - (2)].NodePtr),(yyvsp[(2) - (2)].NodePtr)); (yyval.NodePtr) = compound;;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 139 "src/c_parser.y"
    {Node* compound = new CompoundStatement_Node((yyvsp[(1) - (2)].NodePtr),(yyvsp[(2) - (2)].NodePtr)); (yyval.NodePtr) = compound;;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 140 "src/c_parser.y"
    {Node* compound = new CompoundStatement_Node((yyvsp[(1) - (1)].NodePtr),NULL); (yyval.NodePtr) = compound;;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 143 "src/c_parser.y"
    {Node* declStatement = new DeclStatement_Node((yyvsp[(1) - (3)].Type_NodePtr), (yyvsp[(2) - (3)].NodePtr), false); (yyval.NodePtr) = declStatement;;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 144 "src/c_parser.y"
    {Node* declStatement = new DeclStatement_Node((yyvsp[(1) - (4)].Type_NodePtr), (yyvsp[(3) - (4)].NodePtr), true); (yyval.NodePtr) = declStatement;;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 147 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(1) - (3)].str)); Node* decl = new Decl_Node(currentType, id, false, NULL, (yyvsp[(3) - (3)].NodePtr)); (yyval.NodePtr) = decl; variable_count++;;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 148 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(1) - (4)].str)); Node* decl = new Decl_Node(currentType, id, false, NULL, (yyvsp[(4) - (4)].NodePtr), (yyvsp[(2) - (4)].num)); (yyval.NodePtr) = decl; variable_count+=(yyvsp[(2) - (4)].num);;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 149 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(1) - (3)].str)); Node* decl = new Decl_Node(currentType, id, true, (yyvsp[(3) - (3)].NodePtr), NULL); (yyval.NodePtr) = decl; variable_count++;;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 150 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(1) - (5)].str)); Node* decl = new Decl_Node(currentType, id, true, (yyvsp[(3) - (5)].NodePtr), (yyvsp[(5) - (5)].NodePtr)); (yyval.NodePtr) = decl; variable_count++;;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 151 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(1) - (1)].str)); Node* decl = new Decl_Node(currentType, id, false, NULL, NULL); (yyval.NodePtr) = decl; variable_count++;;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 152 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(1) - (2)].str)); Node* decl = new Decl_Node(currentType, id, false, NULL, NULL, (yyvsp[(2) - (2)].num)); (yyval.NodePtr) = decl; variable_count+=(yyvsp[(2) - (2)].num);;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 156 "src/c_parser.y"
    {Node* declStatement = new DeclStatement_Node((yyvsp[(1) - (3)].Type_NodePtr), (yyvsp[(2) - (3)].NodePtr), false); (yyval.NodePtr) = declStatement;;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 157 "src/c_parser.y"
    {Node* declStatement = new DeclStatement_Node((yyvsp[(1) - (4)].Type_NodePtr), (yyvsp[(3) - (4)].NodePtr), true); (yyval.NodePtr) = declStatement;;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 160 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(1) - (3)].str)); Node* decl = new Decl_Node(currentType, id, false, NULL, (yyvsp[(3) - (3)].NodePtr)); (yyval.NodePtr) = decl; global_variable_count++;;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 161 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(1) - (4)].str)); Node* decl = new Decl_Node(currentType, id, false, NULL, (yyvsp[(4) - (4)].NodePtr), (yyvsp[(2) - (4)].num)); (yyval.NodePtr) = decl; global_variable_count+=(yyvsp[(2) - (4)].num);;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 162 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(1) - (3)].str)); Node* decl = new Decl_Node(currentType, id, true, (yyvsp[(3) - (3)].NodePtr), NULL); (yyval.NodePtr) = decl; global_variable_count++;;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 163 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(1) - (5)].str)); Node* decl = new Decl_Node(currentType, id, true, (yyvsp[(3) - (5)].NodePtr), (yyvsp[(5) - (5)].NodePtr)); (yyval.NodePtr) = decl; global_variable_count++;;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 164 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(1) - (1)].str)); Node* decl = new Decl_Node(currentType, id, false, NULL, NULL); (yyval.NodePtr) = decl; global_variable_count++;;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 165 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(1) - (2)].str)); Node* decl = new Decl_Node(currentType, id, false, NULL, NULL, (yyvsp[(2) - (2)].num)); (yyval.NodePtr) = decl; global_variable_count+=(yyvsp[(2) - (2)].num);;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 169 "src/c_parser.y"
    {Node* new_statement = new Statement_Node((yyvsp[(1) - (1)].NodePtr)); (yyval.NodePtr) = new_statement;;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 170 "src/c_parser.y"
    {Node* new_statement = new Statement_Node((yyvsp[(1) - (1)].NodePtr)); (yyval.NodePtr) = new_statement;;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 171 "src/c_parser.y"
    {Node* new_statement = new Statement_Node((yyvsp[(1) - (1)].NodePtr)); (yyval.NodePtr) = new_statement;;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 172 "src/c_parser.y"
    {Node* new_statement = new Statement_Node((yyvsp[(1) - (1)].NodePtr)); (yyval.NodePtr) = new_statement;;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 173 "src/c_parser.y"
    {Node* new_statement = new Statement_Node((yyvsp[(1) - (1)].NodePtr)); (yyval.NodePtr) = new_statement;;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 174 "src/c_parser.y"
    {Node* new_statement = new Statement_Node((yyvsp[(1) - (1)].NodePtr)); (yyval.NodePtr) = new_statement;;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 177 "src/c_parser.y"
    {Node* new_expr_statement = new ExprStatement_Node((yyvsp[(1) - (2)].NodePtr)); (yyval.NodePtr) = new_expr_statement;;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 181 "src/c_parser.y"
    {Node* new_if_statement = new IfStatement_Node((yyvsp[(3) - (5)].NodePtr), (yyvsp[(5) - (5)].NodePtr), NULL); (yyval.NodePtr) = new_if_statement;;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 182 "src/c_parser.y"
    {Node* new_if_statement = new IfStatement_Node((yyvsp[(3) - (5)].NodePtr), (yyvsp[(5) - (5)].NodePtr), NULL); (yyval.NodePtr) = new_if_statement;;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 183 "src/c_parser.y"
    {Node* new_if_statement = new IfStatement_Node((yyvsp[(3) - (6)].NodePtr), (yyvsp[(5) - (6)].NodePtr), (yyvsp[(6) - (6)].NodePtr)); (yyval.NodePtr) = new_if_statement;;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 184 "src/c_parser.y"
    {Node* new_if_statement = new IfStatement_Node((yyvsp[(3) - (6)].NodePtr), (yyvsp[(5) - (6)].NodePtr), (yyvsp[(6) - (6)].NodePtr)); (yyval.NodePtr) = new_if_statement;;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 187 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(2) - (2)].NodePtr);;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 188 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(2) - (2)].NodePtr);;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 191 "src/c_parser.y"
    {Node* new_while_statement = new WhileStatement_Node((yyvsp[(3) - (5)].NodePtr), (yyvsp[(5) - (5)].NodePtr)); (yyval.NodePtr) = new_while_statement;;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 192 "src/c_parser.y"
    {Node* new_while_statement = new WhileStatement_Node((yyvsp[(3) - (5)].NodePtr), (yyvsp[(5) - (5)].NodePtr)); (yyval.NodePtr) = new_while_statement;;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 195 "src/c_parser.y"
    {Node* new_for_statement = new ForStatement_Node((yyvsp[(3) - (7)].NodePtr),(yyvsp[(4) - (7)].NodePtr),(yyvsp[(5) - (7)].NodePtr),(yyvsp[(7) - (7)].NodePtr)); (yyval.NodePtr) = new_for_statement;;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 196 "src/c_parser.y"
    {Node* new_for_statement = new ForStatement_Node((yyvsp[(3) - (7)].NodePtr),(yyvsp[(4) - (7)].NodePtr),(yyvsp[(5) - (7)].NodePtr),(yyvsp[(7) - (7)].NodePtr)); (yyval.NodePtr) = new_for_statement;;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 200 "src/c_parser.y"
    {Node* new_return_statement = new ReturnStatement_Node((yyvsp[(2) - (3)].NodePtr)); (yyval.NodePtr) = new_return_statement;;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 201 "src/c_parser.y"
    {Node* new_return_statement = new ReturnStatement_Node(NULL); (yyval.NodePtr) = new_return_statement;;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 204 "src/c_parser.y"
    {Node* new_do_while_statement = new DoWhileStatement_Node((yyvsp[(5) - (7)].NodePtr), (yyvsp[(2) - (7)].NodePtr)); (yyval.NodePtr) = new_do_while_statement;;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 205 "src/c_parser.y"
    {Node* new_do_while_statement = new DoWhileStatement_Node((yyvsp[(5) - (7)].NodePtr), (yyvsp[(2) - (7)].NodePtr)); (yyval.NodePtr) = new_do_while_statement;;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 210 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(1) - (1)].NodePtr);;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 213 "src/c_parser.y"
    {Node* new_node = new Assignment_Node((yyvsp[(1) - (3)].NodePtr), (yyvsp[(2) - (3)].Op_NodePtr), (yyvsp[(3) - (3)].NodePtr)); (yyval.NodePtr) = new_node;;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 214 "src/c_parser.y"
    {Node* new_node = new Assignment_Node((yyvsp[(1) - (3)].NodePtr), (yyvsp[(2) - (3)].Op_NodePtr), (yyvsp[(3) - (3)].NodePtr)); (yyval.NodePtr) = new_node;;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 215 "src/c_parser.y"
    {Node* new_node = new Assignment_Node((yyvsp[(1) - (3)].NodePtr), (yyvsp[(2) - (3)].Op_NodePtr), (yyvsp[(3) - (3)].NodePtr)); (yyval.NodePtr) = new_node;;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 216 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(1) - (1)].NodePtr);;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 217 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(1) - (1)].NodePtr);;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 218 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(1) - (1)].NodePtr);;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 221 "src/c_parser.y"
    {Node* new_node = new Ternary_Node((yyvsp[(1) - (5)].NodePtr),(yyvsp[(3) - (5)].NodePtr),(yyvsp[(5) - (5)].NodePtr)); (yyval.NodePtr) = new_node;;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 224 "src/c_parser.y"
    {Node* new_node = new Expr_Node((yyvsp[(1) - (3)].NodePtr), (yyvsp[(2) - (3)].Op_NodePtr), (yyvsp[(3) - (3)].NodePtr)); (yyval.NodePtr) = new_node;;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 227 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(1) - (1)].NodePtr);;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 228 "src/c_parser.y"
    {Node* new_node = new Expr_Node((yyvsp[(1) - (3)].NodePtr), (yyvsp[(2) - (3)].Op_NodePtr), (yyvsp[(3) - (3)].NodePtr)); (yyval.NodePtr) = new_node;;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 231 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(1) - (1)].NodePtr);;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 232 "src/c_parser.y"
    {Node* new_node = new Expr_Node((yyvsp[(1) - (3)].NodePtr), (yyvsp[(2) - (3)].Op_NodePtr), (yyvsp[(3) - (3)].NodePtr)); (yyval.NodePtr) = new_node;;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 235 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(1) - (1)].NodePtr);;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 236 "src/c_parser.y"
    {Node* new_node = new Expr_Node((yyvsp[(1) - (3)].NodePtr), (yyvsp[(2) - (3)].Op_NodePtr), (yyvsp[(3) - (3)].NodePtr)); (yyval.NodePtr) = new_node;;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 239 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(1) - (1)].NodePtr);;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 240 "src/c_parser.y"
    {Node* new_node = new Expr_Node((yyvsp[(1) - (3)].NodePtr), (yyvsp[(2) - (3)].Op_NodePtr), (yyvsp[(3) - (3)].NodePtr)); (yyval.NodePtr) = new_node;;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 243 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(1) - (1)].NodePtr);;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 244 "src/c_parser.y"
    {Node* new_node = new Expr_Node((yyvsp[(1) - (3)].NodePtr), (yyvsp[(2) - (3)].Op_NodePtr), (yyvsp[(3) - (3)].NodePtr)); (yyval.NodePtr) = new_node;;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 247 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(1) - (1)].NodePtr);;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 248 "src/c_parser.y"
    {Node* new_node = new Expr_Node((yyvsp[(1) - (3)].NodePtr), (yyvsp[(2) - (3)].Op_NodePtr), (yyvsp[(3) - (3)].NodePtr)); (yyval.NodePtr) = new_node;;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 251 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(1) - (1)].NodePtr);;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 252 "src/c_parser.y"
    {Node* new_node = new Expr_Node((yyvsp[(1) - (3)].NodePtr), (yyvsp[(2) - (3)].Op_NodePtr), (yyvsp[(3) - (3)].NodePtr)); (yyval.NodePtr) = new_node;;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 255 "src/c_parser.y"
    {Node* new_node = new Expr_Node((yyvsp[(1) - (3)].NodePtr), (yyvsp[(2) - (3)].Op_NodePtr), (yyvsp[(3) - (3)].NodePtr)); (yyval.NodePtr) = new_node;;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 256 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(2) - (2)].NodePtr);;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 257 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(2) - (2)].NodePtr);;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 258 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(2) - (2)].NodePtr);;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 259 "src/c_parser.y"
    {(yyval.NodePtr) = (yyval.NodePtr);;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 260 "src/c_parser.y"
    {if (strcmp((yyvsp[(1) - (2)].str),"SUB") == 0) { ((yyvsp[(2) - (2)].NodePtr))->is_negative = true; } (yyval.NodePtr)=(yyvsp[(2) - (2)].NodePtr);;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 261 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(2) - (2)].NodePtr);;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 262 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(1) - (1)].NodePtr);;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 263 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(1) - (1)].NodePtr);;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 269 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(1) - (1)].NodePtr);;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 270 "src/c_parser.y"
    {if (((yyvsp[(1) - (4)].NodePtr))->node_type == NODE_ID) {((ID_Node*)(yyvsp[(1) - (4)].NodePtr))->array_offset = (yyvsp[(3) - (4)].NodePtr);} (yyval.NodePtr) = (yyvsp[(1) - (4)].NodePtr);;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 279 "src/c_parser.y"
    {Node* new_node = new ID_Node((yyvsp[(1) - (1)].str)); (yyval.NodePtr) = new_node;;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 280 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(1) - (1)].NodePtr);;}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 281 "src/c_parser.y"
    {(yyval.NodePtr) = (yyvsp[(2) - (3)].NodePtr);;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 287 "src/c_parser.y"
    {(yyval.num) = (yyvsp[(2) - (3)].num);;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 292 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(1) - (3)].str)); Node* new_call = new Call_Node(id, NULL); (yyval.NodePtr) = new_call;;}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 293 "src/c_parser.y"
    {ID_Node* id = new ID_Node((yyvsp[(1) - (4)].str)); Node* new_call = new Call_Node(id, (yyvsp[(3) - (4)].NodePtr)); (yyval.NodePtr) = new_call;;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 298 "src/c_parser.y"
    {Node* a = new Argument_Node((yyvsp[(1) - (3)].NodePtr),(yyvsp[(3) - (3)].NodePtr)); (yyval.NodePtr) = a;;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 299 "src/c_parser.y"
    {Node* a = new Argument_Node((yyvsp[(1) - (1)].NodePtr),NULL); (yyval.NodePtr) = a;;}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 302 "src/c_parser.y"
    {Node* new_node = new IntConst_Node((yyvsp[(1) - (1)].num)); (yyval.NodePtr) = new_node;;}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 303 "src/c_parser.y"
    {Node* new_node = new FloatConst_Node((yyvsp[(1) - (1)].fp)); (yyval.NodePtr) = new_node;;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 304 "src/c_parser.y"
    {Node* new_node = new String_Node((yyvsp[(1) - (1)].str)); (yyval.NodePtr) = new_node;;}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 307 "src/c_parser.y"
    {Type_Node* new_type = new Type_Node((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].Type_NodePtr)); (yyval.Type_NodePtr) = new_type; currentType = (yyval.Type_NodePtr);;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 308 "src/c_parser.y"
    {Type_Node* new_type = new Type_Node((yyvsp[(1) - (1)].str),NULL); (yyval.Type_NodePtr) = new_type; currentType = (yyval.Type_NodePtr); ;}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 316 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str),"+"); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 317 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str),"-"); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 318 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str),"*"); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 319 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str),"/"); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 320 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str),"%"); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 321 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str),"&"); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 322 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str),"|"); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 323 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str),"^"); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 324 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str),"<<"); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 325 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str),">>"); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 326 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 331 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 334 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 337 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 340 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 343 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 346 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 347 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 350 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 351 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 354 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 355 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 356 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 366 "src/c_parser.y"
    {strcpy((yyval.str),"SUB");;}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 371 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 372 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 373 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 374 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 375 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;

  case 168:

/* Line 1464 of yacc.c  */
#line 376 "src/c_parser.y"
    {Op_Node* new_node = new Op_Node((yyvsp[(1) - (1)].str)); (yyval.Op_NodePtr) = new_node;;}
    break;



/* Line 1464 of yacc.c  */
#line 2727 "src/c_parser.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 393 "src/c_parser.y"


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

