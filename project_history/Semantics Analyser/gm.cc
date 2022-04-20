
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

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
#line 1 "semantic_analyser.y"

	#include <fstream>
	#include <iostream>
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	#include <vector>
	#include <fstream>

	using namespace std;

	extern FILE *yyin;

	extern "C"
	{
		// int yyparse(void);
		int yylex();
		void yyerror(const char* s) {
			fprintf (stderr, "%s\n", s);
			exit(EXIT_SUCCESS);
		}
		int yywrap() {
			return 1;
		}
	}
	int DEBUG_CODE = 1;

	string TAC = "";


/* Line 189 of yacc.c  */
#line 105 "gm.cc"

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
     MAIN = 258,
     VOID = 259,
     RETURN = 260,
     INT = 261,
     FLOAT = 262,
     CHAR = 263,
     BOOLEAN = 264,
     IF = 265,
     ELIF = 266,
     ELSE = 267,
     LOOP = 268,
     BREAK = 269,
     CONTINUE = 270,
     IDENTIFIER = 271,
     BOOLEAN_LIT = 272,
     FLOAT_LIT = 273,
     INT_LIT = 274,
     CHAR_LIT = 275,
     SEMICOLON = 276,
     COMMA = 277,
     LP = 278,
     RP = 279,
     LC = 280,
     RC = 281,
     ADD_ASSIGN_OP = 282,
     SUB_ASSIGN_OP = 283,
     MUL_ASSIGN_OP = 284,
     DIV_ASSIGN_OP = 285,
     REM_ASSIGN_OP = 286,
     EQUAL_OP = 287,
     NOT_EQUAL_OP = 288,
     MRTE = 289,
     LSTE = 290,
     MRT = 291,
     LST = 292,
     LOGICAL_AND_OP = 293,
     LOGICAL_OR_OP = 294,
     EXCLAMATION_OP = 295,
     ASSIGN_OP = 296,
     ADD_OP = 297,
     SUB_OP = 298,
     MUL_OP = 299,
     DIV_OP = 300,
     REM_OP = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 193 "gm.cc"

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
# if YYENABLE_NLS
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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   194

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNRULES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    12,    14,    17,    23,    30,
      36,    43,    45,    49,    52,    55,    59,    61,    64,    67,
      70,    72,    74,    77,    79,    82,    84,    88,    92,    98,
     100,   102,   106,   110,   114,   118,   122,   126,   128,   132,
     134,   138,   140,   144,   148,   150,   154,   158,   162,   166,
     168,   172,   176,   178,   182,   186,   190,   192,   195,   197,
     200,   203,   207,   213,   219,   226,   229,   235,   238,   240,
     244,   246,   248,   250,   252,   254,   256,   260,   265,   267,
     271,   273,   275,   277
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    -1,     3,    54,    -1,    50,     3,
      54,    -1,    51,    -1,    50,    51,    -1,     4,    16,    23,
      24,    54,    -1,     4,    16,    23,    52,    24,    54,    -1,
      78,    16,    23,    24,    54,    -1,    78,    16,    23,    52,
      24,    54,    -1,    53,    -1,    52,    22,    53,    -1,    78,
      16,    -1,    25,    26,    -1,    25,    55,    26,    -1,    56,
      -1,    55,    56,    -1,    57,    21,    -1,    59,    21,    -1,
      68,    -1,    72,    -1,    73,    21,    -1,    21,    -1,    78,
      58,    -1,    16,    -1,    16,    41,    59,    -1,    58,    22,
      16,    -1,    58,    22,    16,    41,    59,    -1,    60,    -1,
      61,    -1,    16,    41,    61,    -1,    16,    27,    61,    -1,
      16,    28,    61,    -1,    16,    29,    61,    -1,    16,    30,
      61,    -1,    16,    31,    61,    -1,    62,    -1,    61,    39,
      62,    -1,    63,    -1,    62,    38,    63,    -1,    64,    -1,
      63,    32,    64,    -1,    63,    33,    64,    -1,    65,    -1,
      64,    37,    65,    -1,    64,    35,    65,    -1,    64,    36,
      65,    -1,    64,    34,    65,    -1,    66,    -1,    65,    42,
      66,    -1,    65,    43,    66,    -1,    67,    -1,    66,    44,
      67,    -1,    66,    45,    67,    -1,    66,    46,    67,    -1,
      74,    -1,    40,    74,    -1,    69,    -1,    69,    71,    -1,
      69,    70,    -1,    69,    70,    71,    -1,    10,    23,    61,
      24,    54,    -1,    11,    23,    61,    24,    54,    -1,    11,
      23,    61,    24,    54,    70,    -1,    12,    54,    -1,    13,
      23,    61,    24,    54,    -1,     5,    61,    -1,    75,    -1,
      23,    61,    24,    -1,    17,    -1,    18,    -1,    19,    -1,
      20,    -1,    76,    -1,    16,    -1,    16,    23,    24,    -1,
      16,    23,    77,    24,    -1,    75,    -1,    77,    22,    75,
      -1,     6,    -1,     7,    -1,     8,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    45,    45,    52,    58,    65,    71,    78,    84,    90,
      96,   103,   109,   116,   123,   129,   136,   142,   149,   155,
     161,   167,   173,   179,   186,   193,   199,   205,   211,   218,
     224,   231,   237,   243,   249,   255,   261,   268,   274,   281,
     287,   294,   300,   306,   313,   319,   325,   331,   337,   344,
     350,   356,   363,   369,   375,   381,   388,   394,   401,   407,
     413,   419,   426,   433,   439,   446,   453,   460,   467,   473,
     479,   485,   491,   497,   503,   509,   516,   522,   529,   535,
     542,   548,   554,   560
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "VOID", "RETURN", "INT", "FLOAT",
  "CHAR", "BOOLEAN", "IF", "ELIF", "ELSE", "LOOP", "BREAK", "CONTINUE",
  "IDENTIFIER", "BOOLEAN_LIT", "FLOAT_LIT", "INT_LIT", "CHAR_LIT",
  "SEMICOLON", "COMMA", "LP", "RP", "LC", "RC", "ADD_ASSIGN_OP",
  "SUB_ASSIGN_OP", "MUL_ASSIGN_OP", "DIV_ASSIGN_OP", "REM_ASSIGN_OP",
  "EQUAL_OP", "NOT_EQUAL_OP", "MRTE", "LSTE", "MRT", "LST",
  "LOGICAL_AND_OP", "LOGICAL_OR_OP", "EXCLAMATION_OP", "ASSIGN_OP",
  "ADD_OP", "SUB_OP", "MUL_OP", "DIV_OP", "REM_OP", "$accept",
  "program_start", "program", "functions", "function_declaration",
  "params", "param", "block", "statement_list", "statement",
  "variable_declaration", "variable_list", "expression",
  "assign_expression", "op_or_expression", "op_and_expression",
  "op_rel_expression", "op_condt_expression", "op_additive_expression",
  "op_multiplicative_expression", "op_neg_expression",
  "conditional_statement", "simple_if", "ladder_elif", "simple_else",
  "loop_statement", "return_statement", "factor", "term",
  "functional_call", "args", "data_type", 0
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    51,    51,
      51,    52,    52,    53,    54,    54,    55,    55,    56,    56,
      56,    56,    56,    56,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    60,    60,    60,    60,    61,    61,    62,
      62,    63,    63,    63,    64,    64,    64,    64,    64,    65,
      65,    65,    66,    66,    66,    66,    67,    67,    68,    68,
      68,    68,    69,    70,    70,    71,    72,    73,    74,    74,
      75,    75,    75,    75,    75,    75,    76,    76,    77,    77,
      78,    78,    78,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     1,     2,     5,     6,     5,
       6,     1,     3,     2,     2,     3,     1,     2,     2,     2,
       1,     1,     2,     1,     2,     1,     3,     3,     5,     1,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     2,     1,     2,
       2,     3,     5,     5,     6,     2,     5,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     4,     1,     3,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    80,    81,    82,    83,     0,     2,     0,
       5,     0,     0,     3,     0,     1,     0,     6,     0,     0,
       0,     0,    75,    70,    71,    72,    73,    23,     0,    14,
       0,     0,    16,     0,     0,    29,    30,    37,    39,    41,
      44,    49,    52,    20,    58,    21,     0,    56,    68,    74,
       0,     0,     4,     0,    75,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    57,    15,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,    59,    22,    25,
      24,     0,     0,    11,     0,     0,     0,     0,     0,    76,
      78,     0,    32,    33,    34,    35,    36,    31,    69,    38,
      40,    42,    43,    48,    46,    47,    45,    50,    51,    53,
      54,    55,     0,    65,    61,     0,     0,     7,     0,     0,
      13,     9,     0,     0,     0,     0,    77,     0,    26,    27,
      12,     8,    10,    62,    66,    79,     0,     0,    63,    28,
      64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    92,    93,    13,    31,    32,
      33,    90,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    86,    87,    45,    46,    47,    48,    49,
     101,    94
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -119
static const yytype_int16 yypact[] =
{
     152,   -23,    -8,  -119,  -119,  -119,  -119,    11,  -119,   159,
    -119,    39,     7,  -119,    25,  -119,   -23,  -119,    36,    69,
      43,    45,    97,  -119,  -119,  -119,  -119,  -119,    69,  -119,
     134,    44,  -119,    61,    90,  -119,    64,    76,   -27,   140,
     -11,   -10,  -119,  -119,    82,  -119,    94,  -119,  -119,  -119,
     105,    99,  -119,   125,   106,    64,    69,    69,   123,    69,
      69,    69,    69,    69,    69,   -20,  -119,  -119,  -119,  -119,
    -119,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,   112,   -23,   110,  -119,  -119,    95,
     115,   -23,    50,  -119,   128,   -23,    59,    -2,    32,  -119,
    -119,    88,    64,    64,    64,    64,    64,    64,  -119,    76,
     -27,   140,   140,   -11,   -11,   -11,   -11,   -10,   -10,  -119,
    -119,  -119,    69,  -119,  -119,    79,   129,  -119,   172,   -23,
    -119,  -119,   -23,   -23,   -23,   153,  -119,    34,  -119,   145,
    -119,  -119,  -119,  -119,  -119,  -119,   -23,    79,   135,  -119,
    -119
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,  -119,  -119,   139,   111,    60,   -16,  -119,   156,
    -119,  -119,  -118,  -119,   -18,   118,   119,    17,   107,    21,
      -5,  -119,  -119,    42,   108,  -119,  -119,   162,   -55,  -119,
    -119,     9
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      52,    55,    12,   100,   108,    73,    74,   138,    14,    11,
      65,    15,    19,     3,     4,     5,     6,    20,    11,    71,
      21,    50,   133,    22,    23,    24,    25,    26,    27,   149,
      28,    79,    80,    29,    81,    82,    83,    71,    97,    98,
      50,   102,   103,   104,   105,   106,   107,    30,    51,    19,
       3,     4,     5,     6,    20,    18,   134,    21,   146,    53,
      22,    23,    24,    25,    26,    27,    56,    28,    57,   123,
      67,    71,   128,    71,   129,   127,   119,   120,   121,   131,
     145,   128,    69,   132,    30,    54,    23,    24,    25,    26,
     111,   112,    28,    84,    85,    22,    23,    24,    25,    26,
     117,   118,    28,    71,   137,     3,     4,     5,     6,    30,
     135,    70,   136,   141,    72,    88,   142,   143,   144,    30,
      58,    89,    85,    91,    59,    60,    61,    62,    63,    58,
     148,     3,     4,     5,     6,   122,   125,   126,    64,    54,
      23,    24,    25,    26,   130,   139,    84,    99,    17,    95,
      54,    23,    24,    25,    26,     1,     2,    28,     3,     4,
       5,     6,    16,     2,    96,     3,     4,     5,     6,    54,
      23,    24,    25,    26,    75,    76,    77,    78,     3,     4,
       5,     6,   113,   114,   115,   116,   147,    68,   140,   109,
     150,   110,    66,     0,   124
};

