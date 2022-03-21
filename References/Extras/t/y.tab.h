
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
     IDENTIFIER = 265,
     BOOLEAN_LIT = 266,
     FLOAT_LIT = 267,
     INT_LIT = 268,
     CHAR_LIT = 269,
     SEMICOLON = 270,
     COMMA = 271,
     LP = 272,
     RP = 273,
     LC = 274,
     RC = 275,
     ADD_ASSIGN_OP = 276,
     SUB_ASSIGN_OP = 277,
     MUL_ASSIGN_OP = 278,
     DIV_ASSIGN_OP = 279,
     REM_ASSIGN_OP = 280,
     EQUAL_OP = 281,
     NOT_EQUAL_OP = 282,
     MRTE = 283,
     LSTE = 284,
     MRT = 285,
     LST = 286,
     LOGICAL_AND_OP = 287,
     LOGICAL_OR_OP = 288,
     EXCLAMATION_OP = 289,
     ASSIGN_OP = 290,
     ADD_OP = 291,
     SUB_OP = 292,
     MUL_OP = 293,
     DIV_OP = 294,
     REM_OP = 295
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
#define IDENTIFIER 265
#define BOOLEAN_LIT 266
#define FLOAT_LIT 267
#define INT_LIT 268
#define CHAR_LIT 269
#define SEMICOLON 270
#define COMMA 271
#define LP 272
#define RP 273
#define LC 274
#define RC 275
#define ADD_ASSIGN_OP 276
#define SUB_ASSIGN_OP 277
#define MUL_ASSIGN_OP 278
#define DIV_ASSIGN_OP 279
#define REM_ASSIGN_OP 280
#define EQUAL_OP 281
#define NOT_EQUAL_OP 282
#define MRTE 283
#define LSTE 284
#define MRT 285
#define LST 286
#define LOGICAL_AND_OP 287
#define LOGICAL_OR_OP 288
#define EXCLAMATION_OP 289
#define ASSIGN_OP 290
#define ADD_OP 291
#define SUB_OP 292
#define MUL_OP 293
#define DIV_OP 294
#define REM_OP 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


