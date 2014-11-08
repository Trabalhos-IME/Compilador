/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     ASSIGN = 258,
     NOT_EQUAL = 259,
     LESS_THAN = 260,
     GREATER_THAN = 261,
     LESS_OR_EQUAL = 262,
     GREATER_OR_EQUAL = 263,
     EQUAL_EQUAL = 264,
     AND = 265,
     OR = 266,
     PLUS = 267,
     MINUS = 268,
     TIMES = 269,
     DIVIDE = 270,
     COLON = 271,
     SEMICOLON = 272,
     COMMA = 273,
     LEFT_BRACES = 274,
     RIGHT_BRACES = 275,
     LEFT_SQUARE = 276,
     RIGHT_SQUARE = 277,
     LEFT_PARENTHESIS = 278,
     RIGHT_PARENTHESIS = 279,
     NOT = 280,
     UNKNOWN = 281,
     T_TRUE = 282,
     T_FALSE = 283,
     CHARACTER = 284,
     STRINGVAL = 285,
     ID = 286,
     NUMERAL = 287,
     INTEGER = 288,
     CHAR = 289,
     BOOLEAN = 290,
     STRING = 291,
     VAR = 292,
     IF = 293,
     ELSE = 294,
     WHILE = 295,
     DO = 296,
     BREAK = 297
   };
#endif
/* Tokens.  */
#define ASSIGN 258
#define NOT_EQUAL 259
#define LESS_THAN 260
#define GREATER_THAN 261
#define LESS_OR_EQUAL 262
#define GREATER_OR_EQUAL 263
#define EQUAL_EQUAL 264
#define AND 265
#define OR 266
#define PLUS 267
#define MINUS 268
#define TIMES 269
#define DIVIDE 270
#define COLON 271
#define SEMICOLON 272
#define COMMA 273
#define LEFT_BRACES 274
#define RIGHT_BRACES 275
#define LEFT_SQUARE 276
#define RIGHT_SQUARE 277
#define LEFT_PARENTHESIS 278
#define RIGHT_PARENTHESIS 279
#define NOT 280
#define UNKNOWN 281
#define T_TRUE 282
#define T_FALSE 283
#define CHARACTER 284
#define STRINGVAL 285
#define ID 286
#define NUMERAL 287
#define INTEGER 288
#define CHAR 289
#define BOOLEAN 290
#define STRING 291
#define VAR 292
#define IF 293
#define ELSE 294
#define WHILE 295
#define DO 296
#define BREAK 297




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 26 "parser.y"
{
        int boolean;
        int tokenSecundario;
        t_attrib attributedSymbol;
}
/* Line 1529 of yacc.c.  */
#line 139 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

