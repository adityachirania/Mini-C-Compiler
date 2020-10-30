/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

	#include "stdlib.h"
	#include "string.h"
	#include "stdio.h"
	#include "ctype.h"
	#include <malloc.h>

	int number_of_functions_defined = 0;
	char last_function[100];

	void type_insert();
	void insert_symbol_type_proxy(char *,char *);
	void print_constant_table_proxy(void);
	void print_symbol_table_proxy(void);
	void insert_symbol_class_proxy(char *);
	void insert_symbol_array_dimension_proxy(int);
	void insert_arg_list_proxy(char *, char *);
	void append_star_proxy(char *);
	char* get_type_proxy(char *, int);
	void insert_arglist_type_proxy(char *, char**);
	char* get_arg_type_proxy(char *, int );

	void push(char *);
	void start_pop(void);
	void pop(void);
	int check_present_proxy(void);	
	void insert_start_line(int, char *);
	void insert_end_line(int, char *);
	void nesting_insert(int);
	int check_present_function_proxy(char *);
	int check_present_identifier_proxy(char *, int);

	void yyerror(char* s);
	int yylex();

	extern FILE *yyin;
	extern int yylineno;
	extern char *yytext;
	extern char cur_symbol[100];
	extern char cur_type[100];
	extern char cur_value[100];

	char cur_fun_type[100];
	char symbol_stack[100][100];
	char cur_fun[100];
	char arglist[1000];
	char arglist_type[100][100];
	int arglist_type_ptr = 0;
	int line_stack[100];
	int top=-1;
	int cur_line;
	int cur_open_line;
	int error_flag=0;
	int pointer_flag = 0;
	int nesting = 0;

	// DS with all function informantion
	struct func
	{
		char name[100];
		int no_of_parameters;
		char type[50];
	} functions_list[50];
	int functions_list_ptr = 0;
	// 20 should be enough :)
	// 50 don't be kanjoos

	struct id_type
	{
		char name[100];
		char type[50];
	} identifiers_type_list[500];
	int identifiers_type_list_ptr = 0;

	// extern struct_symbol_table_entry *identifiers_list;

#line 143 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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

union YYSTYPE
{
#line 79 "parser.y" /* yacc.c:355  */

	struct
	{
		// Actual values
		int Integer;
		char String[100];
		float Float;
		char Char;

		// operation
		char Op[10];

		// status var
		// Multipurpose variable
		// Can be used to store any kind
		// of status information
		int Status;

		// type of data
		char Type[50];
	}

#line 366 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 383 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   390

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  175
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  290

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   335

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    81,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   147,   147,   150,   154,   155,   159,   160,   161,   162,
     163,   169,   186,   204,   205,   210,   227,   250,   250,   257,
     258,   264,   265,   270,   275,   276,   282,   281,   290,   299,
     304,   311,   312,   313,   317,   318,   322,   322,   327,   326,
     340,   341,   345,   346,   351,   354,   355,   356,   359,   360,
     367,   367,   372,   373,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   390,   391,   392,   393,   396,   397,   398,
     399,   402,   403,   406,   407,   413,   423,   431,   435,   439,
     443,   447,   451,   455,   459,   463,   467,   471,   475,   476,
     480,   500,   513,   521,   542,   555,   563,   568,   576,   610,
     618,   636,   644,   668,   676,   681,   685,   689,   693,   696,
     699,   700,   703,   710,   717,   729,   737,   740,   743,   747,
     751,   759,   774,   783,   794,   797,   802,   807,   812,   822,
     823,   826,   827,   828,   831,   832,   833,   834,   835,   836,
     842,   843,   844,   845,   846,   847,   848,   849,   850,   854,
     855,   859,   859,   863,   864,   868,   869,   874,   878,   879,
     883,   883,   887,   888,   892,   893,   897,   898,   899,   903,
     908,   907,   915,   919,   926,   926
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "OR_OPERATOR",
  "AND_OPERATOR", "BITWISE_OR_OPERATOR", "CARET_OPERATOR",
  "BITWISE_AND_OPERATOR", "EQUAL_COMPARATOR", "NOT_EQUAL_COMPARATOR",
  "LESSER_THAN_OR_EQUAL_TO", "LESSER_THAN", "GREATER_THAN_OR_EQUAL_TO",
  "GREATER_THAN", "LEFT_SHIFT_OPERATOR", "RIGHT_SHIFT_OPERATOR", "ADD",
  "SUBTRACT", "MULTIPLICATION_OPERATOR", "DIVISION", "MODULO",
  "LEFT_SHIFT_ASSIGNMENT_OPERATOR", "RIGHT_SHIFT_ASSIGNMENT_OPERATOR",
  "XOR_ASSIGNMENT_OPERATOR", "OR_ASSIGNMENT_OPERATOR",
  "AND_ASSIGNMENT_OPERATOR", "MODULO_ASSIGNMENT_OPERATOR",
  "MULTIPLICATION_ASSIGNMENT_OPERATOR", "DIVISION_ASSIGNMENT_OPERATOR",
  "ADD_ASSIGNMENT_OPERATOR", "SUBTRACTION_ASSIGNMENT_OPERATOR",
  "ASSIGNMENT_OPERATOR", "SIZEOF", "SEMICOLON_DELIMITER", "COLON",
  "COMMA_DELIMITER", "OPEN_BRACES", "CLOSE_BRACES", "OPEN_BRACKET",
  "CLOSE_BRACKET", "OPEN_SQUARE", "CLOSE_SQUARE", "RETURN",
  "MAIN_FUNCTION", "INT", "SHORT", "LONG", "LONG_LONG", "FLOAT", "CHAR",
  "DOUBLE", "SIGNED", "UNSIGNED", "STRUCT", "BREAK", "CONTINUE", "VOID",
  "WHILE", "FOR", "DO", "SWITCH", "CASE", "DEFAULT", "IDENTIFIER",
  "INVALID_INTEGER", "INVALID_FLOAT", "INVALID_CHARACTER",
  "INVALID_STRING", "ILLEGAL_TOKEN", "INTEGER_CONSTANT", "STRING_CONSTANT",
  "FLOAT_CONSTANT", "CHARACTER_CONSTANT", "PREPROCESSOR_DIRECTIVE",
  "MACRO", "BITWISE_COMPLEMENT_OPERATOR", "EXCLAMATION_OPERATOR",
  "INCREMENT_OPERATOR", "DECREMENT_OPERATOR", "'.'", "$accept", "source",
  "declaration_list", "declaration_list_continuation", "declaration",
  "function_declaration", "function_name", "function_parameters",
  "parameters_list", "param_identifier", "@1",
  "parameter_identifier_array_check", "variable_declaration",
  "variable_declaration_list", "variable_declaration_list_continuation",
  "single_element_declaration", "$@2", "array_declaration",
  "first_dimension", "other_dimension", "array_dimension_without_integer",
  "$@3", "array_dimension_with_integer", "$@4", "initilization",
  "initilization_continuation", "array_initialization", "array_item_list",
  "array_item_list_continuation", "structure_definition", "$@5",
  "struct_variable_declaration", "type_specifier", "unsigned", "signed",
  "short", "long", "expression", "assignment_type", "simple_expression",
  "simple_expression_end", "and_expression", "and_expression_end",
  "unary_relational_expression", "relational_expression", "sum_of_factors",
  "factor", "factor_continuation", "size_of", "size_of_continuation",
  "address_of", "value_of", "assignable", "assignable_end", "fixed_value",
  "function_call", "arguments_list", "constant", "sum_operators",
  "multiplicative_operators", "relational_operators", "statement",
  "statement_list", "compound_statement", "$@6", "expression_statement",
  "conditional_statements", "if_statement", "else_part",
  "switch_statement", "$@7", "case_statements",
  "case_statements_continuation", "loop_statement", "for_statement",
  "while_statement", "$@8", "do_while_statement", "return_statement",
  "$@9", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,    46
};
# endif

