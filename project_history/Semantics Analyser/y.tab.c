
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
	#include <stack>
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

	// DEBUG CODE 
	int DEBUG_CODE = 1;

	// THREE ADDRESS CODE
	string TAC = "";

	// IMPORTANT GLOBAL VARIABLES
	int DATA_TYPE = 0;
	int SCOPE = 0;
	int FUNCTION = 1;
	int NARGS = 0;
	stack<int> currentScope;

	// SYMBOL TABLE
	class SymbolTableNode {
		public:
			string IDEN;
			int type;
			int scopeIn;
			int scope;
			int fIndex;

			SymbolTableNode(string iden, int tp, int scpIn, int scp, int fInd) {
				IDEN = iden;
				type = tp;
				scopeIn = scpIn;
				scope = scp;
				fIndex = fInd;
			}
	};

	class FunctionTableNode {
		public:
			string IDEN;
			int returnType;
			int nArgs;
			int fnIndex;

			FunctionTableNode(string iden, int rtp, int nargs, int fInd) {
				IDEN = iden;
				returnType = rtp;
				nArgs = nargs;
				fnIndex = fInd;
			}
	};

	class SymbolTable {
		private:
			vector<SymbolTableNode> internalSymbolTable;
			vector<FunctionTableNode> internalFunctionTable;

		public:
			SymbolTable() {

			}

			bool functionIDENExists(string IDEN) {
				int n = internalFunctionTable.size();
				for(int i = 0; i < n; i++) {
					if(IDEN.compare(internalFunctionTable[i].IDEN) == 0)
						return true;
				}
				
				n = internalSymbolTable.size();
				for(int i = 0; i < n; i++) {
					if(IDEN.compare(internalSymbolTable[i].IDEN) == 0)
						return true;
				}
				return false;
			}

			bool IDENExists(string IDEN, int scopeIn) {
				int n = internalFunctionTable.size();
				for(int i = 0; i < n; i++) {
					if(IDEN.compare(internalFunctionTable[i].IDEN) == 0)
						return true;
				}

				n = internalSymbolTable.size();
				for(int i = 0; i < n; i++) {
					if(IDEN.compare(internalSymbolTable[i].IDEN) == 0 
					&& scopeIn == internalSymbolTable[i].scopeIn)
						return true;
				}
				return false;
			}

			int addIDEN(string IDEN, int type, int scopeIn, int scope, int fIndex, bool isFun) {
				if(isFun) {
					// type: return type
					// scope: nargs
					if(functionIDENExists(IDEN))
						return -1;
					FunctionTableNode ftn(IDEN, type, scope, fIndex);
					internalFunctionTable.push_back(ftn);
					return 1;
				}
				else {
					if(IDENExists(IDEN, scopeIn))
						return -1;
					SymbolTableNode stn(IDEN, type, scopeIn, scope, fIndex);
					internalSymbolTable.push_back(stn);
					return 1;
				}
			}

			void printTable() {
				int n = internalSymbolTable.size();
				cout << "\nSYMBOL TABLE\n";
				cout << "IDEN\t| TYPE\t| SCPIN\t| SCOPE\t| FINDEX\n";
				cout << "--------|-------|-------|-------|--------\n";
				for(int i = 0; i < n; i++) {
					cout << internalSymbolTable[i].IDEN << "\t| "
						<< internalSymbolTable[i].type << "\t| "
						<< internalSymbolTable[i].scopeIn << "\t| "
						<< internalSymbolTable[i].scope << "\t| "
						<< internalSymbolTable[i].fIndex << "\n";
				}

				n = internalFunctionTable.size();
				cout << "\nFUNCTION TABLE\n";
				cout << "IDEN\t| RTYPE\t| NARGS\t| FINDEX\n";
				cout << "--------|-------|-------|--------\n";
				for(int i = 0; i < n; i++) {
					cout << internalFunctionTable[i].IDEN << "\t| "
						<< internalFunctionTable[i].returnType << "\t| "
						<< internalFunctionTable[i].nArgs << "\t| "
						<< internalFunctionTable[i].fnIndex << "\n";
				}
			}
	};
	SymbolTable symbolTable;


