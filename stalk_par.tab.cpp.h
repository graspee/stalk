
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
     LOW = 258,
     PERIOD = 259,
     ARGHOLDER = 260,
     WORDFROM_K_Q = 261,
     WORDFROM_K = 262,
     WORDSET_K_Q = 263,
     WORDSET_K = 264,
     WORDFROM_Q = 265,
     WORDFROM = 266,
     WORDSET_Q = 267,
     WORDSET = 268,
     COMBIN = 269,
     INITIAL_KEYWORD = 270,
     INITIAL_KEYWORD2 = 271,
     INITIAL_SYMBOL = 272,
     INITIAL_WORD = 273,
     KEYWORD = 274,
     KEYWORD2 = 275,
     SYMBOL = 276,
     LITERAL_HEX = 277,
     LITERAL_BIN = 278,
     LITERAL_DEC_NEG = 279,
     LITERAL_FLOAT_NEG = 280,
     LITERAL_DEC = 281,
     LITERAL_STRING = 282,
     LITERAL_FLOAT = 283,
     SYMBOL_Q = 284,
     KEYWORD_Q = 285,
     AWORD_Q_D = 286,
     AWORD_Q = 287,
     AWORD_D = 288,
     AWORD = 289,
     RB = 290,
     LB = 291,
     RCB = 292,
     LCB = 293,
     RSB = 294,
     LSB = 295
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 40 "stalk_par.y"

unsigned int uint4;
struct listliststring* lls;
struct numandstring* ns;
struct justlist* jl;



/* Line 1676 of yacc.c  */
#line 101 "stalk_par.tab.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