#define YYPACT_NINF -215

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-215)))

#define YYTABLE_NINF -37

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,  -215,   -26,   -18,  -215,  -215,  -215,    24,    39,   -48,
    -215,  -215,  -215,    37,  -215,    -7,  -215,  -215,  -215,   -16,
    -215,  -215,  -215,  -215,  -215,   -26,   -18,  -215,  -215,   -26,
     -18,  -215,    -5,  -215,  -215,  -215,    -5,    17,    21,    27,
      29,  -215,  -215,  -215,  -215,  -215,    40,    26,  -215,    36,
      89,   193,  -215,    -5,  -215,  -215,   302,   -29,    47,  -215,
      52,    23,    41,    32,    32,    58,  -215,  -215,   253,   114,
      35,    80,    76,    77,   193,    78,    81,  -215,  -215,  -215,
    -215,  -215,  -215,   253,  -215,    -5,    91,  -215,   119,   121,
    -215,   146,    10,  -215,  -215,  -215,  -215,   309,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,   302,    90,  -215,  -215,    86,    88,    86,
      18,  -215,  -215,  -215,    96,   253,  -215,   -31,   -31,   238,
     193,    97,  -215,  -215,    -5,  -215,   253,   253,    87,   253,
     253,  -215,   -31,  -215,   253,  -215,   253,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,   135,   135,  -215,  -215,
    -215,   135,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,  -215,  -215,    85,  -215,  -215,  -215,
     110,   108,    82,  -215,  -215,  -215,   241,  -215,  -215,  -215,
     120,   315,   126,  -215,   127,   -31,   193,   131,  -215,   136,
    -215,   137,   133,   139,   147,   142,   119,   121,    10,    16,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,   148,  -215,  -215,  -215,    86,   241,   151,   156,
     152,  -215,  -215,   193,  -215,  -215,  -215,  -215,   157,   253,
     253,   138,   253,  -215,  -215,  -215,  -215,  -215,   158,  -215,
     241,  -215,   120,   170,   193,   164,   160,  -215,  -215,   156,
    -215,  -215,   193,  -215,  -215,   253,   177,    -9,  -215,  -215,
     173,  -215,   253,   169,   176,   193,   180,   193,  -215,  -215,
     193,   154,    -9,   253,  -215,  -215,   182,   193,   154,  -215
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    54,    72,    74,    55,    57,    56,    70,    66,     0,
      62,     9,    10,     0,     2,     5,     6,     7,     8,     0,
      71,    60,    73,    61,    67,    72,    74,    59,    63,    72,
      74,    58,    50,     1,     4,     3,     0,    26,     0,     0,
      25,    68,    69,    64,    65,    26,     0,     0,    28,    30,
       0,     0,    21,     0,    23,    22,    53,    33,    41,    14,
       0,     0,     0,     0,     0,     0,   154,   151,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   125,   126,   127,
     128,   147,   148,     0,   145,     0,     0,    76,    92,    95,
      97,    99,   101,   103,   106,   107,   108,   105,   104,   119,
     120,    11,   142,   140,   141,   155,   156,   143,   166,   167,
     168,   144,    24,    53,     0,    38,    29,    35,     0,    35,
       0,    27,    13,    17,    16,     0,   114,   112,   113,     0,
     150,     0,   173,   174,     0,   146,     0,     0,     0,     0,
     124,    96,   105,   153,     0,    90,     0,    93,   139,   138,
     135,   136,   134,   137,   129,   130,     0,     0,   131,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,     0,    75,   115,    52,
       0,     0,     0,    32,    37,    31,    47,    40,    42,    43,
      20,     0,     0,   111,     0,   110,   150,     0,   118,     0,
     170,     0,     0,     0,   123,     0,    92,    95,   100,    98,
     102,    83,    84,    87,    86,    85,    82,    81,    80,    78,
      79,    77,     0,   117,    51,    39,    35,    47,     0,    49,
       0,    18,    15,     0,   109,   149,   152,   175,     0,     0,
       0,     0,   124,   121,    91,    94,   116,    34,     0,    44,
      47,    46,    20,   159,     0,     0,     0,   160,   122,    49,
      48,    19,     0,   157,   171,     0,     0,     0,    45,   158,
       0,   172,     0,     0,     0,     0,     0,     0,   161,   169,
       0,   165,     0,     0,   163,   162,     0,     0,   165,   164
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -215,  -215,   204,  -215,  -215,  -215,  -215,  -215,    31,  -215,
    -215,   -32,     9,   -20,  -215,   187,  -215,  -215,  -215,  -113,
    -215,  -215,    43,  -215,  -215,  -215,  -215,  -214,   -27,  -215,
    -215,   117,     3,  -215,  -215,    -3,    -1,   -61,  -215,  -120,
      28,    94,    49,   -73,  -215,   100,    79,    98,  -215,  -215,
    -215,  -215,   -62,  -215,  -215,  -215,     0,  -215,  -215,  -215,
    -215,   -51,    64,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,   -19,   -14,  -215,  -215,  -215,  -215,  -215,  -215,  -215
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    35,    15,    16,    38,    51,    60,   124,
     190,   231,    84,    39,    54,    40,    49,    58,   116,   183,
     117,   118,   119,   181,   121,   187,   188,   228,   251,    18,
      47,   114,    85,    31,    27,    21,    23,    86,   177,    87,
     145,    88,   147,    89,    90,    91,    92,    93,    94,   194,
      95,    96,    97,   178,    98,    99,   205,   100,   156,   161,
     157,   196,   197,   102,   130,   103,   104,   105,   263,   106,
     267,   274,   284,   107,   108,   109,   238,   110,   111,   199
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     101,   127,   128,    19,    36,   192,   185,   131,   133,    17,
     141,   173,    46,   248,   -36,    36,   200,    32,    19,   203,
      20,   142,    41,   138,    17,    42,    43,    63,    22,    44,
     158,   159,   160,   112,   154,   155,   260,    33,    64,     1,
       2,     3,   115,     4,     5,     6,     7,     8,     9,    37,
     176,    10,    65,    61,   272,   273,   186,   -12,    68,   189,
      45,    50,    52,   142,    56,   113,    53,   195,    11,    12,
      24,    25,    26,   207,   142,    55,   201,   142,    57,   204,
     120,   125,   142,    76,   142,    28,    29,    30,   123,    77,
      78,    79,    80,   122,   142,   142,    83,   126,   129,   142,
     134,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   247,    46,   135,   136,   137,   139,   255,
     256,   140,   113,    63,   144,   229,   143,   146,   182,   180,
      59,   184,   193,   191,    64,     1,     2,     3,   198,     4,
       5,     6,     7,     8,    63,   224,   202,    10,    65,   132,
     223,   225,   276,   115,    68,    64,   148,   149,   150,   151,
     152,   153,   230,   286,   154,   155,   229,   233,   234,    65,
     236,   237,   239,   240,   262,    68,   257,   142,   142,    76,
     241,   204,   253,   243,   242,    77,    78,    79,    80,   229,
     249,   246,    83,   250,    61,   252,    62,   259,   254,   265,
      76,   266,    63,   264,   270,   277,    77,    78,    79,    80,
     142,   269,   271,    64,   275,   278,   280,   283,   287,    34,
     261,   142,   232,    48,   279,   226,   281,    65,    66,   282,
     179,    67,   268,    68,   244,   208,   288,    69,   206,     1,
       2,     3,   258,     4,     5,     6,     7,     8,    70,    71,
      63,    10,    72,    73,    74,    75,   245,   209,    76,   210,
     235,    64,    63,   285,    77,    78,    79,    80,    81,    82,
       0,    83,     0,    64,   289,    65,     0,     0,     0,   227,
       0,    68,     0,     0,     1,     2,     3,    65,     4,     5,
       6,     7,     8,    68,     0,     0,    10,     0,     0,     0,
       0,     0,     0,   126,     0,     0,    76,     0,     0,     0,
       0,     0,    77,    78,    79,    80,     0,     0,    76,    83,
       0,     0,     0,     0,    77,    78,    79,    80,     0,     0,
       0,    83,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,     0,     0,     0,     0,     1,     2,
       3,   173,     4,     5,     6,     7,     8,    70,     0,     0,
      10,     1,     2,     3,     0,     4,     5,     6,     7,     8,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   174,   175,
     176
};