/* Line 189 of yacc.c  */
#line 236 "y.tab.c"

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
/* Tokens.  */
#define MAIN 258
#define VOID 259
#define RETURN 260
#define INT 261
#define FLOAT 262
#define CHAR 263
#define BOOLEAN 264
#define IF 265
#define ELIF 266
#define ELSE 267
#define LOOP 268
#define BREAK 269
#define CONTINUE 270
#define IDENTIFIER 271
#define BOOLEAN_LIT 272
#define FLOAT_LIT 273
#define INT_LIT 274
#define CHAR_LIT 275
#define SEMICOLON 276
#define COMMA 277
#define LP 278
#define RP 279
#define LC 280
#define RC 281
#define ADD_ASSIGN_OP 282
#define SUB_ASSIGN_OP 283
#define MUL_ASSIGN_OP 284
#define DIV_ASSIGN_OP 285
#define REM_ASSIGN_OP 286
#define EQUAL_OP 287
#define NOT_EQUAL_OP 288
#define MRTE 289
#define LSTE 290
#define MRT 291
#define LST 292
#define LOGICAL_AND_OP 293
#define LOGICAL_OR_OP 294
#define EXCLAMATION_OP 295
#define ASSIGN_OP 296
#define ADD_OP 297
#define SUB_OP 298
#define MUL_OP 299
#define DIV_OP 300
#define REM_OP 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 164 "semantic_analyser.y"
char *str; int type;


