/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    OR_OPERATOR = 260,
    AND_OPERATOR = 261,
    BITWISE_OR_OPERATOR = 262,
    CARET_OPERATOR = 263,
    BITWISE_AND_OPERATOR = 264,
    EQUAL_COMPARATOR = 265,
    NOT_EQUAL_COMPARATOR = 266,
    LESSER_THAN_OR_EQUAL_TO = 267,
    LESSER_THAN = 268,
    GREATER_THAN_OR_EQUAL_TO = 269,
    GREATER_THAN = 270,
    LEFT_SHIFT_OPERATOR = 271,
    RIGHT_SHIFT_OPERATOR = 272,
    ADD = 273,
    SUBTRACT = 274,
    MULTIPLICATION_OPERATOR = 275,
    DIVISION = 276,
    MODULO = 277,
    LEFT_SHIFT_ASSIGNMENT_OPERATOR = 278,
    RIGHT_SHIFT_ASSIGNMENT_OPERATOR = 279,
    XOR_ASSIGNMENT_OPERATOR = 280,
    OR_ASSIGNMENT_OPERATOR = 281,
    AND_ASSIGNMENT_OPERATOR = 282,
    MODULO_ASSIGNMENT_OPERATOR = 283,
    MULTIPLICATION_ASSIGNMENT_OPERATOR = 284,
    DIVISION_ASSIGNMENT_OPERATOR = 285,
    ADD_ASSIGNMENT_OPERATOR = 286,
    SUBTRACTION_ASSIGNMENT_OPERATOR = 287,
    ASSIGNMENT_OPERATOR = 288,
    SIZEOF = 289,
    SEMICOLON_DELIMITER = 290,
    COLON = 291,
    COMMA_DELIMITER = 292,
    OPEN_BRACES = 293,
    CLOSE_BRACES = 294,
    OPEN_BRACKET = 295,
    CLOSE_BRACKET = 296,
    OPEN_SQUARE = 297,
    CLOSE_SQUARE = 298,
    RETURN = 299,
    MAIN_FUNCTION = 300,
    INT = 301,
    SHORT = 302,
    LONG = 303,
    LONG_LONG = 304,
    FLOAT = 305,
    CHAR = 306,
    DOUBLE = 307,
    SIGNED = 308,
    UNSIGNED = 309,
    STRUCT = 310,
    BREAK = 311,
    CONTINUE = 312,
    VOID = 313,
    WHILE = 314,
    FOR = 315,
    DO = 316,
    SWITCH = 317,
    CASE = 318,
    DEFAULT = 319,
    IDENTIFIER = 320,
    INVALID_INTEGER = 321,
    INVALID_FLOAT = 322,
    INVALID_CHARACTER = 323,
    INVALID_STRING = 324,
    ILLEGAL_TOKEN = 325,
    INTEGER_CONSTANT = 326,
    STRING_CONSTANT = 327,
    FLOAT_CONSTANT = 328,
    CHARACTER_CONSTANT = 329,
    PREPROCESSOR_DIRECTIVE = 330,
    MACRO = 331,
    BITWISE_COMPLEMENT_OPERATOR = 332,
    EXCLAMATION_OPERATOR = 333,
    INCREMENT_OPERATOR = 334,
    DECREMENT_OPERATOR = 335
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define OR_OPERATOR 260
#define AND_OPERATOR 261
#define BITWISE_OR_OPERATOR 262
#define CARET_OPERATOR 263
#define BITWISE_AND_OPERATOR 264
#define EQUAL_COMPARATOR 265
#define NOT_EQUAL_COMPARATOR 266
#define LESSER_THAN_OR_EQUAL_TO 267
#define LESSER_THAN 268
#define GREATER_THAN_OR_EQUAL_TO 269
#define GREATER_THAN 270
#define LEFT_SHIFT_OPERATOR 271
#define RIGHT_SHIFT_OPERATOR 272
#define ADD 273
#define SUBTRACT 274
#define MULTIPLICATION_OPERATOR 275
#define DIVISION 276
#define MODULO 277
#define LEFT_SHIFT_ASSIGNMENT_OPERATOR 278
#define RIGHT_SHIFT_ASSIGNMENT_OPERATOR 279
#define XOR_ASSIGNMENT_OPERATOR 280
#define OR_ASSIGNMENT_OPERATOR 281
#define AND_ASSIGNMENT_OPERATOR 282
#define MODULO_ASSIGNMENT_OPERATOR 283
#define MULTIPLICATION_ASSIGNMENT_OPERATOR 284
#define DIVISION_ASSIGNMENT_OPERATOR 285
#define ADD_ASSIGNMENT_OPERATOR 286
#define SUBTRACTION_ASSIGNMENT_OPERATOR 287
#define ASSIGNMENT_OPERATOR 288
#define SIZEOF 289
#define SEMICOLON_DELIMITER 290
#define COLON 291
#define COMMA_DELIMITER 292
#define OPEN_BRACES 293
#define CLOSE_BRACES 294
#define OPEN_BRACKET 295
#define CLOSE_BRACKET 296
#define OPEN_SQUARE 297
#define CLOSE_SQUARE 298
#define RETURN 299
#define MAIN_FUNCTION 300
#define INT 301
#define SHORT 302
#define LONG 303
#define LONG_LONG 304
#define FLOAT 305
#define CHAR 306
#define DOUBLE 307
#define SIGNED 308
#define UNSIGNED 309
#define STRUCT 310
#define BREAK 311
#define CONTINUE 312
#define VOID 313
#define WHILE 314
#define FOR 315
#define DO 316
#define SWITCH 317
#define CASE 318
#define DEFAULT 319
#define IDENTIFIER 320
#define INVALID_INTEGER 321
#define INVALID_FLOAT 322
#define INVALID_CHARACTER 323
#define INVALID_STRING 324
#define ILLEGAL_TOKEN 325
#define INTEGER_CONSTANT 326
#define STRING_CONSTANT 327
#define FLOAT_CONSTANT 328
#define CHARACTER_CONSTANT 329
#define PREPROCESSOR_DIRECTIVE 330
#define MACRO 331
#define BITWISE_COMPLEMENT_OPERATOR 332
#define EXCLAMATION_OPERATOR 333
#define INCREMENT_OPERATOR 334
#define DECREMENT_OPERATOR 335

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