static const yytype_int16 yycheck[] =
{
      51,    63,    64,     0,    20,   125,   119,    68,    69,     0,
      83,    42,    32,   227,    43,    20,   136,    65,    15,   139,
      46,    83,    25,    74,    15,    26,    29,     9,    46,    30,
      20,    21,    22,    53,    18,    19,   250,     0,    20,    46,
      47,    48,    71,    50,    51,    52,    53,    54,    55,    65,
      81,    58,    34,    50,    63,    64,    38,    40,    40,   120,
      65,    40,    35,   125,    38,    56,    37,   129,    75,    76,
      46,    47,    48,   146,   136,    35,   137,   139,    42,   140,
      33,    40,   144,    65,   146,    46,    47,    48,    65,    71,
      72,    73,    74,    41,   156,   157,    78,    65,    40,   161,
      65,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   226,   134,    35,    40,    40,    40,   239,
     240,    40,   113,     9,     5,   186,    35,     6,    42,    39,
      41,    43,   129,    37,    20,    46,    47,    48,    41,    50,
      51,    52,    53,    54,     9,    35,    59,    58,    34,    35,
      65,    43,   272,    71,    40,    20,    10,    11,    12,    13,
      14,    15,    42,   283,    18,    19,   227,    41,    41,    34,
      39,    35,    35,    40,     4,    40,    38,   239,   240,    65,
      41,   242,   233,    41,    37,    71,    72,    73,    74,   250,
      39,    43,    78,    37,   191,    43,     3,    39,    41,    35,
      65,    41,     9,   254,   265,    36,    71,    72,    73,    74,
     272,   262,    35,    20,    41,    39,    36,    63,    36,    15,
     252,   283,   191,    36,   275,   182,   277,    34,    35,   280,
     113,    38,   259,    40,   206,   156,   287,    44,   144,    46,
      47,    48,   242,    50,    51,    52,    53,    54,    55,    56,
       9,    58,    59,    60,    61,    62,   207,   157,    65,   161,
     196,    20,     9,   282,    71,    72,    73,    74,    75,    76,
      -1,    78,    -1,    20,   288,    34,    -1,    -1,    -1,    38,
      -1,    40,    -1,    -1,    46,    47,    48,    34,    50,    51,
      52,    53,    54,    40,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    65,    78,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    78,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    42,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,
      81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    47,    48,    50,    51,    52,    53,    54,    55,
      58,    75,    76,    83,    84,    86,    87,    94,   111,   114,
      46,   117,    46,   118,    46,    47,    48,   116,    46,    47,
      48,   115,    65,     0,    84,    85,    20,    65,    88,    95,
      97,   117,   118,   117,   118,    65,    95,   112,    97,    98,
      40,    89,    35,    37,    96,    35,    38,    42,    99,    41,
      90,   114,     3,     9,    20,    34,    35,    38,    40,    44,
      55,    56,    59,    60,    61,    62,    65,    71,    72,    73,
      74,    75,    76,    78,    94,   114,   119,   121,   123,   125,
     126,   127,   128,   129,   130,   132,   133,   134,   136,   137,
     139,   143,   145,   147,   148,   149,   151,   155,   156,   157,
     159,   160,    95,    94,   113,    71,   100,   102,   103,   104,
      33,   106,    41,    65,    91,    40,    65,   134,   134,    40,
     146,   119,    35,   119,    65,    35,    40,    40,   143,    40,
      40,   125,   134,    35,     5,   122,     6,   124,    10,    11,
      12,    13,    14,    15,    18,    19,   140,   142,    20,    21,
      22,   141,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    42,    79,    80,    81,   120,   135,   113,
      39,   105,    42,   101,    43,   101,    38,   107,   108,   119,
      92,    37,   121,   114,   131,   134,   143,   144,    41,   161,
     121,   119,    59,   121,   119,   138,   123,   125,   128,   127,
     129,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,    65,    35,    43,   104,    38,   109,   119,
      42,    93,    90,    41,    41,   144,    39,    35,   158,    35,
      40,    41,    37,    41,   122,   124,    43,   101,   109,    39,
      37,   110,    43,   143,    41,   121,   121,    38,   138,    39,
     109,    93,     4,   150,   143,    35,    41,   152,   110,   143,
     119,    35,    63,    64,   153,    41,   121,    36,    39,   143,
      36,   143,   143,    63,   154,   153,   121,    36,   143,   154
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    85,    85,    86,    86,    86,    86,
      86,    87,    88,    89,    89,    90,    90,    92,    91,    93,
      93,    94,    94,    95,    96,    96,    98,    97,    97,    99,
      99,   100,   100,   100,   101,   101,   103,   102,   105,   104,
     106,   106,   107,   107,   108,   109,   109,   109,   110,   110,
     112,   111,   113,   113,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   115,   115,   115,   115,   116,   116,   116,
     116,   117,   117,   118,   118,   119,   119,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     121,   122,   122,   123,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   129,   129,   129,   129,   129,   130,
     131,   131,   132,   133,   134,   134,   135,   135,   136,   136,
     136,   137,   138,   138,   138,   139,   139,   139,   139,   140,
     140,   141,   141,   141,   142,   142,   142,   142,   142,   142,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   144,
     144,   146,   145,   147,   147,   148,   148,   149,   150,   150,
     152,   151,   153,   153,   154,   154,   155,   155,   155,   156,
     158,   157,   159,   160,   161,   160
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     1,     1,     1,     1,
       1,     4,     1,     3,     2,     4,     2,     0,     3,     3,
       0,     3,     4,     2,     2,     0,     0,     4,     2,     2,
       0,     2,     2,     0,     3,     0,     0,     2,     0,     3,
       2,     0,     1,     1,     3,     4,     2,     0,     2,     0,
       0,     7,     2,     0,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     2,     2,     0,     1,     2,     2,
       0,     1,     0,     1,     0,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       2,     3,     0,     2,     3,     0,     2,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     4,
       1,     1,     2,     2,     1,     2,     3,     2,     3,     1,
       1,     4,     3,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     2,
       0,     0,     4,     2,     1,     1,     1,     6,     2,     0,
       0,     8,     5,     4,     5,     0,     1,     1,     1,     9,
       0,     6,     7,     2,     0,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 11:
#line 170 "parser.y" /* yacc.c:1646  */
    {
				strcpy(last_function, (yyvsp[-2].String));
				number_of_functions_defined += 1;
				// strcpy($<Type>$2, $<Type>1);

				// Update functions_list

				strcpy(functions_list[functions_list_ptr].type, (yyvsp[-3].Type));
				strcpy(functions_list[functions_list_ptr].name, (yyvsp[-2].String));
				functions_list[functions_list_ptr].no_of_parameters = (yyvsp[-1].Status);

				functions_list_ptr++;
			}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 186 "parser.y" /* yacc.c:1646  */
    {
				if(check_present_function_proxy(cur_symbol)) {
					printf("Line\:%d Semantic error\: Function already defined\n", yylineno);
					exit(1);
				}
				class_insert("FUNCTION");
				strcpy(cur_fun_type, cur_type);
				type_insert((yyvsp[0].String));
				strcpy(cur_fun, cur_symbol);

				// update function name
				strcpy((yyval.String), (yyvsp[0].String));

				// nesting_insert(nesting);
			}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 204 "parser.y" /* yacc.c:1646  */
    {(yyval.Status) = (yyvsp[-1].Status);}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 205 "parser.y" /* yacc.c:1646  */
    {(yyval.Status) = 0;}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 211 "parser.y" /* yacc.c:1646  */
    {
				if(strcmp((yyvsp[-3].Type), "void") == 0) {
					printf("Line\:%d Semantic error\: Param of type void\n", yylineno);
					exit(1);
				}
				char cpy[100];
				strcpy(cpy, (yyvsp[-2].String));
				sprintf(cpy, "%s,%s", (yyvsp[-2].String), arglist);
				strcpy(arglist, cpy);
				insert_arg_list_proxy(cur_fun, arglist);
				strcpy(arglist_type[arglist_type_ptr++], (yyvsp[-3].Type));
				insert_arglist_type_proxy(cur_fun, arglist_type);

				// for computing no of args
				(yyval.Status) = 1 + (yyvsp[0].Status);
			}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 228 "parser.y" /* yacc.c:1646  */
    {
				if(strcmp(cur_type, "void") == 0) {
					printf("Line\:%d Semantic error\: Param of type void\n", yylineno);
					exit(1);
				}
				arglist[0] = '\0';
				char cpy[100];
				strcpy(cpy, (yyvsp[0].String));
				strcat(arglist, cpy);
				// printf("2 %s\n", arglist);
				
				// Arglist will be stored in reverse order
				arglist_type_ptr = 0;
				strcpy(arglist_type[arglist_type_ptr++], (yyvsp[-1].Type));
				insert_arglist_type_proxy(cur_fun, arglist_type);

				// for computing number of args
				(yyval.Status) = 1;
			}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 250 "parser.y" /* yacc.c:1646  */
    { 
				(yyval.Integer) = 1;
				type_insert((yyvsp[0].String)); 
			}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 282 "parser.y" /* yacc.c:1646  */
    { 
				type_insert((yyvsp[0].String)); 
				push((yyvsp[0].String)); 
				pointer_flag = 0;  
				nesting_insert(nesting);
				strcat(identifiers_type_list[identifiers_type_list_ptr].type, cur_type);
				strcpy(identifiers_type_list[identifiers_type_list_ptr].name, (yyvsp[0].String));
			}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 291 "parser.y" /* yacc.c:1646  */
    {
				type_insert((yyvsp[-1].String));
				pointer_flag++;
			}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 300 "parser.y" /* yacc.c:1646  */
    {
				identifiers_type_list_ptr++;
			}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 304 "parser.y" /* yacc.c:1646  */
    {
				identifiers_type_list_ptr++;
			}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 322 "parser.y" /* yacc.c:1646  */
    {array_dim_insert(1);}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 327 "parser.y" /* yacc.c:1646  */
    {
				array_dim_insert(0);
				
				// Array size should be more than 1
				int size = atoi(cur_value);
				if(size < 1) {
					print_semantic_error("Array size less than 1");
				}
			}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 367 "parser.y" /* yacc.c:1646  */
    { 
				type_insert((yyvsp[-1].String)); 
				class_insert();
			}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 379 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Type), (yyvsp[0].Type));}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 380 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Type), (yyvsp[0].Type));}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 381 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Type), (yyvsp[0].Type));}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 382 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Type), (yyvsp[0].Type));}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 387 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Type), (yyvsp[0].Type));}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 406 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Type), (yyvsp[0].Type));}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 414 "parser.y" /* yacc.c:1646  */
    {
				if(strcmp( (yyvsp[-1].Type), "") && strcmp( (yyvsp[0].Type), "") && strcmp((yyvsp[-1].Type), (yyvsp[0].Type)) != 0) {
					printf("Line %d\: Semantic error\: %s and %s are not compatible\n", yylineno, (yyvsp[-1].Type), (yyvsp[0].Type));
					exit(1);
				}
				else {
					strcpy((yyval.Type), (yyvsp[0].Type));
				}
			}
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 424 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 432 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 436 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 440 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 444 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 448 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 452 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 456 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 460 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 464 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 468 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 472 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 481 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[0].Status) == 1)
				{
					(yyval.Integer) = ((yyvsp[-1].Integer) || (yyvsp[0].Integer));
				}
				else
				{
					(yyval.Integer) = (yyvsp[-1].Integer);
				}
				if (strcmp( (yyvsp[-1].Type), "") && strcmp( (yyvsp[0].Type), "") &&strcmp((yyvsp[-1].Type), (yyvsp[0].Type)) != 0) {
					printf("Line %d\: Semantic error\: %s and %s are not compatible\n", yylineno, (yyvsp[-1].Type), (yyvsp[0].Type));
					exit(1);
				}
				else {
					strcpy((yyval.Type), (yyvsp[-1].Type));
				}
			}
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 501 "parser.y" /* yacc.c:1646  */
    {
				(yyval.Integer) = ((yyvsp[-1].Integer) || (yyvsp[0].Integer));
				(yyval.Status) = 1;
				if(strcmp( (yyvsp[-1].Type), "") && strcmp( (yyvsp[0].Type), "") &&strcmp((yyvsp[-1].Type), (yyvsp[0].Type)) != 0) {
					printf("Line %d\: Semantic error\: %s and %s are not compatible\n", yylineno, (yyvsp[-1].Type), (yyvsp[0].Type));
					exit(1);
				}
				else {
					strcpy((yyval.Type), (yyvsp[-1].Type));
				}
			}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 513 "parser.y" /* yacc.c:1646  */
    {
				(yyval.Integer) = 0; 
				(yyval.Status) = 0;
				strcpy((yyval.Type), "");
			}
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 522 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[0].Status) == 1)
				{
					(yyval.Integer) = ((yyvsp[-1].Integer) && (yyvsp[0].Integer));
				}
				else
				{
					(yyval.Integer) = (yyvsp[-1].Integer);
				}
				if(strcmp( (yyvsp[-1].Type), "") && strcmp( (yyvsp[0].Type), "") &&strcmp((yyvsp[-1].Type), (yyvsp[0].Type)) != 0) {
					printf("Line %d\: Semantic error\: %s and %s are not compatible\n", yylineno, (yyvsp[-1].Type), (yyvsp[0].Type));
					exit(1);
				}
				else {
					strcpy((yyval.Type), (yyvsp[-1].Type));
				}
			}
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 543 "parser.y" /* yacc.c:1646  */
    {
				(yyval.Integer) = ((yyvsp[-1].Integer) && (yyvsp[0].Integer));
				(yyval.Status) = 1;
				if(strcmp( (yyvsp[-1].Type), "") && strcmp( (yyvsp[0].Type), "") &&strcmp((yyvsp[-1].Type), (yyvsp[0].Type)) != 0) {
					printf("Line %d\: Semantic error\: %s and %s are not compatible\n", yylineno, (yyvsp[-2].Type), (yyvsp[0].Type));
					exit(1);
				}
				else {
					strcpy((yyval.Type), (yyvsp[-1].Type));
				}
			}
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 555 "parser.y" /* yacc.c:1646  */
    {
				(yyval.Integer) = 1; 
				(yyval.Status) = 0;
				strcpy((yyval.Type), "");
			}
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 564 "parser.y" /* yacc.c:1646  */
    {
				(yyval.Integer) = !((yyvsp[0].Integer));
				strcpy((yyval.Type), (yyvsp[-1].Type));
			}
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 569 "parser.y" /* yacc.c:1646  */
    {
				(yyval.Integer) = (yyvsp[0].Integer);
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 577 "parser.y" /* yacc.c:1646  */
    {
				if(strcmp((yyvsp[-1].Op), ">=") == 0)
				{
					(yyval.Integer) = ((yyvsp[-2].Integer) >= (yyvsp[0].Integer));
				}
				else if(strcmp((yyvsp[-1].Op), "<=") == 0)
				{
					(yyval.Integer) = ((yyvsp[-2].Integer) <= (yyvsp[0].Integer));
				}
				else if(strcmp((yyvsp[-1].Op), ">") == 0)
				{
					(yyval.Integer) = ((yyvsp[-2].Integer) > (yyvsp[0].Integer));
				}
				else if(strcmp((yyvsp[-1].Op), "<") == 0)
				{
					(yyval.Integer) = ((yyvsp[-2].Integer) < (yyvsp[0].Integer));
				}
				else if(strcmp((yyvsp[-1].Op), "!=") == 0)
				{
					(yyval.Integer) = ((yyvsp[-2].Integer) != (yyvsp[0].Integer));
				}
				else if(strcmp((yyvsp[-1].Op), "==") == 0)
				{
					(yyval.Integer) = ((yyvsp[-2].Integer) == (yyvsp[0].Integer));
				}
				if(strcmp( (yyvsp[-2].Type), "") && strcmp( (yyvsp[0].Type), "") &&strcmp((yyvsp[-2].Type), (yyvsp[0].Type)) != 0) {
					printf("Line %d\: Semantic error\: %s and %s are not compatible\n", yylineno, (yyvsp[-2].Type), (yyvsp[0].Type));
					exit(1);
				}
				else {
					strcpy((yyval.Type), (yyvsp[-2].Type));
				}
			}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 611 "parser.y" /* yacc.c:1646  */
    {
				(yyval.Integer) = (yyvsp[0].Integer); 
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 619 "parser.y" /* yacc.c:1646  */
    {
				if(strcmp((yyvsp[-1].Op), "+") == 0)
				{
					(yyval.Integer) = (yyvsp[-2].Integer) + (yyvsp[0].Integer);
				}
				else if (strcmp((yyvsp[-1].Op), "-") == 0)
				{
					(yyval.Integer) = (yyvsp[-2].Integer) - (yyvsp[0].Integer);
				}
				if(strcmp( (yyvsp[-2].Type), "") && strcmp( (yyvsp[0].Type), "") &&strcmp((yyvsp[-2].Type), (yyvsp[0].Type)) != 0) {
					printf("Line %d\: Semantic error\: %s and %s are not compatible\n", yylineno, (yyvsp[-2].Type), (yyvsp[0].Type));
					exit(1);
				}
				else {
					strcpy((yyval.Type), (yyvsp[-2].Type));
				}
			}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 637 "parser.y" /* yacc.c:1646  */
    {
				(yyval.Integer) = (yyvsp[0].Integer);
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 645 "parser.y" /* yacc.c:1646  */
    {
				if(strcmp((yyvsp[-1].Op), "*") == 0)
				{
					(yyval.Integer) = (yyvsp[-2].Integer) * (yyvsp[0].Integer);
				}
				else if (strcmp((yyvsp[-1].Op), "/") == 0)
				{
					(yyval.Integer) = (yyvsp[-2].Integer) / (yyvsp[0].Integer);
				}
				else
				{
					(yyval.Integer) = (yyvsp[-2].Integer) % (yyvsp[0].Integer);
				}
				if(strcmp((yyvsp[-2].Type), (yyvsp[0].Type)) != 0)
				{
					printf("Line %d\: Semantic error\: %s and %s are not compatible\n", yylineno, (yyvsp[-2].Type), (yyvsp[0].Type));
					exit(1);
				}
				else
				{
					strcpy((yyval.Type), (yyvsp[-2].Type));
				}
			}
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 669 "parser.y" /* yacc.c:1646  */
    {
				(yyval.Integer) = (yyvsp[0].Integer);
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 677 "parser.y" /* yacc.c:1646  */
    {
				(yyval.Integer) = (yyvsp[0].Integer);
				strcpy((yyval.Type), (yyvsp[0].Type));	
			}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 682 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 686 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), "int");
			}
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 690 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 704 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 711 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 717 "parser.y" /* yacc.c:1646  */
    {
				if(!check_present_identifier_proxy((yyvsp[0].String), yylineno)) {
					printf("Line %d\: Semantic error\: %s Variable undeclared\n", yylineno, (yyvsp[0].String));
					exit(1);
				}
				if(check_present_function_proxy((yyvsp[0].String))) {
					printf("Line %d\: Semantic error\: %s is a function\n", yylineno, (yyvsp[0].String));
					exit(1);
				}
				// printf("%s", get_type_proxy($<String>1, yylineno));
				strcpy((yyval.Type), get_type_proxy((yyvsp[0].String), yylineno));
			}
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 730 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[-1].Type));
			}
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 737 "parser.y" /* yacc.c:1646  */
    {
				check_if_single_variable(cur_symbol, yylineno);
			}
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 744 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[-1].Type));
			}
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 748 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2373 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 752 "parser.y" /* yacc.c:1646  */
    {
				(yyval.Integer) = (yyvsp[0].Integer);
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 760 "parser.y" /* yacc.c:1646  */
    {
				if(!check_present_function_proxy((yyvsp[-3].String))) 
				{
					printf("Line %d\: Semantic error\: Function is not defined\n", yylineno);
					exit(1);
				}

				check_number_of_args((yyvsp[-3].String), (yyvsp[-1].Status));
				check_type_of_args((yyvsp[-3].String));
				
				strcpy((yyval.Type), (yyvsp[-3].Type));	
			}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 775 "parser.y" /* yacc.c:1646  */
    {
				// for no of args
				(yyval.Status) = 1 + (yyvsp[0].Status);
				// printf("%s1\n", $<Type>1);

				// miggght cause some consistency issues
				strcpy(arglist_type[arglist_type_ptr++], (yyvsp[-2].Type));
			}
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 784 "parser.y" /* yacc.c:1646  */
    {
				// for no of args
				(yyval.Status) = 1;
				// check_for_argtype_mismatch($<Type>1, $<Status>$-1);
				// char req_type = get_arg_type_proxy($<Type>1 ,$<Status>$-1);
				// printf("%s2\n", $<Type>1);

				arglist_type_ptr = 0;
				strcpy(arglist_type[arglist_type_ptr++], (yyvsp[0].Type));
			}
#line 2427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 798 "parser.y" /* yacc.c:1646  */
    {
				(yyval.Integer) = (yyvsp[0].Integer);
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 803 "parser.y" /* yacc.c:1646  */
    {
				strcpy((yyval.String), (yyvsp[0].String));
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 808 "parser.y" /* yacc.c:1646  */
    {
				(yyval.Float) = (yyvsp[0].Float);
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 813 "parser.y" /* yacc.c:1646  */
    {
				(yyval.Char) = (yyvsp[0].Char);
				strcpy((yyval.Type), (yyvsp[0].Type));
			}
#line 2463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 822 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Op), (yyvsp[0].Op));}
#line 2469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 823 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Op), (yyvsp[0].Op));}
#line 2475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 826 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Op), (yyvsp[0].Op));}
#line 2481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 827 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Op), (yyvsp[0].Op));}
#line 2487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 828 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Op), (yyvsp[0].Op));}
#line 2493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 831 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Op), (yyvsp[0].Op));}
#line 2499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 832 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Op), (yyvsp[0].Op));}
#line 2505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 833 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Op), (yyvsp[0].Op));}
#line 2511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 834 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Op), (yyvsp[0].Op));}
#line 2517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 835 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Op), (yyvsp[0].Op));}
#line 2523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 836 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.Op), (yyvsp[0].Op));}
#line 2529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 859 "parser.y" /* yacc.c:1646  */
    {push("{"); nesting++; ;}
#line 2535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 859 "parser.y" /* yacc.c:1646  */
    {push("}"); nesting--; ;}
#line 2541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 883 "parser.y" /* yacc.c:1646  */
    {nesting++; ;}
#line 2547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 883 "parser.y" /* yacc.c:1646  */
    {nesting--; ;}
#line 2553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 908 "parser.y" /* yacc.c:1646  */
    {

			}
#line 2561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 919 "parser.y" /* yacc.c:1646  */
    {
				if(strcmp(cur_fun_type, "void"))
				{
					printf("Line %d\: Semantic error\: The function has to return type %s\n", yylineno, cur_fun_type);
					exit(1);
				}
			}
#line 2573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 926 "parser.y" /* yacc.c:1646  */
    {
				if(!strcmp(cur_fun_type, "void"))
				{
					printf("Line %d\: Semantic error\: The function has return type void\n", yylineno);
					exit(1);
				}
				if(strcmp(cur_fun_type, (yyvsp[0].Type)) != 0) {
					char error[100];
					sprintf(error, "Function has return type %s but it is returning %s", cur_fun_type, (yyvsp[0].Type));
					print_semantic_error(error);
				}
				// printf("%s \n",cur_fun_type);
			}
#line 2591 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2595 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 941 "parser.y" /* yacc.c:1906  */


int main(int argc , char **argv)
{
	yyin = fopen(argv[1], "r");

	yyparse();

	post_parse_check_semantic_error();

	if(error_flag == 0)
	{
		printf("Parsing Complete: Result - Valid" "\n");
		printf("%50s \n", "Symbol table");
		
		print_symbol_table_proxy();

		printf("Constant table\n");
		print_constant_table_proxy();
	}

	return 0;
}

void post_parse_check_semantic_error() {
	// Check for number of function defined
	if(number_of_functions_defined == 0) {
		printf("Line %d: Semantic error: No function defined\n", yylineno);
		exit(1);
	}

	// Check if main is last function
	if(strcmp("main", last_function)) {
		printf("Line %d: Semantic error: main is not last function defined\n", yylineno);
		exit(1);
	}
}

void print_semantic_error(char error[]) {
	printf("Line %d: Semantic error: %s\n", yylineno, error);
	exit(1);
}

void check_number_of_args(char function_name[], int no_of_args)
{
	for(int i = 0; i < functions_list_ptr; i++)
	{
		if(strcmp(function_name, functions_list[i].name) == 0)
		{
			if(no_of_args != functions_list[i].no_of_parameters)
			{
				char error[100];
				snprintf(error, 100, "Function %s given wrong number of arguements", function_name);
				print_semantic_error(error);
			}
			break;
		}
		else
		{
			// function not declared
		}
	}
}

void check_type_of_args(char function_name[]) {
	for(int i = 0; i < arglist_type_ptr; i++)
	{
		if(strcmp(get_arg_type_proxy(function_name, i), arglist_type[i]) != 0) {
			char error[100];
			sprintf(error, "Argument at %d does not match function declaration", arglist_type_ptr-i);
			print_semantic_error(error);
		}
	}
}

char* get_type_from_functions_list(char function_name[])
{
	for(int i = 0; i < functions_list_ptr; i++)
	{
		if(strcmp(function_name, functions_list[i].name) == 0)
		{
			return functions_list[i].type;
		}
	}
}

char* get_type_from_identifiers_type_list(char identifier_name[])
{
	for(int i = 0; i < identifiers_type_list_ptr; i++)
	{
		if(strcmp(identifier_name, identifiers_type_list[i].name) == 0)
		{
			return identifiers_type_list[i].type;
		}
	}
}

void check_if_single_variable(char* symbol, int yylineno) {
	char* type = get_type_proxy(symbol, yylineno);
	if(!strchr(type, '[')) {
		char error[20];
		sprintf(error ,"%s is a single variable type", symbol);
		print_semantic_error(error);
	}
}

void class_insert(char* class)
{
	insert_symbol_class_proxy(class);
}

void type_insert(char *cur_symbol)
{
	if(pointer_flag)
	{
		char pointer_type[100] = "";
		int i = 0;
		for(i = 0; i < pointer_flag; i++)
		{
			strcat(pointer_type, "*");
		}
		strcat(pointer_type, cur_type);
		insert_symbol_type_proxy(cur_symbol, pointer_type);
		return;
	}
	insert_symbol_type_proxy(cur_symbol, cur_type);
}

void append_star()
{
	append_star_proxy(cur_symbol);
}

void array_dim_insert(int empty)
{

	insert_symbol_array_dimension_proxy(empty);
}

int if_declared_before(char symbol[])
{
	int depth = 0;
	int status = 0;
	while(top != -1 && strcmp(symbol_stack[top], "{") != 0) {
		if(strcmp(symbol_stack[top], symbol) == 0) {
			status = 1;
			break;
		}
		top--;
		depth++;
	}
	top += depth;
	return status;
}

void push(char symbol[])
{
	if(top == -1 && strcmp(symbol, "{") != 0) 
	{
		if(!if_declared_before(symbol))
		{
			top++;
			strcpy(symbol_stack[top], symbol);
			line_stack[top] = 0;
		}
		else
		{
			char error[100];
			snprintf(error, 100, "Duplicate declaration of variable: %s", symbol);
			print_semantic_error(error);
		}
		return;
	}
	if(strcmp(symbol, "}") == 0)
	{
		start_pop();
		return;
	}
	if(strcmp(symbol, "{") == 0 || !if_declared_before(symbol))
	{
		top++;
		if(strcmp(symbol, "{") == 0)
		{
			cur_open_line = yylineno;
		}
		strcpy(symbol_stack[top], symbol);
		line_stack[top] = cur_open_line;
		insert_start_line(line_stack[top], symbol_stack[top]);
	}
	else
	{
		char error[100];
		snprintf(error, 100, "Duplicate declaration of variable: %s", symbol);
		print_semantic_error(error);
	}
}

void start_pop()
{
	char cur[100];
	cur_line = yylineno;
	while(strcmp(symbol_stack[top], "{") != 0)
	{
		// insert_start_line(line_stack[top], symbol_stack[top]);
		insert_end_line(cur_line, symbol_stack[top]);
		pop();

	}
	pop();
}

void pop()
{
	top--;
}

int yywrap()
{
	return 1;
}


void yyerror(char *error)
{
	error_flag=1;
	printf("%d %s %s\n", yylineno, error, yytext);
	printf("Parsing Failed: Result- Invalid\n");
}