/* Line 214 of yacc.c  */
#line 368 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 380 "y.tab.c"

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  156

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
       0,     0,     3,     5,     8,    12,    14,    16,    19,    25,
      32,    38,    45,    47,    51,    54,    57,    61,    63,    66,
      69,    72,    74,    76,    79,    81,    84,    86,    90,    94,
     100,   102,   104,   108,   112,   116,   120,   124,   128,   130,
     134,   136,   140,   142,   146,   150,   152,   156,   160,   164,
     168,   170,   174,   178,   180,   184,   188,   192,   194,   197,
     199,   202,   205,   209,   215,   221,   228,   231,   237,   240,
     242,   246,   248,   250,   252,   254,   256,   258,   262,   267,
     269,   273,   275,   277,   279,   281,   283,   285,   287
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    -1,    50,    55,    -1,    51,    50,
      55,    -1,     3,    -1,    52,    -1,    51,    52,    -1,     4,
      16,    80,    81,    55,    -1,     4,    16,    80,    53,    81,
      55,    -1,    79,    16,    80,    81,    55,    -1,    79,    16,
      80,    53,    81,    55,    -1,    54,    -1,    53,    22,    54,
      -1,    79,    16,    -1,    82,    83,    -1,    82,    56,    83,
      -1,    57,    -1,    56,    57,    -1,    58,    21,    -1,    60,
      21,    -1,    69,    -1,    73,    -1,    74,    21,    -1,    21,
      -1,    79,    59,    -1,    16,    -1,    16,    41,    60,    -1,
      59,    22,    16,    -1,    59,    22,    16,    41,    60,    -1,
      61,    -1,    62,    -1,    16,    41,    62,    -1,    16,    27,
      62,    -1,    16,    28,    62,    -1,    16,    29,    62,    -1,
      16,    30,    62,    -1,    16,    31,    62,    -1,    63,    -1,
      62,    39,    63,    -1,    64,    -1,    63,    38,    64,    -1,
      65,    -1,    64,    32,    65,    -1,    64,    33,    65,    -1,
      66,    -1,    65,    37,    66,    -1,    65,    35,    66,    -1,
      65,    36,    66,    -1,    65,    34,    66,    -1,    67,    -1,
      66,    42,    67,    -1,    66,    43,    67,    -1,    68,    -1,
      67,    44,    68,    -1,    67,    45,    68,    -1,    67,    46,
      68,    -1,    75,    -1,    40,    75,    -1,    70,    -1,    70,
      72,    -1,    70,    71,    -1,    70,    71,    72,    -1,    10,
      80,    62,    81,    55,    -1,    11,    80,    62,    81,    55,
      -1,    11,    80,    62,    81,    55,    71,    -1,    12,    55,
      -1,    13,    80,    62,    81,    55,    -1,     5,    62,    -1,
      76,    -1,    23,    62,    24,    -1,    17,    -1,    18,    -1,
      19,    -1,    20,    -1,    77,    -1,    16,    -1,    16,    23,
      24,    -1,    16,    23,    78,    24,    -1,    76,    -1,    78,
      22,    76,    -1,     6,    -1,     7,    -1,     8,    -1,     9,
      -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   177,   177,   186,   193,   201,   214,   221,   229,   242,
     255,   268,   282,   289,   297,   309,   316,   324,   331,   339,
     346,   353,   360,   367,   374,   382,   390,   401,   412,   423,
     435,   442,   450,   457,   464,   471,   478,   485,   493,   500,
     508,   515,   523,   530,   537,   545,   552,   559,   566,   573,
     581,   588,   595,   603,   610,   617,   624,   632,   639,   647,
     654,   661,   668,   676,   684,   691,   699,   707,   715,   723,
     730,   737,   744,   751,   758,   765,   772,   780,   787,   795,
     802,   810,   818,   826,   834,   843,   853,   863,   873
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
  "program_start", "program", "main_term", "functions",
  "function_declaration", "params", "param", "block", "statement_list",
  "statement", "variable_declaration", "variable_list", "expression",
  "assign_expression", "op_or_expression", "op_and_expression",
  "op_rel_expression", "op_condt_expression", "op_additive_expression",
  "op_multiplicative_expression", "op_neg_expression",
  "conditional_statement", "simple_if", "ladder_elif", "simple_else",
  "loop_statement", "return_statement", "factor", "term",
  "functional_call", "args", "data_type", "left_paran", "right_paran",
  "left_curl", "right_curl", 0
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
       0,    47,    48,    49,    49,    50,    51,    51,    52,    52,
      52,    52,    53,    53,    54,    55,    55,    56,    56,    57,
      57,    57,    57,    57,    57,    58,    59,    59,    59,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    62,    62,
      63,    63,    64,    64,    64,    65,    65,    65,    65,    65,
      66,    66,    66,    67,    67,    67,    67,    68,    68,    69,
      69,    69,    69,    70,    71,    71,    72,    73,    74,    75,
      75,    76,    76,    76,    76,    76,    76,    77,    77,    78,
      78,    79,    79,    79,    79,    80,    81,    82,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     1,     1,     2,     5,     6,
       5,     6,     1,     3,     2,     2,     3,     1,     2,     2,
       2,     1,     1,     2,     1,     2,     1,     3,     3,     5,
       1,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     1,
       2,     2,     3,     5,     5,     6,     2,     5,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     3,     4,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,    81,    82,    83,    84,     0,     2,     0,
       0,     6,     0,     0,     1,    87,     3,     0,     0,     7,
       0,    85,     0,     0,     0,     0,    76,    71,    72,    73,
      74,    24,     0,    88,     0,     0,    17,     0,     0,    30,
      31,    38,    40,    42,    45,    50,    53,    21,    59,    22,
       0,    57,    69,    75,     0,    15,     4,     0,    86,     0,
      12,     0,     0,    76,    68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    18,    16,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,    60,    23,    26,    25,
       0,     0,     0,     0,    14,     8,     0,     0,    77,    79,
       0,    33,    34,    35,    36,    37,    32,    70,    39,    41,
      43,    44,    49,    47,    48,    46,    51,    52,    54,    55,
      56,     0,    66,    62,     0,     0,     0,    10,    13,     9,
       0,     0,     0,    78,     0,    27,    28,    11,    63,    67,
      80,     0,     0,    64,    29,    65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    59,    60,    16,    35,
      36,    37,    99,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    95,    96,    49,    50,    51,    52,
      53,   110,    61,    22,    62,    17,    55
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -127
static const yytype_int16 yypact[] =
{
     131,  -127,   -12,  -127,  -127,  -127,  -127,    10,  -127,    12,
     131,  -127,    23,    20,  -127,  -127,  -127,    15,    12,  -127,
      20,  -127,   100,    50,    20,    20,    74,  -127,  -127,  -127,
    -127,  -127,    50,  -127,   109,    15,  -127,    54,    70,  -127,
      45,    79,    39,    22,    71,    18,  -127,  -127,   108,  -127,
     115,  -127,  -127,  -127,    84,  -127,  -127,   100,  -127,   -15,
    -127,   105,    12,   126,    45,    50,    50,    62,    50,    50,
      50,    50,    50,    50,   -10,  -127,  -127,  -127,  -127,  -127,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    20,    12,   138,  -127,  -127,   112,   132,
     -15,    12,   135,    12,  -127,  -127,     3,     3,  -127,  -127,
      88,    45,    45,    45,    45,    45,    45,  -127,    79,    39,
      22,    22,    71,    71,    71,    71,    18,    18,  -127,  -127,
    -127,    50,  -127,  -127,    76,   139,    12,  -127,  -127,  -127,
      12,    12,    -1,  -127,     3,  -127,   116,  -127,  -127,  -127,
    -127,    12,    76,   145,  -127,  -127
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,   148,  -127,   149,   103,    59,   -18,  -127,
     127,  -127,  -127,  -126,  -127,   -20,    83,    85,    48,    61,
      63,    -3,  -127,  -127,    11,    72,  -127,  -127,   134,   -65,
    -127,  -127,    30,   -19,   -46,  -127,   130
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      56,    57,   109,    64,    13,    65,    66,   102,   145,    58,
      14,   101,    74,   103,   117,    63,    27,    28,    29,    30,
      23,     3,     4,     5,     6,    24,   154,    58,    25,    80,
      12,    26,    27,    28,    29,    30,    31,    15,    32,    20,
      12,    33,    80,    21,   105,   106,   107,    54,   111,   112,
     113,   114,   115,   116,   136,    34,    84,    85,    86,    87,
     140,   141,    90,    91,    92,    54,    63,    27,    28,    29,
      30,    82,    83,    32,   131,    78,   132,   150,    63,    27,
      28,    29,    30,   137,    80,   139,   108,   128,   129,   130,
      34,    79,    26,    27,    28,    29,    30,    67,   151,    32,
      98,    68,    69,    70,    71,    72,     3,     4,     5,     6,
     142,   144,   143,    88,    89,    73,    34,    81,   147,    93,
      94,   104,   148,   149,    58,    63,    27,    28,    29,    30,
     120,   121,    32,   153,     1,     2,    97,     3,     4,     5,
       6,     3,     4,     5,     6,   122,   123,   124,   125,    67,
      94,   126,   127,   134,   135,   146,    93,   152,    18,    19,
     100,   138,    76,   118,   155,    77,   119,   133,    75
};