static const yytype_int16 yycheck[] =
{
      16,    19,    25,    58,    24,    32,    33,   125,    16,     0,
      28,     0,     5,     6,     7,     8,     9,    10,     9,    39,
      13,    12,    24,    16,    17,    18,    19,    20,    21,   147,
      23,    42,    43,    26,    44,    45,    46,    39,    56,    57,
      31,    59,    60,    61,    62,    63,    64,    40,    23,     5,
       6,     7,     8,     9,    10,    16,    24,    13,    24,    23,
      16,    17,    18,    19,    20,    21,    23,    23,    23,    85,
      26,    39,    22,    39,    24,    91,    81,    82,    83,    95,
     135,    22,    21,    24,    40,    16,    17,    18,    19,    20,
      73,    74,    23,    11,    12,    16,    17,    18,    19,    20,
      79,    80,    23,    39,   122,     6,     7,     8,     9,    40,
      22,    21,    24,   129,    38,    21,   132,   133,   134,    40,
      23,    16,    12,    24,    27,    28,    29,    30,    31,    23,
     146,     6,     7,     8,     9,    23,    41,    22,    41,    16,
      17,    18,    19,    20,    16,    16,    11,    24,     9,    24,
      16,    17,    18,    19,    20,     3,     4,    23,     6,     7,
       8,     9,     3,     4,    53,     6,     7,     8,     9,    16,
      17,    18,    19,    20,    34,    35,    36,    37,     6,     7,
       8,     9,    75,    76,    77,    78,    41,    31,   128,    71,
     148,    72,    30,    -1,    86
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,     8,     9,    48,    49,    50,
      51,    78,    25,    54,    16,     0,     3,    51,    16,     5,
      10,    13,    16,    17,    18,    19,    20,    21,    23,    26,
      40,    55,    56,    57,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    72,    73,    74,    75,    76,
      78,    23,    54,    23,    16,    61,    23,    23,    23,    27,
      28,    29,    30,    31,    41,    61,    74,    26,    56,    21,
      21,    39,    38,    32,    33,    34,    35,    36,    37,    42,
      43,    44,    45,    46,    11,    12,    70,    71,    21,    16,
      58,    24,    52,    53,    78,    24,    52,    61,    61,    24,
      75,    77,    61,    61,    61,    61,    61,    61,    24,    62,
      63,    64,    64,    65,    65,    65,    65,    66,    66,    67,
      67,    67,    23,    54,    71,    41,    22,    54,    22,    24,
      16,    54,    24,    24,    24,    22,    24,    61,    59,    16,
      53,    54,    54,    54,    54,    75,    24,    41,    54,    59,
      70
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

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
# if YYLTYPE_IS_TRIVIAL
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

/* Line 1455 of yacc.c  */
#line 46 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("program_start\n");
				;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 53 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("program 1\n");
			;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 59 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("program 2\n");
			;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 66 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("functions 1\n");
				;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 72 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("functions 2\n");
				;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 79 "semantic_analyser.y"
    {
							if(DEBUG_CODE == 1)
								printf("function_declaration 1\n");
						;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 85 "semantic_analyser.y"
    {
							if(DEBUG_CODE == 1)
								printf("function_declaration 2\n");
						;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 91 "semantic_analyser.y"
    {
							if(DEBUG_CODE == 1)
								printf("function_declaration 3\n");
						;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 97 "semantic_analyser.y"
    {
							if(DEBUG_CODE == 1)
								printf("function_declaration 4\n");
						;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 104 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("params 2\n");
			;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 110 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("params 2\n");
			;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 117 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("param \n");
			;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 124 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("block 1\n");
			;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 130 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("block 2\n");
			;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 137 "semantic_analyser.y"
    {
						if(DEBUG_CODE == 1)
							printf("statement_list 1\n");
					;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 143 "semantic_analyser.y"
    {
						if(DEBUG_CODE == 1)
							printf("statement_list 2\n");
					;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 150 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("statement 1\n");
				;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 156 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("statement 2\n");
				;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 162 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("statement 3\n");
				;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 168 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("statement 4\n");
				;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 174 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("statement 5\n");
				;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 180 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("statement 6\n");
				;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 187 "semantic_analyser.y"
    {
							if(DEBUG_CODE == 1)
								printf("variable_declaration \n");
						;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 194 "semantic_analyser.y"
    {
						if(DEBUG_CODE == 1)
							printf("variable_list 1 ");
					;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 200 "semantic_analyser.y"
    {
						if(DEBUG_CODE == 1)
							printf("variable_list 2 ");
					;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 206 "semantic_analyser.y"
    {
						if(DEBUG_CODE == 1)
							printf("variable_list 3 ");
					;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 212 "semantic_analyser.y"
    {
						if(DEBUG_CODE == 1)
							printf("variable_list 4 ");
					;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 219 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("expression 1 ");
				;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 225 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("expression 2 ");
				;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 232 "semantic_analyser.y"
    {
							if(DEBUG_CODE == 1)
								printf("assign_expression 1 ");
						;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 238 "semantic_analyser.y"
    {
							if(DEBUG_CODE == 1)
								printf("assign_expression 2 ");
						;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 244 "semantic_analyser.y"
    {
							if(DEBUG_CODE == 1)
								printf("assign_expression 3 ");
						;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 250 "semantic_analyser.y"
    {
							if(DEBUG_CODE == 1)
								printf("assign_expression 4 ");
						;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 256 "semantic_analyser.y"
    {
							if(DEBUG_CODE == 1)
								printf("assign_expression 5 ");
						;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 262 "semantic_analyser.y"
    {
							if(DEBUG_CODE == 1)
								printf("assign_expression 6 ");
						;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 269 "semantic_analyser.y"
    {
                        if(DEBUG_CODE == 1)
							printf("op_or_expression 1 ");
                    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 275 "semantic_analyser.y"
    {
                        if(DEBUG_CODE == 1)
							printf("op_or_expression 2 ");
                    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 282 "semantic_analyser.y"
    {
                            if(DEBUG_CODE == 1)
								printf("op_and_expression 1 ");
                        ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 288 "semantic_analyser.y"
    {
                            if(DEBUG_CODE == 1)
								printf("op_and_expression 2 ");
                        ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 295 "semantic_analyser.y"
    {
                            if(DEBUG_CODE == 1)
								printf("op_rel_expression 1 ");
                        ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 301 "semantic_analyser.y"
    {
                            if(DEBUG_CODE == 1)
								printf("op_rel_expression 2 ");
                        ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 307 "semantic_analyser.y"
    {
                            if(DEBUG_CODE == 1)
								printf("op_rel_expression 3 ");
                        ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 314 "semantic_analyser.y"
    {
                            if(DEBUG_CODE == 1)
								printf("op_condt_expression 1 ");
                        ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 320 "semantic_analyser.y"
    {
                            if(DEBUG_CODE == 1)
								printf("op_condt_expression 2 ");
                        ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 326 "semantic_analyser.y"
    {
                            if(DEBUG_CODE == 1)
								printf("op_condt_expression 3 ");
                        ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 332 "semantic_analyser.y"
    {
                            if(DEBUG_CODE == 1)
								printf("op_condt_expression 4 ");
                        ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 338 "semantic_analyser.y"
    {
                            if(DEBUG_CODE == 1)
								printf("op_condt_expression 5 ");
                        ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 345 "semantic_analyser.y"
    {
                                if(DEBUG_CODE == 1)
									printf("op_additive_expression 1 ");
                            ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 351 "semantic_analyser.y"
    {
                                if(DEBUG_CODE == 1)
									printf("op_additive_expression 2 ");
                            ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 357 "semantic_analyser.y"
    {
                                if(DEBUG_CODE == 1)
									printf("op_additive_expression 3 ");
                            ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 364 "semantic_analyser.y"
    {
                                        if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 1 ");
                                    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 370 "semantic_analyser.y"
    {
                                        if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 2 ");
                                    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 376 "semantic_analyser.y"
    {
                                        if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 3 ");
                                    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 382 "semantic_analyser.y"
    {
                                        if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 4 ");
                                    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 389 "semantic_analyser.y"
    {
                            if(DEBUG_CODE == 1)
								printf("op_neg_expression 1 ");
                        ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 395 "semantic_analyser.y"
    {
                            if(DEBUG_CODE == 1)
								printf("op_neg_expression 2 ");
                        ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 402 "semantic_analyser.y"
    {
								if(DEBUG_CODE == 1)
									printf("conditional_statement 1 ");
							;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 408 "semantic_analyser.y"
    {
								if(DEBUG_CODE == 1)
									printf("conditional_statement 2 ");
							;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 414 "semantic_analyser.y"
    {
								if(DEBUG_CODE == 1)
									printf("conditional_statement 3 ");
							;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 420 "semantic_analyser.y"
    {
								if(DEBUG_CODE == 1)
									printf("conditional_statement 4 ");
							;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 427 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("simple_if ");
				;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 434 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("ladder_elif 1 ");
				;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 440 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("ladder_elif 2 ");
				;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 447 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("simple_else ");
				;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 454 "semantic_analyser.y"
    {
						if(DEBUG_CODE == 1)
							printf("loop_statement ");
					;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 461 "semantic_analyser.y"
    {
						if(DEBUG_CODE == 1)
							printf("return_statement ");
					;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 468 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("factor 1 ");
			;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 474 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("factor 2 ");
			;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 480 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("term 1 ");
			;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 486 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("term 2 ");
			;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 492 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("term 3 ");
			;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 498 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("term 4 ");
			;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 504 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("term 5 ");
			;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 510 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("term 6 ");
			;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 517 "semantic_analyser.y"
    {
						if(DEBUG_CODE == 1)
							printf("functional_call 1 ");
					;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 523 "semantic_analyser.y"
    {
						if(DEBUG_CODE == 1)
							printf("functional_call 2 ");
					;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 530 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("args 1 ");
			;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 536 "semantic_analyser.y"
    {
				if(DEBUG_CODE == 1)
					printf("args 2 ");
			;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 543 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("data_type 1 ");
				;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 549 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("data_type 2 ");
				;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 555 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("data_type 3 ");
				;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 561 "semantic_analyser.y"
    {
					if(DEBUG_CODE == 1)
						printf("data_type 4 ");
				;}
    break;



/* Line 1455 of yacc.c  */
#line 2362 "gm.cc"
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



/* Line 1675 of yacc.c  */
#line 566 "semantic_analyser.y"


// ./parser ./exmp/arithmetic.xvgs
int main(int argc, char *argv[]) {
    if(argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if(fp)
           yyin = fp;
		else
			printf("Error opening file\n");
    }

    yyparse();
	// printf("Hello\n");
    return 0;
}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 
