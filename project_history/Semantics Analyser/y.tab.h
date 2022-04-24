
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

/* Line 1676 of yacc.c  */
#line 164 "semantic_analyser.y"
char *str; int type;


/* Line 1676 of yacc.c  */
#line 148 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