static const yytype_uint8 yycheck[] =
{
      18,    20,    67,    23,    16,    24,    25,    22,   134,    24,
       0,    57,    32,    59,    24,    16,    17,    18,    19,    20,
       5,     6,     7,     8,     9,    10,   152,    24,    13,    39,
       0,    16,    17,    18,    19,    20,    21,    25,    23,    16,
      10,    26,    39,    23,    62,    65,    66,    17,    68,    69,
      70,    71,    72,    73,   100,    40,    34,    35,    36,    37,
     106,   107,    44,    45,    46,    35,    16,    17,    18,    19,
      20,    32,    33,    23,    93,    21,    94,   142,    16,    17,
      18,    19,    20,   101,    39,   103,    24,    90,    91,    92,
      40,    21,    16,    17,    18,    19,    20,    23,   144,    23,
      16,    27,    28,    29,    30,    31,     6,     7,     8,     9,
      22,   131,    24,    42,    43,    41,    40,    38,   136,    11,
      12,    16,   140,   141,    24,    16,    17,    18,    19,    20,
      82,    83,    23,   151,     3,     4,    21,     6,     7,     8,
       9,     6,     7,     8,     9,    84,    85,    86,    87,    23,
      12,    88,    89,    41,    22,    16,    11,    41,    10,    10,
      57,   102,    35,    80,   153,    35,    81,    95,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,     8,     9,    48,    49,    50,
      51,    52,    79,    16,     0,    25,    55,    82,    50,    52,
      16,    23,    80,     5,    10,    13,    16,    17,    18,    19,
      20,    21,    23,    26,    40,    56,    57,    58,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    73,
      74,    75,    76,    77,    79,    83,    55,    80,    24,    53,
      54,    79,    81,    16,    62,    80,    80,    23,    27,    28,
      29,    30,    31,    41,    62,    75,    57,    83,    21,    21,
      39,    38,    32,    33,    34,    35,    36,    37,    42,    43,
      44,    45,    46,    11,    12,    71,    72,    21,    16,    59,
      53,    81,    22,    81,    16,    55,    62,    62,    24,    76,
      78,    62,    62,    62,    62,    62,    62,    24,    63,    64,
      65,    65,    66,    66,    66,    66,    67,    67,    68,    68,
      68,    80,    55,    72,    41,    22,    81,    55,    54,    55,
      81,    81,    22,    24,    62,    60,    16,    55,    55,    55,
      76,    81,    41,    55,    60,    71
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
#line 178 "semantic_analyser.y"
    {
					symbolTable.printTable();
					
					if(DEBUG_CODE == 1)
						printf("program_start\n");
				}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 187 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("program 1\n");
			}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 194 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("program 2\n");
			}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 202 "semantic_analyser.y"
    {
					FUNCTION = 0;
					if(symbolTable.addIDEN("main", -1, -1, -1, FUNCTION, true) == -1) {
						const char *s = "FUNCTION Identifier with this value already exists";
						yyerror(s);
					}

					if(DEBUG_CODE == 1)
						printf("main_term\n");
				}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 215 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("functions 1\n");
				}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 222 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("functions 2\n");
				}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 230 "semantic_analyser.y"
    {
							FUNCTION++;
							if(symbolTable.addIDEN((yyvsp[(2) - (5)].str), 0, -1, 0, FUNCTION - 1, true) == -1) {
								const char *s = "FUNCTION Identifier with this value already exists";
								yyerror(s);
							}
							NARGS = 0;

							if(DEBUG_CODE == 1)
								printf("function_declaration 1\n");
						}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 243 "semantic_analyser.y"
    {
							FUNCTION++;
							if(symbolTable.addIDEN((yyvsp[(2) - (6)].str), 0, -1, NARGS, FUNCTION - 1, true) == -1) {
								const char *s = "FUNCTION Identifier with this value already exists";
								yyerror(s);
							}
							NARGS = 0;

							if(DEBUG_CODE == 1)
								printf("function_declaration 2\n");
						}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 256 "semantic_analyser.y"
    {
							FUNCTION++;
							if(symbolTable.addIDEN((yyvsp[(2) - (5)].str), DATA_TYPE, -1, 0, FUNCTION - 1, true) == -1) {
								const char *s = "FUNCTION Identifier with this value already exists";
								yyerror(s);
							}
							NARGS = 0;

							if(DEBUG_CODE == 1)
								printf("function_declaration 3\n");
						}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 269 "semantic_analyser.y"
    {
							FUNCTION++;
							if(symbolTable.addIDEN((yyvsp[(2) - (6)].str), DATA_TYPE, -1, NARGS, FUNCTION - 1, true) == -1) {
								const char *s = "FUNCTION Identifier with this value already exists";
								yyerror(s);
							}
							NARGS = 0;

							if(DEBUG_CODE == 1)
								printf("function_declaration 4\n");
						}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 283 "semantic_analyser.y"
    {
				NARGS++;
				if(DEBUG_CODE == 1)
					printf("params 2\n");
			}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 290 "semantic_analyser.y"
    {
				NARGS++;
				if(DEBUG_CODE == 1)
					printf("params 2\n");
			}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 298 "semantic_analyser.y"
    {
				if(symbolTable.addIDEN((yyvsp[(2) - (2)].str), DATA_TYPE, currentScope.top(), currentScope.size(), FUNCTION, false) == -1) {
					const char *s = "Identifier with this value already exists";
					yyerror(s);
				}
				
				if(DEBUG_CODE == 1)
					printf("param \n");
			}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 310 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("block 1\n");
			}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 317 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("block 2\n");
			}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 325 "semantic_analyser.y"
    {
						
						if(DEBUG_CODE == 1)
							printf("statement_list 1\n");
					}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 332 "semantic_analyser.y"
    {
						
						if(DEBUG_CODE == 1)
							printf("statement_list 2\n");
					}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 340 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("statement 1\n");
				}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 347 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("statement 2\n");
				}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 354 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("statement 3\n");
				}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 361 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("statement 4\n");
				}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 368 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("statement 5\n");
				}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 375 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("statement 6\n");
				}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 383 "semantic_analyser.y"
    {
							
							if(DEBUG_CODE == 1)
								printf("variable_declaration \n");
						}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 391 "semantic_analyser.y"
    {
						if(symbolTable.addIDEN((yyvsp[(1) - (1)].str), DATA_TYPE, currentScope.top(), currentScope.size(), FUNCTION, false) == -1) {
							const char *s = "Identifier with this value already exists";
							yyerror(s);
						}
						
						if(DEBUG_CODE == 1)
							printf("variable_list 1 ");
					}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 402 "semantic_analyser.y"
    {
						if(symbolTable.addIDEN((yyvsp[(1) - (3)].str), DATA_TYPE, currentScope.top(), currentScope.size(), FUNCTION, false) == -1) {
							const char *s = "Identifier with this value already exists";
							yyerror(s);
						}
						
						if(DEBUG_CODE == 1)
							printf("variable_list 2 ");
					}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 413 "semantic_analyser.y"
    {	
						if(symbolTable.addIDEN((yyvsp[(3) - (3)].str), DATA_TYPE, currentScope.top(), currentScope.size(), FUNCTION, false) == -1) {
							const char *s = "Identifier with this value already exists";
							yyerror(s);
						}
						
						if(DEBUG_CODE == 1)
							printf("variable_list 3 ");
					}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 424 "semantic_analyser.y"
    {
						if(symbolTable.addIDEN((yyvsp[(3) - (5)].str), DATA_TYPE, currentScope.top(), currentScope.size(), FUNCTION, false) == -1) {
							const char *s = "Identifier with this value already exists";
							yyerror(s);
						}
						
						if(DEBUG_CODE == 1)
							printf("variable_list 4 ");
					}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 436 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("expression 1 ");
				}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 443 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("expression 2 ");
				}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 451 "semantic_analyser.y"
    {
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 1 ");
						}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 458 "semantic_analyser.y"
    {
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 2 ");
						}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 465 "semantic_analyser.y"
    {
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 3 ");
						}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 472 "semantic_analyser.y"
    {
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 4 ");
						}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 479 "semantic_analyser.y"
    {
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 5 ");
						}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 486 "semantic_analyser.y"
    {
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 6 ");
						}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 494 "semantic_analyser.y"
    {
                        
						if(DEBUG_CODE == 1)
							printf("op_or_expression 1 ");
                    }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 501 "semantic_analyser.y"
    {
                        
						if(DEBUG_CODE == 1)
							printf("op_or_expression 2 ");
                    }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 509 "semantic_analyser.y"
    {
                            
							if(DEBUG_CODE == 1)
								printf("op_and_expression 1 ");
                        }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 516 "semantic_analyser.y"
    {
                            
							if(DEBUG_CODE == 1)
								printf("op_and_expression 2 ");
                        }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 524 "semantic_analyser.y"
    {
                            
							if(DEBUG_CODE == 1)
								printf("op_rel_expression 1 ");
                        }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 531 "semantic_analyser.y"
    {
                            
							if(DEBUG_CODE == 1)
								printf("op_rel_expression 2 ");
                        }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 538 "semantic_analyser.y"
    {
                            
							if(DEBUG_CODE == 1)
								printf("op_rel_expression 3 ");
                        }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 546 "semantic_analyser.y"
    {
                            
							if(DEBUG_CODE == 1)
								printf("op_condt_expression 1 ");
                        }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 553 "semantic_analyser.y"
    {
                            
							if(DEBUG_CODE == 1)
								printf("op_condt_expression 2 ");
                        }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 560 "semantic_analyser.y"
    {
                            
							if(DEBUG_CODE == 1)
								printf("op_condt_expression 3 ");
                        }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 567 "semantic_analyser.y"
    {
                            
							if(DEBUG_CODE == 1)
								printf("op_condt_expression 4 ");
                        }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 574 "semantic_analyser.y"
    {
                            
							if(DEBUG_CODE == 1)
								printf("op_condt_expression 5 ");
                        }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 582 "semantic_analyser.y"
    {
                                
								if(DEBUG_CODE == 1)
									printf("op_additive_expression 1 ");
                            }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 589 "semantic_analyser.y"
    {
                                
								if(DEBUG_CODE == 1)
									printf("op_additive_expression 2 ");
                            }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 596 "semantic_analyser.y"
    {
                                
								if(DEBUG_CODE == 1)
									printf("op_additive_expression 3 ");
                            }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 604 "semantic_analyser.y"
    {
                                        
										if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 1 ");
                                    }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 611 "semantic_analyser.y"
    {
                                        
										if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 2 ");
                                    }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 618 "semantic_analyser.y"
    {
                                        
										if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 3 ");
                                    }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 625 "semantic_analyser.y"
    {
                                        
										if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 4 ");
                                    }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 633 "semantic_analyser.y"
    {
                            
							if(DEBUG_CODE == 1)
								printf("op_neg_expression 1 ");
                        }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 640 "semantic_analyser.y"
    {
                            
							if(DEBUG_CODE == 1)
								printf("op_neg_expression 2 ");
                        }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 648 "semantic_analyser.y"
    {
								
								if(DEBUG_CODE == 1)
									printf("conditional_statement 1 ");
							}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 655 "semantic_analyser.y"
    {
								
								if(DEBUG_CODE == 1)
									printf("conditional_statement 2 ");
							}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 662 "semantic_analyser.y"
    {
								
								if(DEBUG_CODE == 1)
									printf("conditional_statement 3 ");
							}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 669 "semantic_analyser.y"
    {
								
								if(DEBUG_CODE == 1)
									printf("conditional_statement 4 ");
							}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 677 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("simple_if ");
				}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 685 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("ladder_elif 1 ");
				}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 692 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("ladder_elif 2 ");
				}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 700 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("simple_else ");
				}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 708 "semantic_analyser.y"
    {
						
						if(DEBUG_CODE == 1)
							printf("loop_statement ");
					}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 716 "semantic_analyser.y"
    {
						
						if(DEBUG_CODE == 1)
							printf("return_statement ");
					}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 724 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("factor 1 ");
			}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 731 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("factor 2 ");
			}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 738 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("term 1 ");
			}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 745 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("term 2 ");
			}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 752 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("term 3 ");
			}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 759 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("term 4 ");
			}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 766 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("term 5 ");
			}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 773 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("term 6 ");
			}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 781 "semantic_analyser.y"
    {
						
						if(DEBUG_CODE == 1)
							printf("functional_call 1 ");
					}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 788 "semantic_analyser.y"
    {
						
						if(DEBUG_CODE == 1)
							printf("functional_call 2 ");
					}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 796 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("args 1 ");
			}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 803 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("args 2 ");
			}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 811 "semantic_analyser.y"
    {	
					DATA_TYPE = 1;
					
					if(DEBUG_CODE == 1)
						printf("data_type 1 ");
				}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 819 "semantic_analyser.y"
    {
					DATA_TYPE = 2;
					
					if(DEBUG_CODE == 1)
						printf("data_type 2 ");
				}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 827 "semantic_analyser.y"
    {	
					DATA_TYPE = 3;
					
					if(DEBUG_CODE == 1)
						printf("data_type 3 ");
				}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 835 "semantic_analyser.y"
    {
					DATA_TYPE = 4;
					
					if(DEBUG_CODE == 1)
						printf("data_type 4 ");
				}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 844 "semantic_analyser.y"
    {	
					SCOPE++;
					currentScope.push(SCOPE);
					
					if(DEBUG_CODE == 1)
						printf("LP ");
				}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 854 "semantic_analyser.y"
    {	
					SCOPE--;
					currentScope.pop();
					
					if(DEBUG_CODE == 1)
						printf("RP ");
				}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 864 "semantic_analyser.y"
    {	
					SCOPE++;
					currentScope.push(SCOPE);
					
					if(DEBUG_CODE == 1)
						printf("LC ");
				}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 874 "semantic_analyser.y"
    {	
					currentScope.pop();
					
					if(DEBUG_CODE == 1)
						printf("RC ");
				}
    break;



/* Line 1455 of yacc.c  */
#line 2743 "y.tab.c"
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
#line 881 "semantic_analyser.y"


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
