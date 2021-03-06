
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
			// exit(EXIT_SUCCESS);
		}
		int yywrap() {
			return 1;
		}
	}

	// DEBUG CODE 
	int DEBUG_CODE = -1;

	// THREE ADDRESS CODE
	string TAC = "";

	// IMPORTANT GLOBAL VARIABLES
	int DATA_TYPE = 0;
	int SCOPE = 0;
	stack<int> currentScope;
	int FUNCTION = 1;
	int NARGS = 0;
	int ERROR = 0;
	int CURRENT_TAC_INDEX = 1;
	stack<pair<int, int>> currentTAC;	// first = tac_index, second = tac_data_type
	int LABEL = 1;
	stack<int> currentLabel;
	int END_LABEL = 1;
	stack<int> currentEndLabel;
	int LOOP_LABEL = 1;
	stack<int> currentLoopLabel;
	bool isIF = true;

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

			vector<SymbolTableNode> getSymbolTable() {
				return internalSymbolTable;
			}

			vector<FunctionTableNode> getFunctionTable() {
				return internalFunctionTable;
			}

			int getArgs(int fInd) {
				return internalFunctionTable[fInd - 1].nArgs;
			}

			int getReturnType(int fInd) {
				return internalFunctionTable[fInd - 1].returnType;
			}

			vector<SymbolTableNode> getFunctionTable(int fInd) {
				int nargs = getArgs(fInd);
				int k = 0;

				vector<SymbolTableNode> fVar;
				int n = internalSymbolTable.size();
				for(int i = 0; i < n; i++) {
					if(k >= nargs)
						break;
					if(fInd == internalSymbolTable[i].fIndex) {
						string iden = internalSymbolTable[i].IDEN + "_" + to_string(i);
						SymbolTableNode stn(iden, internalSymbolTable[i].type, internalSymbolTable[i].scopeIn, internalSymbolTable[i].scope, internalSymbolTable[i].fIndex);
						fVar.push_back(stn);
						k++;
					}
				}
				return fVar;
			}

			int getFIndex(string IDEN) {
				int n = internalFunctionTable.size();
				for(int i = 0; i < n; i++) {
					if(IDEN.compare(internalFunctionTable[i].IDEN) == 0)
						return i + 1;
				}
				return -1;
			}

			int functionIDENExists(string IDEN) {
				int n = internalFunctionTable.size();
				for(int i = 0; i < n; i++) {
					if(IDEN.compare(internalFunctionTable[i].IDEN) == 0)
						return -2;
				}
				
				n = internalSymbolTable.size();
				for(int i = 0; i < n; i++) {
					if(IDEN.compare(internalSymbolTable[i].IDEN) == 0)
						return -1;
				}
				return 1;
			}

			int IDENExists(string IDEN, int scopeIn) {
				int n = internalFunctionTable.size();
				for(int i = 0; i < n; i++) {
					if(IDEN.compare(internalFunctionTable[i].IDEN) == 0)
						return -2;
				}

				n = internalSymbolTable.size();
				for(int i = 0; i < n; i++) {
					if(IDEN.compare(internalSymbolTable[i].IDEN) == 0 
					&& scopeIn == internalSymbolTable[i].scopeIn)
						return -1;
				}
				return 1;
			}

			int addIDEN(string IDEN, int type, int scopeIn, int scope, int fIndex, bool isFun) {
				if(isFun) {
					// type: return type
					// scope: nargs
					int m = functionIDENExists(IDEN);
					if(m < 0)
						return m;
					FunctionTableNode ftn(IDEN, type, scope, fIndex);
					internalFunctionTable.push_back(ftn);
					return 1;
				}
				else {
					int m = IDENExists(IDEN, scopeIn);
					if(m < 0)
						return m;
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

			int idenDeclared(string IDEN, int scope, int fIndex) {
				int n = internalFunctionTable.size();
				for(int i = 0; i < n; i++) {
					if(IDEN.compare(internalFunctionTable[i].IDEN) == 0)
						return -2;
				}

				n = internalSymbolTable.size();
				for(int i = n - 1; i >= 0; i--) {
					if(fIndex == internalSymbolTable[i].fIndex
					&& IDEN.compare(internalSymbolTable[i].IDEN) == 0
					&& scope >= internalSymbolTable[i].scope)
						return i;
				}
				return -1;
			}

			int getVarDataType(int in) {
				return internalSymbolTable[in].type;
			}

			int getSymbolTableSize() {
				return internalSymbolTable.size();
			}
	};
	SymbolTable symbolTable;

	// FUNCTION DECLARATIONS
	string constructTACHeader();
	void input_output_TAC(int ind, string iden);
	void assignValToTAC(int typ, string val, int dtype);
	string getBinaryOperator(int op);
	void binaryTAC_expression(int op);
	void assign_expression_TAC(int ind, string iden, int type);
	void generateTACFile(string fileName);
	void conditional_expression_TAC(int type);
	void functional_expression_TAC(int type, string IDEN);
	void return_expression_TAC(int fIndex);
	void printTAC(pair<int, int> temptac);

	// ERROR FUNCTIONS
	void IDENAlreadyExistsError(int m, int errNo);
	void expressionErrors(int errNo);


/* Line 189 of yacc.c  */
#line 334 "gm.cc"

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
     INPUT = 271,
     OUTPUT = 272,
     IDENTIFIER = 273,
     BOOLEAN_LIT = 274,
     FLOAT_LIT = 275,
     INT_LIT = 276,
     CHAR_LIT = 277,
     SEMICOLON = 278,
     COMMA = 279,
     LP = 280,
     RP = 281,
     LC = 282,
     RC = 283,
     ADD_ASSIGN_OP = 284,
     SUB_ASSIGN_OP = 285,
     MUL_ASSIGN_OP = 286,
     DIV_ASSIGN_OP = 287,
     REM_ASSIGN_OP = 288,
     EQUAL_OP = 289,
     NOT_EQUAL_OP = 290,
     MRTE = 291,
     LSTE = 292,
     MRT = 293,
     LST = 294,
     LOGICAL_AND_OP = 295,
     LOGICAL_OR_OP = 296,
     EXCLAMATION_OP = 297,
     ASSIGN_OP = 298,
     ADD_OP = 299,
     SUB_OP = 300,
     MUL_OP = 301,
     DIV_OP = 302,
     REM_OP = 303
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 262 "semantic_analyser.y"
char *str; int type;


/* Line 214 of yacc.c  */
#line 422 "gm.cc"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 434 "gm.cc"

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
#define YYLAST   171

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNRULES -- Number of states.  */
#define YYNSTATES  167

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    12,    14,    16,    19,    25,
      32,    38,    45,    47,    51,    54,    57,    61,    63,    66,
      69,    72,    74,    76,    79,    82,    84,    87,    89,    93,
      97,   103,   105,   107,   111,   115,   119,   123,   127,   131,
     133,   137,   139,   143,   145,   149,   153,   155,   159,   163,
     167,   171,   173,   177,   181,   183,   187,   191,   195,   197,
     200,   202,   205,   208,   212,   218,   224,   231,   234,   236,
     238,   240,   246,   248,   250,   253,   257,   261,   263,   267,
     269,   271,   273,   275,   277,   279,   283,   288,   290,   294,
     296,   298,   300,   302,   304,   306,   308
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    -1,    52,    57,    -1,    53,    52,
      57,    -1,     3,    -1,    54,    -1,    53,    54,    -1,     4,
      18,    88,    89,    57,    -1,     4,    18,    88,    55,    89,
      57,    -1,    87,    18,    88,    89,    57,    -1,    87,    18,
      88,    55,    89,    57,    -1,    56,    -1,    55,    24,    56,
      -1,    87,    18,    -1,    90,    91,    -1,    90,    58,    91,
      -1,    59,    -1,    58,    59,    -1,    60,    23,    -1,    62,
      23,    -1,    71,    -1,    78,    -1,    81,    23,    -1,    82,
      23,    -1,    23,    -1,    87,    61,    -1,    18,    -1,    18,
      43,    64,    -1,    61,    24,    18,    -1,    61,    24,    18,
      43,    64,    -1,    63,    -1,    64,    -1,    18,    43,    64,
      -1,    18,    29,    64,    -1,    18,    30,    64,    -1,    18,
      31,    64,    -1,    18,    32,    64,    -1,    18,    33,    64,
      -1,    65,    -1,    64,    41,    65,    -1,    66,    -1,    65,
      40,    66,    -1,    67,    -1,    66,    34,    67,    -1,    66,
      35,    67,    -1,    68,    -1,    67,    39,    68,    -1,    67,
      37,    68,    -1,    67,    38,    68,    -1,    67,    36,    68,
      -1,    69,    -1,    68,    44,    69,    -1,    68,    45,    69,
      -1,    70,    -1,    69,    46,    70,    -1,    69,    47,    70,
      -1,    69,    48,    70,    -1,    83,    -1,    42,    83,    -1,
      72,    -1,    72,    74,    -1,    72,    73,    -1,    72,    73,
      74,    -1,    75,    88,    64,    80,    57,    -1,    76,    88,
      64,    80,    57,    -1,    76,    88,    64,    80,    57,    73,
      -1,    77,    57,    -1,    10,    -1,    11,    -1,    12,    -1,
      79,    88,    64,    80,    57,    -1,    13,    -1,    26,    -1,
       5,    64,    -1,    18,    43,    16,    -1,    17,    43,    18,
      -1,    84,    -1,    25,    64,    26,    -1,    19,    -1,    20,
      -1,    21,    -1,    22,    -1,    85,    -1,    18,    -1,    18,
      25,    26,    -1,    18,    25,    86,    26,    -1,    64,    -1,
      86,    24,    64,    -1,     6,    -1,     7,    -1,     8,    -1,
       9,    -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   276,   276,   292,   299,   307,   324,   331,   339,   352,
     365,   378,   392,   400,   409,   421,   428,   436,   443,   451,
     458,   465,   472,   479,   486,   493,   501,   509,   520,   537,
     548,   565,   572,   580,   596,   612,   628,   644,   660,   677,
     684,   693,   700,   709,   716,   724,   733,   740,   748,   756,
     764,   773,   780,   788,   797,   804,   812,   820,   829,   836,
     862,   870,   878,   886,   895,   903,   910,   918,   926,   935,
     945,   955,   965,   974,   986,   995,  1011,  1028,  1035,  1042,
    1050,  1058,  1066,  1074,  1081,  1098,  1111,  1125,  1132,  1140,
    1148,  1156,  1164,  1173,  1183,  1195,  1205
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "VOID", "RETURN", "INT", "FLOAT",
  "CHAR", "BOOLEAN", "IF", "ELIF", "ELSE", "LOOP", "BREAK", "CONTINUE",
  "INPUT", "OUTPUT", "IDENTIFIER", "BOOLEAN_LIT", "FLOAT_LIT", "INT_LIT",
  "CHAR_LIT", "SEMICOLON", "COMMA", "LP", "RP", "LC", "RC",
  "ADD_ASSIGN_OP", "SUB_ASSIGN_OP", "MUL_ASSIGN_OP", "DIV_ASSIGN_OP",
  "REM_ASSIGN_OP", "EQUAL_OP", "NOT_EQUAL_OP", "MRTE", "LSTE", "MRT",
  "LST", "LOGICAL_AND_OP", "LOGICAL_OR_OP", "EXCLAMATION_OP", "ASSIGN_OP",
  "ADD_OP", "SUB_OP", "MUL_OP", "DIV_OP", "REM_OP", "$accept",
  "program_start", "program", "main_term", "functions",
  "function_declaration", "params", "param", "block", "statement_list",
  "statement", "variable_declaration", "variable_list", "expression",
  "assign_expression", "op_or_expression", "op_and_expression",
  "op_rel_expression", "op_condt_expression", "op_additive_expression",
  "op_multiplicative_expression", "op_neg_expression",
  "conditional_statement", "simple_if", "ladder_elif", "simple_else",
  "if_term", "elif_term", "else_term", "loop_statement", "loop_term",
  "right_paran_cond", "return_statement", "input_output_statement",
  "factor", "term", "functional_call", "args", "data_type", "left_paran",
  "right_paran", "left_curl", "right_curl", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    53,    53,    54,    54,
      54,    54,    55,    55,    56,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    60,    61,    61,    61,
      61,    62,    62,    63,    63,    63,    63,    63,    63,    64,
      64,    65,    65,    66,    66,    66,    67,    67,    67,    67,
      67,    68,    68,    68,    69,    69,    69,    69,    70,    70,
      71,    71,    71,    71,    72,    73,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    82,    83,    83,    84,
      84,    84,    84,    84,    84,    85,    85,    86,    86,    87,
      87,    87,    87,    88,    89,    90,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     1,     1,     2,     5,     6,
       5,     6,     1,     3,     2,     2,     3,     1,     2,     2,
       2,     1,     1,     2,     2,     1,     2,     1,     3,     3,
       5,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       1,     2,     2,     3,     5,     5,     6,     2,     1,     1,
       1,     5,     1,     1,     2,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,    89,    90,    91,    92,     0,     2,     0,
       0,     6,     0,     0,     1,    95,     3,     0,     0,     7,
       0,    93,     0,     0,    68,    72,     0,    84,    79,    80,
      81,    82,    25,     0,    96,     0,     0,    17,     0,     0,
      31,    32,    39,    41,    43,    46,    51,    54,    21,    60,
       0,    22,     0,     0,     0,    58,    77,    83,     0,    15,
       4,     0,    94,     0,    12,     0,     0,    84,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,    18,
      16,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,    70,    62,    61,
       0,     0,     0,     0,    23,    24,    27,    26,     0,     0,
       0,     0,    14,     8,    76,    85,    87,     0,    34,    35,
      36,    37,    38,    75,    33,    78,    40,    42,    44,    45,
      50,    48,    49,    47,    52,    53,    55,    56,    57,    63,
       0,    67,     0,     0,     0,     0,     0,    10,    13,     9,
       0,    86,     0,    73,     0,     0,    28,    29,    11,    88,
       0,    64,    71,     0,    65,    30,    66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    63,    64,    16,    36,
      37,    38,   107,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    98,    99,    50,   100,   101,    51,
      52,   154,    53,    54,    55,    56,    57,   117,    65,    22,
      66,    17,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -139
static const yytype_int16 yypact[] =
{
     110,  -139,    14,  -139,  -139,  -139,  -139,    17,  -139,    33,
     110,  -139,    66,     4,  -139,  -139,  -139,     2,    33,  -139,
       4,  -139,    98,    78,  -139,  -139,    49,     9,  -139,  -139,
    -139,  -139,  -139,    78,  -139,    90,     2,  -139,    71,   102,
    -139,    85,    94,    16,    93,    24,    -1,  -139,  -139,    65,
       4,  -139,     4,   112,   120,  -139,  -139,  -139,   126,  -139,
    -139,    98,  -139,    11,  -139,   127,    33,   128,    85,   133,
      53,    78,    78,    78,    78,    78,    45,   -23,  -139,  -139,
    -139,  -139,  -139,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,  -139,  -139,   140,  -139,
       4,    33,    78,    78,  -139,  -139,   111,   131,    11,    33,
     132,    33,  -139,  -139,  -139,  -139,    85,    56,    85,    85,
      85,    85,    85,  -139,    85,  -139,    94,    16,    93,    93,
      24,    24,    24,    24,    -1,    -1,  -139,  -139,  -139,  -139,
      78,  -139,   -13,   -13,    78,   138,    33,  -139,  -139,  -139,
      78,  -139,   -13,  -139,    33,    33,    85,   114,  -139,    85,
      33,  -139,  -139,    78,   147,    85,  -139
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,  -139,   149,  -139,   150,   100,    52,   -18,  -139,
     129,  -139,  -139,  -139,  -139,   -17,    80,    82,    36,    60,
      10,    -5,  -139,  -139,     0,    69,  -139,  -139,  -139,  -139,
    -139,  -138,  -139,  -139,   134,  -139,  -139,  -139,    26,   -19,
     -59,  -139,   135
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      60,    61,   109,   125,   111,   155,    68,    23,     3,     4,
       5,     6,    24,   153,   160,    25,    77,    14,    83,    26,
      27,    28,    29,    30,    31,    32,    12,    33,    83,    21,
      34,   102,    13,   103,    70,   110,    12,    62,    71,    72,
      73,    74,    75,    58,    35,    93,    94,    95,   113,   146,
      85,    86,    76,   116,   118,   119,   120,   121,   122,   124,
      15,   123,    58,    67,    28,    29,    30,    31,    91,    92,
      33,    67,    28,    29,    30,    31,    96,    97,    33,   115,
     150,   140,   151,   141,    20,   142,   143,    35,   136,   137,
     138,   147,    69,   149,    81,    35,    67,    28,    29,    30,
      31,   134,   135,    33,     3,     4,     5,     6,    67,    28,
      29,    30,    31,     1,     2,    33,     3,     4,     5,     6,
      35,   128,   129,   152,    62,    82,    83,   156,   158,    87,
      88,    89,    90,   159,    84,   104,   161,   162,     3,     4,
       5,     6,   164,   105,   106,   112,   165,   130,   131,   132,
     133,   114,    97,    70,   144,   145,   157,   163,    96,    18,
      19,   108,   148,   126,   166,    79,   127,   139,     0,    78,
       0,    80
};

static const yytype_int16 yycheck[] =
{
      18,    20,    61,    26,    63,   143,    23,     5,     6,     7,
       8,     9,    10,    26,   152,    13,    33,     0,    41,    17,
      18,    19,    20,    21,    22,    23,     0,    25,    41,    25,
      28,    50,    18,    52,    25,    24,    10,    26,    29,    30,
      31,    32,    33,    17,    42,    46,    47,    48,    66,   108,
      34,    35,    43,    70,    71,    72,    73,    74,    75,    76,
      27,    16,    36,    18,    19,    20,    21,    22,    44,    45,
      25,    18,    19,    20,    21,    22,    11,    12,    25,    26,
      24,   100,    26,   101,    18,   102,   103,    42,    93,    94,
      95,   109,    43,   111,    23,    42,    18,    19,    20,    21,
      22,    91,    92,    25,     6,     7,     8,     9,    18,    19,
      20,    21,    22,     3,     4,    25,     6,     7,     8,     9,
      42,    85,    86,   140,    26,    23,    41,   144,   146,    36,
      37,    38,    39,   150,    40,    23,   154,   155,     6,     7,
       8,     9,   160,    23,    18,    18,   163,    87,    88,    89,
      90,    18,    12,    25,    43,    24,    18,    43,    11,    10,
      10,    61,   110,    83,   164,    36,    84,    98,    -1,    35,
      -1,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,     8,     9,    50,    51,    52,
      53,    54,    87,    18,     0,    27,    57,    90,    52,    54,
      18,    25,    88,     5,    10,    13,    17,    18,    19,    20,
      21,    22,    23,    25,    28,    42,    58,    59,    60,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      75,    78,    79,    81,    82,    83,    84,    85,    87,    91,
      57,    88,    26,    55,    56,    87,    89,    18,    64,    43,
      25,    29,    30,    31,    32,    33,    43,    64,    83,    59,
      91,    23,    23,    41,    40,    34,    35,    36,    37,    38,
      39,    44,    45,    46,    47,    48,    11,    12,    73,    74,
      76,    77,    88,    88,    23,    23,    18,    61,    55,    89,
      24,    89,    18,    57,    18,    26,    64,    86,    64,    64,
      64,    64,    64,    16,    64,    26,    65,    66,    67,    67,
      68,    68,    68,    68,    69,    69,    70,    70,    70,    74,
      88,    57,    64,    64,    43,    24,    89,    57,    56,    57,
      24,    26,    64,    26,    80,    80,    64,    18,    57,    64,
      80,    57,    57,    43,    57,    64,    73
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
#line 277 "semantic_analyser.y"
    {
					if(ERROR > 0) {
						cout << "\n~~~~~~~~ERROR OCCURED~~~~~~~~\n";	
					}
					else if(ERROR == 0) {
						symbolTable.printTable();
						TAC = constructTACHeader() + TAC;
						generateTACFile("file");
					}
					
					if(DEBUG_CODE == 1)
						printf("program_start\n");
				;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 293 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("program 1\n");
			;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 300 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("program 2\n");
			;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 308 "semantic_analyser.y"
    {
					FUNCTION = 0;
					int m = symbolTable.addIDEN("main", -1, -1, -1, FUNCTION, true);
					if(m < 0) {
						ERROR = 1;
						const char *s = "\nERROR CODE(02200): FUNCTION Identifier with this value already exists";
						yyerror(s);
					}

					TAC += "^ main:\n";

					if(DEBUG_CODE == 1)
						printf("main_term\n");
				;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 325 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("functions 1\n");
				;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 332 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("functions 2\n");
				;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 340 "semantic_analyser.y"
    {
							FUNCTION++;
							int m = symbolTable.addIDEN(string((yyvsp[(2) - (5)].str)), 0, -1, 0, FUNCTION -1, true);
							if(m < 0) {
								IDENAlreadyExistsError(m, 1);
							}
							NARGS = 0;

							if(DEBUG_CODE == 1)
								printf("function_declaration 1\n");
						;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 353 "semantic_analyser.y"
    {
							FUNCTION++;
							int m = symbolTable.addIDEN(string((yyvsp[(2) - (6)].str)), 0, -1, NARGS, FUNCTION - 1, true);
							if(m < 0) {
								IDENAlreadyExistsError(m, 2);
							}
							NARGS = 0;

							if(DEBUG_CODE == 1)
								printf("function_declaration 2\n");
						;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 366 "semantic_analyser.y"
    {
							FUNCTION++;
							int m = symbolTable.addIDEN(string((yyvsp[(2) - (5)].str)), DATA_TYPE, -1, 0, FUNCTION - 1, true);
							if(m < 0) {
								IDENAlreadyExistsError(m, 3);
							}
							NARGS = 0;

							if(DEBUG_CODE == 1)
								printf("function_declaration 3\n");
						;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 379 "semantic_analyser.y"
    {
							FUNCTION++;
							int m = symbolTable.addIDEN(string((yyvsp[(2) - (6)].str)), DATA_TYPE, -1, NARGS, FUNCTION - 1, true);
							if(m < 0) {
								IDENAlreadyExistsError(m, 4);
							}
							NARGS = 0;

							if(DEBUG_CODE == 1)
								printf("function_declaration 4\n");
						;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 393 "semantic_analyser.y"
    {
				NARGS++;

				if(DEBUG_CODE == 1)
					printf("params 2\n");
			;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 401 "semantic_analyser.y"
    {
				NARGS++;

				if(DEBUG_CODE == 1)
					printf("params 2\n");
			;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 410 "semantic_analyser.y"
    {
				int m = symbolTable.addIDEN(string((yyvsp[(2) - (2)].str)), DATA_TYPE, currentScope.top(), currentScope.size(), FUNCTION, false);
				if(m < 0) {
					IDENAlreadyExistsError(m, 5);
				}
				
				if(DEBUG_CODE == 1)
					printf("param \n");
			;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 422 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("block 1\n");
			;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 429 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("block 2\n");
			;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 437 "semantic_analyser.y"
    {
						
						if(DEBUG_CODE == 1)
							printf("statement_list 1\n");
					;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 444 "semantic_analyser.y"
    {
						
						if(DEBUG_CODE == 1)
							printf("statement_list 2\n");
					;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 452 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("statement 1\n");
				;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 459 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("statement 2\n");
				;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 466 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("statement 3\n");
				;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 473 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("statement 4\n");
				;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 480 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("statement 5\n");
				;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 487 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("statement 6\n");
				;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 494 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("statement 7\n");
				;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 502 "semantic_analyser.y"
    {
							
							if(DEBUG_CODE == 1)
								printf("variable_declaration \n");
						;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 510 "semantic_analyser.y"
    {
						int m = symbolTable.addIDEN(string((yyvsp[(1) - (1)].str)), DATA_TYPE, currentScope.top(), currentScope.size(), FUNCTION, false);
						if(m < 0) {
							IDENAlreadyExistsError(m, 6);
						}
						
						if(DEBUG_CODE == 1)
							printf("variable_list 1 ");
					;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 521 "semantic_analyser.y"
    {
						string iden = string((yyvsp[(1) - (3)].str));
						int m = symbolTable.addIDEN(iden, DATA_TYPE, currentScope.top(), currentScope.size(), FUNCTION, false);
						if(m < 0) {
							IDENAlreadyExistsError(m, 7);
						}
						else {
							iden += "_" + to_string(symbolTable.getSymbolTableSize() - 1);
							assign_expression_TAC(1, iden, DATA_TYPE);
						}
							
						
						if(DEBUG_CODE == 1)
							printf("variable_list 2 ");
					;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 538 "semantic_analyser.y"
    {
						int m = symbolTable.addIDEN(string((yyvsp[(3) - (3)].str)), DATA_TYPE, currentScope.top(), currentScope.size(), FUNCTION, false);
						if(m < 0) {
							IDENAlreadyExistsError(m, 8);
						}
						
						if(DEBUG_CODE == 1)
							printf("variable_list 3 ");
					;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 549 "semantic_analyser.y"
    {
						string iden = string((yyvsp[(3) - (5)].str));
						int m = symbolTable.addIDEN(iden, DATA_TYPE, currentScope.top(), currentScope.size(), FUNCTION, false);
						if(m < 0) {
							IDENAlreadyExistsError(m, 9);
						}
						else {
							iden += "_" + to_string(symbolTable.getSymbolTableSize() - 1);
							assign_expression_TAC(1, iden, DATA_TYPE);
						}
						
						if(DEBUG_CODE == 1)
							printf("variable_list 4 ");
					;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 566 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("expression 1 ");
				;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 573 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("expression 2 ");
				;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 581 "semantic_analyser.y"
    {
							string iden = string((yyvsp[(1) - (3)].str));
							int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
							if(m < 0) {
								IDENAlreadyExistsError(m, 12);
							}
							else {
								iden += "_" + to_string(m);
								assign_expression_TAC(1, iden, symbolTable.getVarDataType(m));
							}
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 1 ");
						;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 597 "semantic_analyser.y"
    {
							string iden = string((yyvsp[(1) - (3)].str));
							int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
							if(m < 0) {
								IDENAlreadyExistsError(m, 12);
							}
							else {
								iden += "_" + to_string(m);
								assign_expression_TAC(2, iden, symbolTable.getVarDataType(m));
							}
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 2 ");
						;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 613 "semantic_analyser.y"
    {
							string iden = string((yyvsp[(1) - (3)].str));
							int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
							if(m < 0) {
								IDENAlreadyExistsError(m, 12);
							}
							else {
								iden += "_" + to_string(m);
								assign_expression_TAC(3, iden, symbolTable.getVarDataType(m));
							}
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 3 ");
						;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 629 "semantic_analyser.y"
    {
							string iden = string((yyvsp[(1) - (3)].str));
							int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
							if(m < 0) {
								IDENAlreadyExistsError(m, 12);
							}
							else {
								iden += "_" + to_string(m);
								assign_expression_TAC(4, iden, symbolTable.getVarDataType(m));
							}
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 4 ");
						;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 645 "semantic_analyser.y"
    {
							string iden = string((yyvsp[(1) - (3)].str));
							int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
							if(m < 0) {
								IDENAlreadyExistsError(m, 12);
							}
							else {
								iden += "_" + to_string(m);
								assign_expression_TAC(5, iden, symbolTable.getVarDataType(m));
							}
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 5 ");
						;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 661 "semantic_analyser.y"
    {
							string iden = string((yyvsp[(1) - (3)].str));
							int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
							if(m < 0) {
								IDENAlreadyExistsError(m, 12);
							}
							else {
								iden += "_" + to_string(m);
								assign_expression_TAC(6, iden, symbolTable.getVarDataType(m));
							}
							
							if(DEBUG_CODE == 1)
								printf("assign_expression 6 ");
						;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 678 "semantic_analyser.y"
    {
                        
						if(DEBUG_CODE == 1)
							printf("op_or_expression 1 ");
                    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 685 "semantic_analyser.y"
    {
						binaryTAC_expression(1);
                        
						if(DEBUG_CODE == 1)
							printf("op_or_expression 2 ");
                    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 694 "semantic_analyser.y"
    {
                            
							if(DEBUG_CODE == 1)
								printf("op_and_expression 1 ");
                        ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 701 "semantic_analyser.y"
    {
							binaryTAC_expression(2);
                            
							if(DEBUG_CODE == 1)
								printf("op_and_expression 2 ");
                        ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 710 "semantic_analyser.y"
    {
                            
							if(DEBUG_CODE == 1)
								printf("op_rel_expression 1 ");
                        ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 717 "semantic_analyser.y"
    {
							binaryTAC_expression(3);
                            
							if(DEBUG_CODE == 1)
								printf("op_rel_expression 2 ");
                        ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 725 "semantic_analyser.y"
    {
							binaryTAC_expression(4);
                            
							if(DEBUG_CODE == 1)
								printf("op_rel_expression 3 ");
                        ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 734 "semantic_analyser.y"
    {
                            
							if(DEBUG_CODE == 1)
								printf("op_condt_expression 1 ");
                        ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 741 "semantic_analyser.y"
    {
							binaryTAC_expression(5);
                            
							if(DEBUG_CODE == 1)
								printf("op_condt_expression 2 ");
                        ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 749 "semantic_analyser.y"
    {
							binaryTAC_expression(6);
                            
							if(DEBUG_CODE == 1)
								printf("op_condt_expression 3 ");
                        ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 757 "semantic_analyser.y"
    {
							binaryTAC_expression(7);
                            
							if(DEBUG_CODE == 1)
								printf("op_condt_expression 4 ");
                        ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 765 "semantic_analyser.y"
    {
							binaryTAC_expression(8);
                            
							if(DEBUG_CODE == 1)
								printf("op_condt_expression 5 ");
                        ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 774 "semantic_analyser.y"
    {
                                
								if(DEBUG_CODE == 1)
									printf("op_additive_expression 1 ");
                            ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 781 "semantic_analyser.y"
    {
								binaryTAC_expression(9);
                                
								if(DEBUG_CODE == 1)
									printf("op_additive_expression 2 ");
                            ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 789 "semantic_analyser.y"
    {
								binaryTAC_expression(10);
                                
								if(DEBUG_CODE == 1)
									printf("op_additive_expression 3 ");
                            ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 798 "semantic_analyser.y"
    {
                                        
										if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 1 ");
                                    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 805 "semantic_analyser.y"
    {
										binaryTAC_expression(11);
                                        
										if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 2 ");
                                    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 813 "semantic_analyser.y"
    {
										binaryTAC_expression(12);
                                        
										if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 3 ");
                                    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 821 "semantic_analyser.y"
    {
										binaryTAC_expression(13);
                                        
										if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 4 ");
                                    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 830 "semantic_analyser.y"
    {
                            
							if(DEBUG_CODE == 1)
								printf("op_neg_expression 1 ");
                        ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 837 "semantic_analyser.y"
    {
							if(currentTAC.size() >= 1) {
								pair<int, int> tempTac = currentTAC.top();
								currentTAC.pop();
								if(tempTac.second != 4) {
									expressionErrors(14);
								}
								else {
									TAC += "t" + to_string(CURRENT_TAC_INDEX);
									TAC += " = ! ";
									TAC += "t" + to_string(tempTac.first) + "\n";
									pair<int, int> newTac;
									newTac.first = CURRENT_TAC_INDEX;
									newTac.second = tempTac.second;
									// printTAC(newTac);
									currentTAC.push(newTac);
									CURRENT_TAC_INDEX++;
								}
							}
							
							if(DEBUG_CODE == 1)
								printf("op_neg_expression 2 ");
                        ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 863 "semantic_analyser.y"
    {
								conditional_expression_TAC(4);
								
								if(DEBUG_CODE == 1)
									printf("conditional_statement 1 ");
							;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 871 "semantic_analyser.y"
    {
								conditional_expression_TAC(3);
								
								if(DEBUG_CODE == 1)
									printf("conditional_statement 2 ");
							;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 879 "semantic_analyser.y"
    {
								conditional_expression_TAC(3);
								
								if(DEBUG_CODE == 1)
									printf("conditional_statement 3 ");
							;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 887 "semantic_analyser.y"
    {
								conditional_expression_TAC(3);
								
								if(DEBUG_CODE == 1)
									printf("conditional_statement 4 ");
							;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 896 "semantic_analyser.y"
    {

					if(DEBUG_CODE == 1)
						printf("simple_if ");
				;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 904 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("ladder_elif 1 ");
				;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 911 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("ladder_elif 2 ");
				;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 919 "semantic_analyser.y"
    {
					
					if(DEBUG_CODE == 1)
						printf("simple_else ");
				;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 927 "semantic_analyser.y"
    {
					isIF = true;

					if(DEBUG_CODE == 1)
						printf("IF ");
				;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 936 "semantic_analyser.y"
    {
					isIF = false;
					conditional_expression_TAC(2);

					if(DEBUG_CODE == 1)
						printf("ELIF ");
				;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 946 "semantic_analyser.y"
    {
					isIF = false;
					conditional_expression_TAC(2);

					if(DEBUG_CODE == 1)
						printf("ELSE ");	
				;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 956 "semantic_analyser.y"
    {
						conditional_expression_TAC(6);
						conditional_expression_TAC(4);
						
						if(DEBUG_CODE == 1)
							printf("loop_statement ");
					;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 966 "semantic_analyser.y"
    {
					conditional_expression_TAC(5);
					
					if(DEBUG_CODE == 1)
						printf("loop_statement ");
				;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 975 "semantic_analyser.y"
    {	
							SCOPE--;
							currentScope.pop();

							conditional_expression_TAC(1);
							
							if(DEBUG_CODE == 1)
								printf("RP ");
						;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 987 "semantic_analyser.y"
    {
						return_expression_TAC(FUNCTION - 1);
						
						if(DEBUG_CODE == 1)
							printf("return_statement ");
					;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 996 "semantic_analyser.y"
    {
								string iden = string((yyvsp[(1) - (3)].str));
								int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
								if(m < 0) {
									IDENAlreadyExistsError(m, 12);
								} 	
								else {
									iden += "_" + to_string(m);
									input_output_TAC(1, iden);
								}
						
								if(DEBUG_CODE == 1)
									printf("input_output_statement 1 ");
							;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1012 "semantic_analyser.y"
    {
								string iden = string((yyvsp[(3) - (3)].str));
								int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
								if(m < 0) {
									IDENAlreadyExistsError(m, 12);
								} 	
								else {
									iden += "_" + to_string(m);
									input_output_TAC(2, iden);
								}
						
								if(DEBUG_CODE == 1)
									printf("input_output_statement 2 ");
							;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1029 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("factor 1 ");
			;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1036 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("factor 2 ");
			;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1043 "semantic_analyser.y"
    {
				assignValToTAC(4, string((yyvsp[(1) - (1)].str)), 4);

				if(DEBUG_CODE == 1)
					printf("term 1 ");
			;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1051 "semantic_analyser.y"
    {
				assignValToTAC(2, string((yyvsp[(1) - (1)].str)), 2);
				
				if(DEBUG_CODE == 1)
					printf("term 2 ");
			;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1059 "semantic_analyser.y"
    {
				assignValToTAC(1, string((yyvsp[(1) - (1)].str)), 1);

				if(DEBUG_CODE == 1)
					printf("term 3 ");
			;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1067 "semantic_analyser.y"
    {
				assignValToTAC(3, string((yyvsp[(1) - (1)].str)), 3);
				
				if(DEBUG_CODE == 1)
					printf("term 4 ");
			;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1075 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("term 5 ");
			;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1082 "semantic_analyser.y"
    {
				string iden = string((yyvsp[(1) - (1)].str));
				int m = symbolTable.idenDeclared(iden, currentScope.size(), FUNCTION);
				if(m < 0) {
					IDENAlreadyExistsError(m, 12);
				}
				else {
					iden += "_" + to_string(m);
					assignValToTAC(0, iden, symbolTable.getVarDataType(m));
				}
				
				if(DEBUG_CODE == 1)
					printf("term 6 ");
			;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1099 "semantic_analyser.y"
    {
						int m = symbolTable.functionIDENExists(string((yyvsp[(1) - (3)].str)));
						if(m != -2) {
							IDENAlreadyExistsError(m, 10);
						}

						functional_expression_TAC(1, string((yyvsp[(1) - (3)].str)));
						
						if(DEBUG_CODE == 1)
							printf("functional_call 1 ");
					;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1112 "semantic_analyser.y"
    {
						int m = symbolTable.functionIDENExists(string((yyvsp[(1) - (4)].str)));
						if(m != -2) {
							IDENAlreadyExistsError(m, 11);
						}

						functional_expression_TAC(2, string((yyvsp[(1) - (4)].str)));
						
						if(DEBUG_CODE == 1)
							printf("functional_call 2 ");
					;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1126 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("args 1 ");
			;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1133 "semantic_analyser.y"
    {
				
				if(DEBUG_CODE == 1)
					printf("args 2 ");
			;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1141 "semantic_analyser.y"
    {	
					DATA_TYPE = 1;
					
					if(DEBUG_CODE == 1)
						printf("data_type 1 ");
				;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1149 "semantic_analyser.y"
    {
					DATA_TYPE = 2;
					
					if(DEBUG_CODE == 1)
						printf("data_type 2 ");
				;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1157 "semantic_analyser.y"
    {	
					DATA_TYPE = 3;
					
					if(DEBUG_CODE == 1)
						printf("data_type 3 ");
				;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1165 "semantic_analyser.y"
    {
					DATA_TYPE = 4;
					
					if(DEBUG_CODE == 1)
						printf("data_type 4 ");
				;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1174 "semantic_analyser.y"
    {	
					SCOPE++;
					currentScope.push(SCOPE);
					
					if(DEBUG_CODE == 1)
						printf("LP ");
				;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1184 "semantic_analyser.y"
    {	
					SCOPE--;
					currentScope.pop();

					conditional_expression_TAC(7);
					
					if(DEBUG_CODE == 1)
						printf("RP ");
				;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1196 "semantic_analyser.y"
    {	
					SCOPE++;
					currentScope.push(SCOPE);
					
					if(DEBUG_CODE == 1)
						printf("LC ");
				;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1206 "semantic_analyser.y"
    {	
					currentScope.pop();
					
					if(DEBUG_CODE == 1)
						printf("RC ");
				;}
    break;



/* Line 1455 of yacc.c  */
#line 3070 "gm.cc"
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
#line 1213 "semantic_analyser.y"


string constructTACHeader() {
	string header = "";
	vector<SymbolTableNode> internalSymbolTable = symbolTable.getSymbolTable();
	vector<FunctionTableNode> internalFunctionTable = symbolTable.getFunctionTable();

	int n;
	n = internalSymbolTable.size();
	header += to_string(n) + "\n";
	for(int i = 0; i < n; i++) {
		header += "$";
		header += internalSymbolTable[i].IDEN + "_" + to_string(i) + ".";
		header += to_string(internalSymbolTable[i].type) + ".";
		header += to_string(internalSymbolTable[i].scopeIn) + ".";
		header += to_string(internalSymbolTable[i].scope) + ".";
		header += to_string(internalSymbolTable[i].fIndex) + "\n";
	}

	n = internalFunctionTable.size();
	header += to_string(n) + "\n";
	for(int i = 0; i < n; i++) {
		header += "#";
		header += internalFunctionTable[i].IDEN + ".";
		header += to_string(internalFunctionTable[i].returnType) + ".";
		header += to_string(internalFunctionTable[i].nArgs) + ".";
		header += to_string(internalFunctionTable[i].fnIndex) + "\n";
	}

	return header;
}

void input_output_TAC(int ind, string iden) {
	// ind = 1	:	INPUT
	// ind = 2	:	OUTPUT
	
	if(ind == 1) {
		TAC += "@input = $" + iden + "\n";
	}
	else if(ind == 2) {
		TAC += "@output = $" + iden + "\n";
	}
}

void assignValToTAC(int typ, string val, int dtype) {
	pair<int, int> newTac;
	if(typ == 0) {
		TAC += "t" + to_string(CURRENT_TAC_INDEX) + " = $" + val + "\n";
		newTac.second = dtype;
	}
	else if(typ >= 1 && typ <= 4) {
		TAC += "t" + to_string(CURRENT_TAC_INDEX) + " = " + val + "\n";
		newTac.second = typ;
	}
	newTac.first = CURRENT_TAC_INDEX;
	// printTAC(newTac);
	currentTAC.push(newTac);
	CURRENT_TAC_INDEX++;
}

string getBinaryOperator(int op) {
	switch(op) {
		case 1:
			return "||";
		case 2:
			return "&&";
		case 3:
			return "==";
		case 4:
			return "!=";
		case 5:
			return "<";
		case 6:
			return "<=";
		case 7:
			return ">";
		case 8:
			return ">=";
		case 9:
			return "+";
		case 10:
			return "-";
		case 11:
			return "*";
		case 12:
			return "/";
		case 13:
			return "%";
		default:
			return "";
	}
}

void binaryTAC_expression(int op) {
	if(currentTAC.size() >= 2) {
		string opr = getBinaryOperator(op);

		pair<int, int> tempTac1 = currentTAC.top();
		currentTAC.pop();
		pair<int, int> tempTac2 = currentTAC.top();
		currentTAC.pop();

		bool errorOccured = false;
		switch(op) {
			case 1:
			case 2:
				errorOccured = tempTac1.second != 4;
				errorOccured = errorOccured || tempTac1.second != tempTac2.second;
				break;
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				errorOccured = tempTac1.second != tempTac2.second;
				break;
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
				errorOccured = tempTac1.second == 4;
				// if(tempTac1.second != tempTac2.second) {
				// 	if((tempTac1.second == 3 && tempTac2.second == 1)
				// 	|| (tempTac1.second == 1 && tempTac2.second == 3)) {

				// 	}
				// 	else
				// 		errorOccured = true;
				// }
				errorOccured = errorOccured || tempTac1.second != tempTac2.second;
				break;
			default:
				break;
		}

		if(errorOccured) {
			expressionErrors(op);
			return;
		}

		TAC += "t" + to_string(CURRENT_TAC_INDEX);
		TAC += " = ";
		TAC += "t" + to_string(tempTac2.first);
		TAC += " " + opr + " ";
		TAC += "t" + to_string(tempTac1.first) + "\n";

		pair<int, int> newTac;
		newTac.first = CURRENT_TAC_INDEX;
		if(op >= 3 && op <= 8) {
			newTac.second = 4;
		}
		else {
			newTac.second = tempTac1.second;
		}
		// printTAC(newTac);
		currentTAC.push(newTac);
		CURRENT_TAC_INDEX++;
	}
}

void assign_expression_TAC(int ind, string iden, int type) {
	if(currentTAC.size() >= 1) {
		pair<int, int> tempTac = currentTAC.top();
		currentTAC.pop();

		if(type == 2) {
			if(!(tempTac.second == 2 || tempTac.second == 1)) {
				// cout << "ee\n";
				expressionErrors(0);
				return;
			}
		}
		else {
			if(type != tempTac.second) {
				// cout << "dd\n";
				expressionErrors(0);
				return;
			}
		}

		if(ind == 1) {
			TAC += "$" + iden;
			TAC += " = ";
			TAC += "t" + to_string(tempTac.first) + "\n";
		}
		else if(ind >= 2 && ind <= 6) {
			if(!(type == 1 || type == 2)) {
				expressionErrors(0);
				return;
			}

			TAC += "t" + to_string(CURRENT_TAC_INDEX) + " = $" + iden + "\n";
			CURRENT_TAC_INDEX++;

			TAC += "t" + to_string(CURRENT_TAC_INDEX) + " = ";

			if(ind == 2) {
				TAC += "t" + to_string(CURRENT_TAC_INDEX - 1) + " + ";
			}
			else if(ind == 3) {
				TAC += "t" + to_string(CURRENT_TAC_INDEX - 1) + " - ";
			}
			else if(ind == 4) {
				TAC += "t" + to_string(CURRENT_TAC_INDEX - 1) + " * ";
			}
			else if(ind == 5) {
				TAC += "t" + to_string(CURRENT_TAC_INDEX - 1) + " / ";
			}
			else if(ind == 6) {
				TAC += "t" + to_string(CURRENT_TAC_INDEX - 1) + " % ";
			}
			
			TAC += "t" + to_string(tempTac.first) + "\n";
			CURRENT_TAC_INDEX++;

			TAC += "$" + iden;
			TAC += " = ";
			TAC += "t" + to_string(CURRENT_TAC_INDEX - 1) + "\n";
		}
	}
}

void generateTACFile(string fileName) {
	fileName += ".tac";
	ofstream tacFile(fileName);
	tacFile << TAC;
	tacFile.close();
}

void conditional_expression_TAC(int type) {
	if(type == 1) {
		if(currentTAC.size() >= 1) {
			pair<int, int> tempTac = currentTAC.top();
			currentTAC.pop();

			TAC += "@if = t" + to_string(tempTac.first);
			TAC += " ^ LABEL" + to_string(LABEL) + "\n";

			currentLabel.push(LABEL);
			LABEL++;

			if(isIF) {
				currentEndLabel.push(END_LABEL);
				END_LABEL++;
			}
		}
	}
	else if(type == 2) {
		if(currentEndLabel.size() >= 1) {
			TAC += "JUMP ^ END" + to_string(currentEndLabel.top()) + "\n";
		}
		// FIX THIS

		if(currentLabel.size() >= 1) {
			TAC += "^ LABEL" + to_string(currentLabel.top()) + ":\n";
			currentLabel.pop();
		}
	}
	else if(type == 3) {
		if(currentEndLabel.size() >= 1) {
			TAC += "^ END" + to_string(currentEndLabel.top()) + ":\n";
			currentEndLabel.pop();
		}
	}
	else if(type == 4) {
		if(currentLabel.size() >= 1) {
			TAC += "^ LABEL" + to_string(currentLabel.top()) + ":\n";
			currentLabel.pop();
		}
	}
	else if(type == 5) {
		TAC += "^ LOOP_LABEL" + to_string(LOOP_LABEL) + ":\n";
		currentLoopLabel.push(LOOP_LABEL);
		LOOP_LABEL++;
	}
	else if(type == 6) {
		if(currentLoopLabel.size() >= 1) {
			TAC += "JUMP ^ LOOP_LABEL" + to_string(currentLoopLabel.top()) + "\n";
			currentLoopLabel.pop();
		}
	}
	else if(type == 7) {
		TAC += "^ FUNC_LABEL" + to_string(FUNCTION) + ":\n";
	}
}

void functional_expression_TAC(int type, string IDEN) {
	int fInd = symbolTable.getFIndex(IDEN);

	if(type == 1) {
		TAC += "JAL ^ FUNC_LABEL" + to_string(fInd) + "\n";
	}
	else if(type == 2) {
		int nargs = symbolTable.getArgs(fInd);
		if(currentTAC.size() >= nargs) {
			vector<SymbolTableNode> fVar = symbolTable.getFunctionTable(fInd);
			for(int i = 0; i < nargs; i++) {
				pair<int, int> tempTac = currentTAC.top();
				currentTAC.pop();

				TAC += "$" + fVar[nargs - i - 1].IDEN;
				TAC += " = ";
				TAC += "t" + to_string(tempTac.first) + "\n";
			}
		}
		else {
			string t = "\nERROR CODE(02040): Unequal number of arguments in function call";
			
			ERROR = 1;
			const char *s = t.c_str();
			yyerror(s);
			return;
		}
		TAC += "JAL ^ FUNC_LABEL" + to_string(fInd) + "\n";
		
		pair<int, int> newTac;
		TAC += "t" + to_string(CURRENT_TAC_INDEX) + " = v1\n";
		newTac.first = CURRENT_TAC_INDEX;
		newTac.second = symbolTable.getReturnType(fInd);
		// printTAC(newTac);
		currentTAC.push(newTac);
		CURRENT_TAC_INDEX++;
	}
	else if(type == 3) {
		
	}
}

void return_expression_TAC(int fIndex) {
	if(currentTAC.size() >= 1) {
		// int retType = symbolTable.getReturnType(fIndex);
		// if(retType == 0) {
		// 	string t = "\nERROR CODE(02041): VOID return type function trying to return a value.\n";
			
		// 	ERROR = 1;
		// 	const char *s = t.c_str();
		// 	yyerror(s);
		// 	return;
		// }

		pair<int, int> tempTac = currentTAC.top();

		// if(retType != tempTac.second) {
		// 	string t = "\nERROR CODE(02042): Return type of function does not match returned value.\n";
			
		// 	ERROR = 1;
		// 	const char *s = t.c_str();
		// 	yyerror(s);
		// 	return;
		// }

		currentTAC.pop();
		TAC += "v1 = t" + to_string(tempTac.first) + "\n";
		TAC += "JR ^ RA\n";
	}
}

void printTAC(pair<int, int> temptac) {
	cout << "TAC: " << temptac.first << "." << temptac.second << endl;
}

void IDENAlreadyExistsError(int m, int errNo) {
	// errNo:
	// 1-4		:	Function Declaration
	// 5		:	Function parameter declaration
	// 6-9		:	Variable Declaration
	// 10-11	:	Function Call
	// 12		:	Variable Call

	int k = errNo * 2;
	string t = "";

	if(errNo >= 1 && errNo <= 4) {
		if(m == -1) {
			k = 2000 + k - 1;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): Illegal Function declaration. Identifier with this value is already declared.";
		}
		else if(m == -2) {
			k = 2000 + k;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): Illegal Function declaration. Functional Identifier with this value is already declared.";
		}
	}
	else if(errNo == 5) {
		if(m == -1) {
			k = 2000 + k - 1;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): Illegal Parameter declaration. Identifier with this value is already declared.";
		}
		else if(m == -2) {
			k = 2000 + k;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): Illegal Parameter declaration. Functional Identifier with this value is already declared.";
		}
	}
	else if(errNo >= 6 && errNo <= 9) {
		if(m == -1) {
			k = 2000 + k - 1;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): Illegal Variable declaration. Identifier with this value is already declared.";
		}
		else if(m == -2) {
			k = 2000 + k;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): Illegal Variable declaration. Functional Identifier with this value is already declared.";
		}
	}
	else if(errNo >= 10 && errNo <= 11) {
		if(m == -1) {
			k = 2000 + k - 1;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): No function was declared with this Identifier. A variable was.";
		}
		else if(m == 1) {
			k = 2000 + k;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): No function was declared with this Identifier.";
		}
	}
	else if(errNo == 12) {
		if(m == -2) {
			k = 2000 + k - 1;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): No variable was declared with this Identifier. A function was.";
		}
		else if(m == -1) {
			k = 2000 + k;
			t = "\nERROR CODE(0";
			t += to_string(k);
			t += "): No variable was declared with this Identifier.";
		}
	}

	ERROR = 1;
	const char *s = t.c_str();
	yyerror(s);
}

void expressionErrors(int errNo) {
	string t = "";

	switch(errNo) {
		case 0:
			t = "\nERROR CODE(02025): Incorrect data types for assignment";
			break;
		case 1:
			t = "\nERROR CODE(02026): Error occured with ||";
			break;
		case 2:
			t = "\nERROR CODE(02027): Error occured with &&";
			break;
		case 3:
			t = "\nERROR CODE(02028): Error occured with ==";
			break;
		case 4:
			t = "\nERROR CODE(02029): Error occured with !=";
			break;
		case 5:
			t = "\nERROR CODE(02030): Error occured with <";
			break;
		case 6:
			t = "\nERROR CODE(02031): Error occured with <=";
			break;
		case 7:
			t = "\nERROR CODE(02032): Error occured with >";
			break;
		case 8:
			t = "\nERROR CODE(02033): Error occured with >=";
			break;
		case 9:
			t = "\nERROR CODE(02034): Error occured with +";
			break;
		case 10:
			t = "\nERROR CODE(02035): Error occured with -";
			break;
		case 11:
			t = "\nERROR CODE(02036): Error occured with *";
			break;
		case 12:
			t = "\nERROR CODE(02037): Error occured with /";
			break;
		case 13:
			t = "\nERROR CODE(02038): Error occured with %";
			break;
		case 14:
			t = "\nERROR CODE(02039): Error occured with !";
			break;
		default:
			break;
	}

	ERROR = 1;
	const char *s = t.c_str();
	yyerror(s);
}

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
