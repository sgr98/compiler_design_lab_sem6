
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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
#define INPUT 271
#define OUTPUT 272
#define IDENTIFIER 273
#define BOOLEAN_LIT 274
#define FLOAT_LIT 275
#define INT_LIT 276
#define CHAR_LIT 277
#define SEMICOLON 278
#define COMMA 279
#define LP 280
#define RP 281
#define LC 282
#define RC 283
#define ADD_ASSIGN_OP 284
#define SUB_ASSIGN_OP 285
#define MUL_ASSIGN_OP 286
#define DIV_ASSIGN_OP 287
#define REM_ASSIGN_OP 288
#define EQUAL_OP 289
#define NOT_EQUAL_OP 290
#define MRTE 291
#define LSTE 292
#define MRT 293
#define LST 294
#define LOGICAL_AND_OP 295
#define LOGICAL_OR_OP 296
#define EXCLAMATION_OP 297
#define ASSIGN_OP 298
#define ADD_OP 299
#define SUB_OP 300
#define MUL_OP 301
#define DIV_OP 302
#define REM_OP 303




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 261 "semantic_analyser.y"
char *str; int type;


/* Line 1676 of yacc.c  */
#line 152 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


