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

using namespace std;

int yylex();
int yyerror(const char* s);
void indent(int n);

int n = 0;


/* Line 189 of yacc.c  */
#line 86 "bin/c_parser.tab.c"

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
#line 14 "src/c_parser.y"

	int num;
	double fp;
	char* str;



/* Line 214 of yacc.c  */
#line 218 "bin/c_parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 230 "bin/c_parser.tab.c"

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
#define YYFINAL  77
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   639

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNRULES -- Number of states.  */
#define YYNSTATES  216

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
       0,     0,     3,     6,     9,    12,    14,    16,    18,    22,
      25,    27,    29,    30,    38,    39,    46,    47,    53,    56,
      59,    62,    64,    66,    68,    70,    72,    74,    77,    83,
      89,    96,   103,   106,   109,   115,   121,   129,   137,   141,
     145,   148,   152,   155,   159,   163,   165,   167,   171,   175,
     177,   179,   183,   189,   193,   196,   199,   202,   207,   210,
     213,   215,   219,   221,   226,   230,   235,   239,   243,   246,
     249,   251,   253,   257,   261,   266,   270,   276,   278,   281,
     285,   289,   294,   298,   300,   304,   306,   308,   310,   312,
     315,   317,   319,   321,   323,   325,   327,   329,   331,   333,
     335,   337,   339,   341,   343,   345,   347,   349,   351,   353,
     355,   357,   359,   361,   363,   365,   367,   369,   371,   373,
     375,   377,   379,   381,   383,   385,   387,   389,   391,   393,
     395,   397,   399,   401,   403,   405,   407,   409,   411,   413,
     415,   417,   419,   421,   423,   425,   427
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      90,     0,    -1,   100,    90,    -1,    94,    90,    -1,    91,
      90,    -1,   100,    -1,    94,    -1,    91,    -1,    92,    99,
      93,    -1,    92,    93,    -1,    60,    -1,    61,    -1,    -1,
     119,    10,    48,    95,    97,    49,    91,    -1,    -1,   119,
      10,    48,    96,    49,    91,    -1,    -1,   119,    10,    98,
      64,    97,    -1,   119,    10,    -1,    91,    99,    -1,   100,
      99,    -1,   100,    -1,   101,    -1,   102,    -1,   104,    -1,
     105,    -1,   106,    -1,   107,    62,    -1,    13,    48,   107,
      49,   100,    -1,    13,    48,   107,    49,    91,    -1,    13,
      48,   107,    49,   100,   103,    -1,    13,    48,   107,    49,
      91,   103,    -1,    14,   100,    -1,    14,    91,    -1,    16,
      48,   107,    49,   100,    -1,    16,    48,   107,    49,    91,
      -1,    12,    48,   101,   101,   107,    49,   100,    -1,    12,
      48,   101,   101,   107,    49,    91,    -1,    18,   107,    62,
      -1,    18,   118,    62,    -1,    18,    62,    -1,    18,    10,
      62,    -1,   119,   114,    -1,   119,    45,   114,    -1,   107,
      64,   108,    -1,   108,    -1,   116,    -1,   108,   121,   110,
      -1,   108,   121,   109,    -1,   109,    -1,   110,    -1,   110,
     124,   110,    -1,   110,    67,   110,    63,   110,    -1,   110,
     122,   110,    -1,    65,   110,    -1,    66,   110,    -1,    75,
     110,    -1,    75,    48,   120,    49,    -1,   123,   110,    -1,
     111,   110,    -1,   112,    -1,    48,   120,    49,    -1,   113,
      -1,   112,    57,   107,    58,    -1,   112,    48,    49,    -1,
     112,    48,   117,    49,    -1,   112,    59,    10,    -1,   112,
      78,    10,    -1,   112,    65,    -1,   112,    66,    -1,    10,
      -1,   118,    -1,    48,   107,    49,    -1,    10,    64,   114,
      -1,    10,   115,    64,   114,    -1,    10,    50,   107,    -1,
      10,    50,   107,    64,   114,    -1,    10,    -1,    10,   115,
      -1,    57,     7,    58,    -1,    10,    48,    49,    -1,    10,
      48,   117,    49,    -1,    10,    64,   117,    -1,    10,    -1,
     118,    64,   117,    -1,   118,    -1,     7,    -1,     8,    -1,
       9,    -1,   120,   119,    -1,   120,    -1,    15,    -1,    19,
      -1,    20,    -1,    25,    -1,    26,    -1,    27,    -1,    28,
      -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,    33,
      -1,    34,    -1,    36,    -1,    37,    -1,    38,    -1,    39,
      -1,    41,    -1,    42,    -1,    79,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,    88,    -1,    50,    -1,    43,    -1,    44,
      -1,    45,    -1,    46,    -1,    47,    -1,    68,    -1,    69,
      -1,    70,    -1,    71,    -1,    72,    -1,    73,    -1,    74,
      -1,    76,    -1,    77,    -1,    68,    -1,    69,    -1,    43,
      -1,    44,    -1,    70,    -1,    45,    -1,    51,    -1,    52,
      -1,    53,    -1,    54,    -1,    55,    -1,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    54,    55,    56,    57,    58,    61,    62,
      65,    68,    71,    71,    72,    72,    75,    75,    76,    79,
      80,    81,    84,    85,    86,    87,    88,    91,    95,    96,
      97,    98,   101,   102,   105,   106,   109,   110,   114,   115,
     116,   117,   121,   122,   123,   124,   125,   128,   129,   130,
     131,   134,   135,   138,   139,   140,   141,   142,   143,   144,
     145,   148,   151,   152,   153,   154,   155,   156,   157,   158,
     161,   162,   163,   166,   167,   168,   169,   170,   171,   174,
     179,   180,   185,   186,   187,   188,   191,   191,   191,   194,
     195,   198,   198,   198,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   200,   200,   200,   200,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   211,
     211,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   216,   216,   219,   220,   221,   222,   223,
     224,   227,   227,   227,   227,   227,   227
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
  "$accept", "File", "Block", "StartScope", "EndScope", "Function", "$@1",
  "$@2", "Parameter", "$@3", "CompoundStatement", "Statement",
  "ExprStatement", "IfStatement", "ElseStatement", "WhileStatement",
  "ForStatement", "ReturnStatement", "Expr", "Assignment",
  "ConditionalExpr", "UnaryExpr", "Cast", "PostFixExpr", "PrimaryExpr",
  "Declaration", "ArrayDecl", "Call", "Argument", "Value", "CompoundType",
  "Type", "OpAssign", "OpManipulate", "OpUnary", "OpCond", 0
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
       0,    89,    90,    90,    90,    90,    90,    90,    91,    91,
      92,    93,    95,    94,    96,    94,    98,    97,    97,    99,
      99,    99,   100,   100,   100,   100,   100,   101,   102,   102,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     106,   106,   107,   107,   107,   107,   107,   108,   108,   108,
     108,   109,   109,   110,   110,   110,   110,   110,   110,   110,
     110,   111,   112,   112,   112,   112,   112,   112,   112,   112,
     113,   113,   113,   114,   114,   114,   114,   114,   114,   115,
     116,   116,   117,   117,   117,   117,   118,   118,   118,   119,
     119,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   123,   123,   123,   123,   123,
     123,   124,   124,   124,   124,   124,   124
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     1,     1,     1,     3,     2,
       1,     1,     0,     7,     0,     6,     0,     5,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     2,     5,     5,
       6,     6,     2,     2,     5,     5,     7,     7,     3,     3,
       2,     3,     2,     3,     3,     1,     1,     3,     3,     1,
       1,     3,     5,     3,     2,     2,     2,     4,     2,     2,
       1,     3,     1,     4,     3,     4,     3,     3,     2,     2,
       1,     1,     3,     3,     4,     3,     5,     1,     2,     3,
       3,     4,     3,     1,     3,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    86,    87,    88,    70,     0,     0,    91,     0,     0,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   137,   138,
     140,     0,    10,     0,     0,   135,   136,   139,     0,     0,
       7,     0,     6,     5,    22,    23,    24,    25,    26,     0,
      45,    49,    50,     0,    60,    62,    46,    71,     0,    90,
       0,     0,     0,     0,     0,    70,    40,     0,    71,     0,
       0,    90,    70,    54,    55,     0,    56,     1,     4,    11,
       0,     9,     0,    21,     3,     2,    27,     0,   120,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     121,   122,   123,   124,   125,   141,   142,   143,   144,   145,
     146,     0,   126,   127,   128,   129,   130,   131,   132,   133,
     134,     0,     0,    59,     0,     0,     0,    68,    69,     0,
      77,     0,    42,    89,    58,    83,    80,     0,    85,     0,
       0,     0,    41,    38,    39,    77,    72,    61,    90,    19,
       8,    20,    44,    48,    47,     0,    53,    51,    64,     0,
       0,    66,    67,    12,     0,     0,     0,    78,    43,     0,
      81,     0,     0,     0,     0,    57,     0,    65,    63,     0,
       0,    75,     0,    73,     0,    82,    84,     0,    29,    28,
      35,    34,    52,     0,     0,     0,     0,    79,    74,     0,
       0,    31,    30,     0,    16,    15,    70,    76,    37,    36,
      33,    32,    13,     0,     0,    17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    39,    40,    41,    81,    42,   179,   180,   193,   213,
      82,    43,    44,    45,   201,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,   132,   167,    56,   137,    57,
      69,    59,    99,   121,    60,   122
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -119
static const yytype_int16 yypact[] =
{
     238,  -119,  -119,  -119,   -10,    -3,    14,  -119,    35,   302,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,   366,  -119,    20,    20,  -119,  -119,  -119,   380,    21,
     238,   174,   238,   238,  -119,  -119,  -119,  -119,  -119,    63,
      19,  -119,   441,    20,    65,  -119,  -119,  -119,    -4,   597,
      20,     8,   366,   366,   366,   -23,  -119,    74,   -18,     2,
     -38,   501,  -119,   537,   537,   366,   537,  -119,  -119,  -119,
     238,  -119,    13,   238,  -119,  -119,  -119,    20,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,    20,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,    20,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,    20,    20,   537,    26,   366,    84,  -119,  -119,    87,
      62,   105,  -119,  -119,   537,    52,  -119,    71,    73,   366,
     -27,    23,  -119,  -119,  -119,    64,  -119,  -119,   526,  -119,
    -119,  -119,    19,  -119,   441,   527,   537,   537,  -119,    80,
     -44,  -119,  -119,    92,   366,    77,   105,    82,  -119,   125,
    -119,   125,   366,   238,   238,    43,    20,  -119,  -119,   597,
     100,    86,    95,  -119,   105,  -119,  -119,    32,   140,   140,
    -119,  -119,   537,   106,   147,    98,   408,  -119,  -119,   238,
     238,  -119,  -119,    98,   110,  -119,    64,  -119,  -119,  -119,
    -119,  -119,  -119,    96,   597,  -119
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -119,   102,   -34,  -119,    81,  -119,  -119,  -119,   -52,  -119,
      -7,   -22,   -59,  -119,   -17,  -119,  -119,  -119,    -8,   -85,
      68,   -29,  -119,  -119,  -119,  -118,  -119,  -119,   -92,    -1,
       0,   -21,  -119,  -119,  -119,  -119
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -62
static const yytype_int16 yytable[] =
{
      58,    67,   152,   139,    73,    74,   130,    80,    68,    76,
      71,   146,   145,   168,   178,     1,     2,     3,   135,    83,
      87,    77,   173,    70,   123,    61,    87,     1,     2,     3,
      72,   134,   159,     1,     2,     3,   135,    87,    61,   142,
      58,   131,    58,    58,   144,    62,    80,   131,   183,    80,
     -61,   -61,   -61,   -61,   148,   140,   141,   136,    83,   133,
     138,    83,    63,    28,    29,    30,   198,    70,    31,    88,
     154,   133,   174,   149,    79,   158,   151,   185,   207,   186,
     172,   199,   155,    64,   182,    33,    34,    87,    35,    36,
      37,   -61,   156,   157,   161,    38,    87,   162,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   -61,   -61,
     163,   152,   164,   124,   164,   145,   169,   160,   -61,   165,
     170,   165,   125,   138,   126,    86,   166,    87,   166,   177,
     127,   128,     1,     2,     3,   135,   143,   171,    87,   188,
     190,   -14,    78,   129,    84,    85,   184,   192,   133,   195,
     196,   189,   191,   197,   200,   203,   181,   204,    32,   -18,
     214,   205,   215,   150,   187,   208,   210,   153,   138,   212,
     138,     0,   202,     0,     0,     0,     0,   209,   211,   194,
       0,     1,     2,     3,     4,     0,     5,     6,     0,     7,
       8,     0,     9,    10,    11,     0,     0,     0,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
      22,    23,    24,    25,   194,    26,    27,    28,    29,    30,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    79,     0,     0,     0,    33,
      34,     0,    35,    36,    37,     1,     2,     3,     4,    38,
       5,     6,     0,     7,     8,     0,     9,    10,    11,     0,
       0,     0,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,    22,    23,    24,    25,     0,    26,
      27,    28,    29,    30,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,     0,
       0,     0,     0,    33,    34,     0,    35,    36,    37,     1,
       2,     3,    65,    38,     0,     0,     0,     7,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    66,     0,     0,    33,    34,     0,
      35,    36,    37,     1,     2,     3,     4,    38,     0,     0,
       0,     7,     0,     0,     0,    10,    11,     1,     2,     3,
      72,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,    22,    23,    24,    25,     0,    26,    27,    28,
      29,    30,     0,     0,    31,     1,     2,     3,   206,     0,
       0,     0,     0,    28,    29,    30,     0,     0,    75,     0,
       0,    33,    34,     0,    35,    36,    37,     0,     0,     0,
       0,    38,     0,     0,     0,    33,    34,     0,    35,    36,
      37,    28,    29,    30,     0,    38,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,     0,    35,    36,    37,     0,
       0,     0,     0,    38,   100,   101,   102,   103,   104,     0,
       0,     0,   105,   106,   107,   108,   109,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     7,   119,   120,     0,
      10,    11,     0,     0,     0,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,    22,    23,    24,
      25,     7,    26,    27,     0,    10,    11,     0,     0,     0,
     147,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,    22,    23,    24,    25,     0,    26,    27,     0,
     100,   101,   102,   103,   104,   175,     0,     0,     0,     0,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
     176,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,     0,   119,   120,   112,   113,   114,   115,   116,
     117,   118,     7,   119,   120,     0,    10,    11,     0,     0,
       0,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,    22,    23,    24,    25,     0,    26,    27
};

static const yytype_int16 yycheck[] =
{
       0,     9,    87,    62,    33,    34,    10,    41,     9,    38,
      31,    49,    10,   131,    58,     7,     8,     9,    10,    41,
      64,     0,    49,    31,    53,    48,    64,     7,     8,     9,
      10,    60,   124,     7,     8,     9,    10,    64,    48,    62,
      40,    45,    42,    43,    62,    48,    80,    45,   166,    83,
       7,     8,     9,    10,    75,    63,    64,    49,    80,    59,
      61,    83,    48,    43,    44,    45,   184,    75,    48,    50,
      99,    71,    49,    80,    61,    49,    83,   169,   196,   171,
     139,    49,   111,    48,     7,    65,    66,    64,    68,    69,
      70,    48,   121,   122,    10,    75,    64,    10,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    65,    66,
      48,   196,    50,    48,    50,    10,    64,   125,    75,    57,
      49,    57,    57,   124,    59,    62,    64,    64,    64,    49,
      65,    66,     7,     8,     9,    10,    62,    64,    64,   173,
     174,    49,    40,    78,    42,    43,    64,   176,   148,    49,
      64,   173,   174,    58,    14,    49,   164,    10,    60,    49,
      64,   195,   214,    82,   172,   199,   200,    99,   169,   203,
     171,    -1,   189,    -1,    -1,    -1,    -1,   199,   200,   179,
      -1,     7,     8,     9,    10,    -1,    12,    13,    -1,    15,
      16,    -1,    18,    19,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,   214,    41,    42,    43,    44,    45,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    65,
      66,    -1,    68,    69,    70,     7,     8,     9,    10,    75,
      12,    13,    -1,    15,    16,    -1,    18,    19,    20,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    41,
      42,    43,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    70,     7,
       8,     9,    10,    75,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    45,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    65,    66,    -1,
      68,    69,    70,     7,     8,     9,    10,    75,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    19,    20,     7,     8,     9,
      10,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    45,    -1,    -1,    48,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    43,    44,    45,    -1,    -1,    48,    -1,
      -1,    65,    66,    -1,    68,    69,    70,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    -1,    65,    66,    -1,    68,    69,
      70,    43,    44,    45,    -1,    75,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    70,    -1,
      -1,    -1,    -1,    75,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    15,    76,    77,    -1,
      19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    15,    41,    42,    -1,    19,    20,    -1,    -1,    -1,
      49,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    41,    42,    -1,
      43,    44,    45,    46,    47,    49,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    68,    69,    70,    71,    72,
      73,    74,    15,    76,    77,    -1,    19,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    36,    37,    38,    39,    -1,    41,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    12,    13,    15,    16,    18,
      19,    20,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    36,    37,    38,    39,    41,    42,    43,    44,
      45,    48,    60,    65,    66,    68,    69,    70,    75,    90,
      91,    92,    94,   100,   101,   102,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   116,   118,   119,   120,
     123,    48,    48,    48,    48,    10,    62,   107,   118,   119,
     107,   120,    10,   110,   110,    48,   110,     0,    90,    61,
      91,    93,    99,   100,    90,    90,    62,    64,    50,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   121,
      43,    44,    45,    46,    47,    51,    52,    53,    54,    55,
      56,    67,    68,    69,    70,    71,    72,    73,    74,    76,
      77,   122,   124,   110,    48,    57,    59,    65,    66,    78,
      10,    45,   114,   119,   110,    10,    49,   117,   118,   101,
     107,   107,    62,    62,    62,    10,    49,    49,   120,    99,
      93,    99,   108,   109,   110,   110,   110,   110,    49,   117,
     107,    10,    10,    48,    50,    57,    64,   115,   114,    64,
      49,    64,   101,    49,    49,    49,    63,    49,    58,    95,
      96,   107,     7,   114,    64,   117,   117,   107,    91,   100,
      91,   100,   110,    97,   119,    49,    64,    58,   114,    49,
      14,   103,   103,    49,    10,    91,    10,   114,    91,   100,
      91,   100,    91,    98,    64,    97
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
        case 10:

/* Line 1464 of yacc.c  */
#line 65 "src/c_parser.y"
    {indent(n); cout << "SCOPE" << endl; n++;;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 68 "src/c_parser.y"
    {n--;;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 71 "src/c_parser.y"
    {indent(n); cout << "FUNCTION : " << (yyvsp[(2) - (3)].str) << endl;;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 72 "src/c_parser.y"
    {indent(n); cout << "FUNCTION : " << (yyvsp[(2) - (3)].str) << endl;;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 75 "src/c_parser.y"
    {indent(n); cout << "    PARAMETER : " << (yyvsp[(2) - (2)].str) << endl;;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 76 "src/c_parser.y"
    {indent(n); cout << "    PARAMETER : " << (yyvsp[(2) - (2)].str) << endl;;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 166 "src/c_parser.y"
    {indent(n); cout << "VARIABLE : " << (yyvsp[(1) - (3)].str) << endl;;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 167 "src/c_parser.y"
    {indent(n); cout << "VARIABLE : " << (yyvsp[(1) - (4)].str) << endl;;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 168 "src/c_parser.y"
    {indent(n); cout << "VARIABLE : " << (yyvsp[(1) - (3)].str) << endl;;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 169 "src/c_parser.y"
    {indent(n); cout << "VARIABLE : " << (yyvsp[(1) - (5)].str) << endl;;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 170 "src/c_parser.y"
    {indent(n); cout << "VARIABLE : " << (yyvsp[(1) - (1)].str) << endl;;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 171 "src/c_parser.y"
    {indent(n); cout << "VARIABLE : " << (yyvsp[(1) - (2)].str) << endl;;}
    break;



/* Line 1464 of yacc.c  */
#line 1828 "bin/c_parser.tab.c"
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
#line 236 "src/c_parser.y"


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

