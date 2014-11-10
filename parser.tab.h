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
     BOOLEAN = 258,
     BREAK = 259,
     CHAR = 260,
     DO = 261,
     ELSE = 262,
     T_FALSE = 263,
     IF = 264,
     INTEGER = 265,
     STRING = 266,
     T_TRUE = 267,
     VAR = 268,
     WHILE = 269,
     ASSIGN = 270,
     COLON = 271,
     COMMA = 272,
     NOT_EQUAL = 273,
     LESS_THAN = 274,
     GREATER_THAN = 275,
     LESS_OR_EQUAL = 276,
     GREATER_OR_EQUAL = 277,
     EQUAL_EQUAL = 278,
     AND = 279,
     OR = 280,
     PLUS = 281,
     MINUS = 282,
     TIMES = 283,
     DIVIDE = 284,
     PLUS_PLUS = 285,
     MINUS_MINUS = 286,
     SEMICOLON = 287,
     LEFT_BRACES = 288,
     RIGHT_BRACES = 289,
     LEFT_SQUARE = 290,
     RIGHT_SQUARE = 291,
     LEFT_PARENTHESIS = 292,
     RIGHT_PARENTHESIS = 293,
     NOT = 294,
     CHARACTER = 295,
     STRINGVAL = 296,
     ID = 297,
     NUMERAL = 298,
     _EOF = 299,
     UNKNOWN = 300
   };
#endif
/* Tokens.  */
#define BOOLEAN 258
#define BREAK 259
#define CHAR 260
#define DO 261
#define ELSE 262
#define T_FALSE 263
#define IF 264
#define INTEGER 265
#define STRING 266
#define T_TRUE 267
#define VAR 268
#define WHILE 269
#define ASSIGN 270
#define COLON 271
#define COMMA 272
#define NOT_EQUAL 273
#define LESS_THAN 274
#define GREATER_THAN 275
#define LESS_OR_EQUAL 276
#define GREATER_OR_EQUAL 277
#define EQUAL_EQUAL 278
#define AND 279
#define OR 280
#define PLUS 281
#define MINUS 282
#define TIMES 283
#define DIVIDE 284
#define PLUS_PLUS 285
#define MINUS_MINUS 286
#define SEMICOLON 287
#define LEFT_BRACES 288
#define RIGHT_BRACES 289
#define LEFT_SQUARE 290
#define RIGHT_SQUARE 291
#define LEFT_PARENTHESIS 292
#define RIGHT_PARENTHESIS 293
#define NOT 294
#define CHARACTER 295
#define STRINGVAL 296
#define ID 297
#define NUMERAL 298
#define _EOF 299
#define UNKNOWN 300




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 26 "parser.y"
{
        int boolean;
        int tokenSecundario;
        t_attrib attributedSymbol;
}
/* Line 1529 of yacc.c.  */
#line 145 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

