%{
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
%}

%union
{
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
};

%nonassoc IF
%nonassoc ELSE

%left OR_OPERATOR
%left AND_OPERATOR
%left BITWISE_OR_OPERATOR
%left CARET_OPERATOR
%left BITWISE_AND_OPERATOR
%left EQUAL_COMPARATOR NOT_EQUAL_COMPARATOR
%left LESSER_THAN_OR_EQUAL_TO LESSER_THAN GREATER_THAN_OR_EQUAL_TO GREATER_THAN
%left LEFT_SHIFT_OPERATOR RIGHT_SHIFT_OPERATOR 
%left ADD SUBTRACT
%left MULTIPLICATION_OPERATOR DIVISION MODULO

%right LEFT_SHIFT_ASSIGNMENT_OPERATOR RIGHT_SHIFT_ASSIGNMENT_OPERATOR
%right XOR_ASSIGNMENT_OPERATOR OR_ASSIGNMENT_OPERATOR
%right AND_ASSIGNMENT_OPERATOR MODULO_ASSIGNMENT_OPERATOR
%right MULTIPLICATION_ASSIGNMENT_OPERATOR DIVISION_ASSIGNMENT_OPERATOR
%right ADD_ASSIGNMENT_OPERATOR SUBTRACTION_ASSIGNMENT_OPERATOR
%right ASSIGNMENT_OPERATOR
%right SIZEOF

%define parse.error verbose
%token SEMICOLON_DELIMITER COLON COMMA_DELIMITER OPEN_BRACES CLOSE_BRACES OPEN_BRACKET CLOSE_BRACKET OPEN_SQUARE CLOSE_SQUARE
%token RETURN MAIN_FUNCTION
%token INT SHORT LONG LONG_LONG FLOAT CHAR DOUBLE SIGNED UNSIGNED STRUCT
%token BREAK CONTINUE
%token VOID
%token IF ELSE
%token WHILE FOR DO 
%token SWITCH CASE DEFAULT
%token IDENTIFIER
%token INVALID_INTEGER INVALID_FLOAT INVALID_CHARACTER INVALID_STRING ILLEGAL_TOKEN
%token INTEGER_CONSTANT STRING_CONSTANT FLOAT_CONSTANT CHARACTER_CONSTANT
%token PREPROCESSOR_DIRECTIVE MACRO


//NO RULES FOR BITWISE OPERATORS DONE
//2d ARRAYS NOT CONSIDERED  
%right BITWISE_COMPLEMENT_OPERATOR EXCLAMATION_OPERATOR
%left INCREMENT_OPERATOR DECREMENT_OPERATOR 

%start source

%%
source : declaration_list;

declaration_list
			: declaration declaration_list_continuation 
			;

declaration_list_continuation
			: declaration_list
			| ;

// Different types of declaration statements 
declaration
			: function_declaration
			| variable_declaration  // global variable declaration
			| structure_definition
			| PREPROCESSOR_DIRECTIVE
			| MACRO;

/*** FUNCTION GRAMMAR ***/

// Main structure of a function
function_declaration
			: type_specifier function_name function_parameters statement 
			{
				strcpy(last_function, $<String>2);
				number_of_functions_defined += 1;
				// strcpy($<Type>$2, $<Type>1);

				// Update functions_list

				strcpy(functions_list[functions_list_ptr].type, $<Type>1);
				strcpy(functions_list[functions_list_ptr].name, $<String>2);
				functions_list[functions_list_ptr].no_of_parameters = $<Status>3;

				functions_list_ptr++;
			};

// Stores necessary informationt to be output
function_name
			: IDENTIFIER {
				if(check_present_function_proxy(cur_symbol)) {
					printf("Line\:%d Semantic error\: Function already defined\n", yylineno);
					exit(1);
				}
				class_insert("FUNCTION");
				strcpy(cur_fun_type, cur_type);
				type_insert($<String>1);
				strcpy(cur_fun, cur_symbol);

				// update function name
				strcpy($<String>$, $<String>1);

				// nesting_insert(nesting);
			};

// The funtion may or may not have parameters
function_parameters
			: OPEN_BRACKET parameters_list CLOSE_BRACKET {$<Status>$ = $<Status>2;}
			| OPEN_BRACKET CLOSE_BRACKET {$<Status>$ = 0;}
			;

// Stores necessary informationt to be output
parameters_list 
			: type_specifier param_identifier COMMA_DELIMITER parameters_list
			{
				if(strcmp($<Type>1, "void") == 0) {
					printf("Line\:%d Semantic error\: Param of type void\n", yylineno);
					exit(1);
				}
				char cpy[100];
				strcpy(cpy, $<String>2);
				sprintf(cpy, "%s,%s", $<String>2, arglist);
				strcpy(arglist, cpy);
				insert_arg_list_proxy(cur_fun, arglist);
				strcpy(arglist_type[arglist_type_ptr++], $<Type>1);
				insert_arglist_type_proxy(cur_fun, arglist_type);

				// for computing no of args
				$<Status>$ = 1 + $<Status>4;
			}
			| type_specifier param_identifier 
			{
				if(strcmp(cur_type, "void") == 0) {
					printf("Line\:%d Semantic error\: Param of type void\n", yylineno);
					exit(1);
				}
				arglist[0] = '\0';
				char cpy[100];
				strcpy(cpy, $<String>2);
				strcat(arglist, cpy);
				// printf("2 %s\n", arglist);
				
				// Arglist will be stored in reverse order
				arglist_type_ptr = 0;
				strcpy(arglist_type[arglist_type_ptr++], $<Type>1);
				insert_arglist_type_proxy(cur_fun, arglist_type);

				// for computing number of args
				$<Status>$ = 1;
			};

// Any identifier in the parameters
param_identifier 
			: IDENTIFIER { 
				$<Integer>$ = 1;
				type_insert($<String>1); 
			} parameter_identifier_array_check;

// Each parameter can either be an array or single element
parameter_identifier_array_check
			: OPEN_SQUARE CLOSE_SQUARE parameter_identifier_array_check
			| ;

/*** VARIABLE DECLARATION ***/

// Variables declared can be a regular element or struct
variable_declaration
			: type_specifier variable_declaration_list SEMICOLON_DELIMITER
			| STRUCT IDENTIFIER variable_declaration_list SEMICOLON_DELIMITER
			;

// Declare a list of variables to be declared
variable_declaration_list
			: single_element_declaration variable_declaration_list_continuation
			;

// The list can continue or end at any point
variable_declaration_list_continuation
			: COMMA_DELIMITER variable_declaration_list
			| ;

// Each element in the declaration can be a pointer or a regular variable
// TODO: type for arrays also
single_element_declaration
			: IDENTIFIER 
			{ 
				type_insert($<String>1); 
				push($<String>1); 
				pointer_flag = 0;  
				nesting_insert(nesting);
				strcat(identifiers_type_list[identifiers_type_list_ptr].type, cur_type);
				strcpy(identifiers_type_list[identifiers_type_list_ptr].name, $<String>1);
			} array_declaration initilization
			| MULTIPLICATION_OPERATOR single_element_declaration // Pointer
			{
				type_insert($<String>1);
				pointer_flag++;
			}
			;

// For arrays to be declared
array_declaration
			: OPEN_SQUARE first_dimension
			{
				identifiers_type_list_ptr++;
			}
			| 
			{
				identifiers_type_list_ptr++;
			}
			;

// First dimenstion can have size or not
first_dimension
			: array_dimension_with_integer other_dimension
			| array_dimension_without_integer other_dimension
			| ;

// Other dimensions must have size defined 
other_dimension
			: OPEN_SQUARE array_dimension_with_integer other_dimension
			| ;

// Different types of dimenstion declaration
array_dimension_without_integer
			: {array_dim_insert(1);} CLOSE_SQUARE
			;

array_dimension_with_integer
			: INTEGER_CONSTANT 
			{
				array_dim_insert(0);
				
				// Array size should be more than 1
				int size = atoi(cur_value);
				if(size < 1) {
					print_semantic_error("Array size less than 1");
				}
			} CLOSE_SQUARE
			;

// Assigning a value after the declaration
initilization
			: ASSIGNMENT_OPERATOR initilization_continuation
			| ;

// The assigned value can be for an array or a single variable
initilization_continuation
			: array_initialization
			| expression
			;

// Array initilization
array_initialization
			: OPEN_BRACES array_item_list CLOSE_BRACES;

array_item_list
			: OPEN_BRACES array_item_list CLOSE_BRACES array_item_list_continuation
			| expression array_item_list_continuation
			| ;

array_item_list_continuation
			: COMMA_DELIMITER array_item_list
			| ;		


/*** STRUCTURE DECLARATION ***/

// Defining a structure
structure_definition
			: STRUCT IDENTIFIER { 
				type_insert($<String>1); 
				class_insert();
			} OPEN_BRACES struct_variable_declaration CLOSE_BRACES SEMICOLON_DELIMITER;

struct_variable_declaration : variable_declaration struct_variable_declaration 
							| ;

/*** TYPE DECLARATION ***/

// Different datatypes
type_specifier 
			: INT {strcpy($<Type>$, $<Type>1);}
			| FLOAT {strcpy($<Type>$, $<Type>1);}
			| DOUBLE {strcpy($<Type>$, $<Type>1);}
			| CHAR {strcpy($<Type>$, $<Type>1);}
			| UNSIGNED unsigned 
			| SIGNED signed
			| SHORT short
			| LONG long
			| VOID {strcpy($<Type>$, $<Type>1);};

unsigned 
			: INT 
			| SHORT short 
			| LONG long 
			| ;

signed 
			: INT 
			| SHORT short 
			| LONG long 
			| ;

short 
			: INT 
			| ;

long 
			: INT {strcpy($<Type>$, $<Type>1);}
			| ;

/*** EXPRESSION ***/

// Some elements can be on the LHS and some can't
expression
			: assignable assignment_type
			{
				if(strcmp( $<Type>1, "") && strcmp( $<Type>2, "") && strcmp($<Type>1, $<Type>2) != 0) {
					printf("Line %d\: Semantic error\: %s and %s are not compatible\n", yylineno, $<Type>1, $<Type>2);
					exit(1);
				}
				else {
					strcpy($<Type>$, $<Type>2);
				}
			}
			| simple_expression 
			{
				strcpy($<Type>$, $<Type>1);
			}
			;

// Different methods to assign RHS value to LHS
assignment_type
			: ASSIGNMENT_OPERATOR expression
			{
				strcpy($<Type>$, $<Type>2);
			}
			| ADD_ASSIGNMENT_OPERATOR expression
			{
				strcpy($<Type>$, $<Type>2);
			}
			| SUBTRACTION_ASSIGNMENT_OPERATOR expression
			{
				strcpy($<Type>$, $<Type>2);
			}
			| DIVISION_ASSIGNMENT_OPERATOR expression
			{
				strcpy($<Type>$, $<Type>2);
			}
			| MULTIPLICATION_ASSIGNMENT_OPERATOR expression
			{
				strcpy($<Type>$, $<Type>2);
			}
			| MODULO_ASSIGNMENT_OPERATOR expression
			{
				strcpy($<Type>$, $<Type>2);
			}
			| LEFT_SHIFT_ASSIGNMENT_OPERATOR expression
			{
				strcpy($<Type>$, $<Type>2);
			}
			| RIGHT_SHIFT_ASSIGNMENT_OPERATOR expression
			{
				strcpy($<Type>$, $<Type>2);
			}
			| AND_ASSIGNMENT_OPERATOR expression
			{
				strcpy($<Type>$, $<Type>2);
			}
			| OR_ASSIGNMENT_OPERATOR expression
			{
				strcpy($<Type>$, $<Type>2);
			}
			| XOR_ASSIGNMENT_OPERATOR expression
			{
				strcpy($<Type>$, $<Type>2);
			}
			| INCREMENT_OPERATOR
			| DECREMENT_OPERATOR ;

// 
simple_expression
			: and_expression simple_expression_end 
			{
				if($<Status>2 == 1)
				{
					$<Integer>$ = ($<Integer>1 || $<Integer>2);
				}
				else
				{
					$<Integer>$ = $<Integer>1;
				}
				if (strcmp( $<Type>1, "") && strcmp( $<Type>2, "") &&strcmp($<Type>1, $<Type>2) != 0) {
					printf("Line %d\: Semantic error\: %s and %s are not compatible\n", yylineno, $<Type>1, $<Type>2);
					exit(1);
				}
				else {
					strcpy($<Type>$, $<Type>1);
				}
			};

simple_expression_end
			: OR_OPERATOR and_expression simple_expression_end 
			{
				$<Integer>$ = ($<Integer>2 || $<Integer>3);
				$<Status>$ = 1;
				if(strcmp( $<Type>2, "") && strcmp( $<Type>3, "") &&strcmp($<Type>2, $<Type>3) != 0) {
					printf("Line %d\: Semantic error\: %s and %s are not compatible\n", yylineno, $<Type>2, $<Type>3);
					exit(1);
				}
				else {
					strcpy($<Type>$, $<Type>2);
				}
			}
			| 
			{
				$<Integer>$ = 0; 
				$<Status>$ = 0;
				strcpy($<Type>$, "");
			}
			;

and_expression
			: unary_relational_expression and_expression_end
			{
				if($<Status>2 == 1)
				{
					$<Integer>$ = ($<Integer>1 && $<Integer>2);
				}
				else
				{
					$<Integer>$ = $<Integer>1;
				}
				if(strcmp( $<Type>1, "") && strcmp( $<Type>2, "") &&strcmp($<Type>1, $<Type>2) != 0) {
					printf("Line %d\: Semantic error\: %s and %s are not compatible\n", yylineno, $<Type>1, $<Type>2);
					exit(1);
				}
				else {
					strcpy($<Type>$, $<Type>1);
				}
			}
			;

and_expression_end
			: AND_OPERATOR unary_relational_expression and_expression_end
			{
				$<Integer>$ = ($<Integer>2 && $<Integer>3);
				$<Status>$ = 1;
				if(strcmp( $<Type>2, "") && strcmp( $<Type>3, "") &&strcmp($<Type>2, $<Type>3) != 0) {
					printf("Line %d\: Semantic error\: %s and %s are not compatible\n", yylineno, $<Type>1, $<Type>3);
					exit(1);
				}
				else {
					strcpy($<Type>$, $<Type>2);
				}
			}
			| 
			{
				$<Integer>$ = 1; 
				$<Status>$ = 0;
				strcpy($<Type>$, "");
			}
			;

unary_relational_expression
			: EXCLAMATION_OPERATOR unary_relational_expression
			{
				$<Integer>$ = !($<Integer>2);
				strcpy($<Type>$, $<Type>1);
			}
			| relational_expression 
			{
				$<Integer>$ = $<Integer>1;
				strcpy($<Type>$, $<Type>1);
			}
			;

relational_expression
			: sum_of_factors relational_operators sum_of_factors
			{
				if(strcmp($<Op>2, ">=") == 0)
				{
					$<Integer>$ = ($<Integer>1 >= $<Integer>3);
				}
				else if(strcmp($<Op>2, "<=") == 0)
				{
					$<Integer>$ = ($<Integer>1 <= $<Integer>3);
				}
				else if(strcmp($<Op>2, ">") == 0)
				{
					$<Integer>$ = ($<Integer>1 > $<Integer>3);
				}
				else if(strcmp($<Op>2, "<") == 0)
				{
					$<Integer>$ = ($<Integer>1 < $<Integer>3);
				}
				else if(strcmp($<Op>2, "!=") == 0)
				{
					$<Integer>$ = ($<Integer>1 != $<Integer>3);
				}
				else if(strcmp($<Op>2, "==") == 0)
				{
					$<Integer>$ = ($<Integer>1 == $<Integer>3);
				}
				if(strcmp( $<Type>1, "") && strcmp( $<Type>3, "") &&strcmp($<Type>1, $<Type>3) != 0) {
					printf("Line %d\: Semantic error\: %s and %s are not compatible\n", yylineno, $<Type>1, $<Type>3);
					exit(1);
				}
				else {
					strcpy($<Type>$, $<Type>1);
				}
			}
			| sum_of_factors 
			{
				$<Integer>$ = $<Integer>1; 
				strcpy($<Type>$, $<Type>1);
			}
			;

sum_of_factors
			: sum_of_factors sum_operators factor
			{
				if(strcmp($<Op>2, "+") == 0)
				{
					$<Integer>$ = $<Integer>1 + $<Integer>3;
				}
				else if (strcmp($<Op>2, "-") == 0)
				{
					$<Integer>$ = $<Integer>1 - $<Integer>3;
				}
				if(strcmp( $<Type>1, "") && strcmp( $<Type>3, "") &&strcmp($<Type>1, $<Type>3) != 0) {
					printf("Line %d\: Semantic error\: %s and %s are not compatible\n", yylineno, $<Type>1, $<Type>3);
					exit(1);
				}
				else {
					strcpy($<Type>$, $<Type>1);
				}
			}
			| factor 
			{
				$<Integer>$ = $<Integer>1;
				strcpy($<Type>$, $<Type>1);
			}
			;

factor
			: factor multiplicative_operators factor_continuation
			{
				if(strcmp($<Op>2, "*") == 0)
				{
					$<Integer>$ = $<Integer>1 * $<Integer>3;
				}
				else if (strcmp($<Op>2, "/") == 0)
				{
					$<Integer>$ = $<Integer>1 / $<Integer>3;
				}
				else
				{
					$<Integer>$ = $<Integer>1 % $<Integer>3;
				}
				if(strcmp($<Type>1, $<Type>3) != 0)
				{
					printf("Line %d\: Semantic error\: %s and %s are not compatible\n", yylineno, $<Type>1, $<Type>3);
					exit(1);
				}
				else
				{
					strcpy($<Type>$, $<Type>1);
				}
			}
			| factor_continuation 
			{
				$<Integer>$ = $<Integer>1;
				strcpy($<Type>$, $<Type>1);
			}
			;

factor_continuation
			: fixed_value 
			{
				$<Integer>$ = $<Integer>1;
				strcpy($<Type>$, $<Type>1);	
			}
			| assignable 
			{
				strcpy($<Type>$, $<Type>1);
			}
			| size_of
			{
				strcpy($<Type>$, "int");
			}
			| address_of
			{
				strcpy($<Type>$, $<Type>1);
			}
			| value_of;

size_of
			: SIZEOF OPEN_BRACKET size_of_continuation CLOSE_BRACKET;

size_of_continuation
			: assignable
			| type_specifier;

address_of
			: BITWISE_AND_OPERATOR assignable
			{
				strcpy($<Type>$, $<Type>2);
			}
			;

value_of
			: MULTIPLICATION_OPERATOR assignable
			{
				strcpy($<Type>$, $<Type>2);
			}
			;

assignable
			: IDENTIFIER {
				if(!check_present_identifier_proxy($<String>1, yylineno)) {
					printf("Line %d\: Semantic error\: %s Variable undeclared\n", yylineno, $<String>1);
					exit(1);
				}
				if(check_present_function_proxy($<String>1)) {
					printf("Line %d\: Semantic error\: %s is a function\n", yylineno, $<String>1);
					exit(1);
				}
				// printf("%s", get_type_proxy($<String>1, yylineno));
				strcpy($<Type>$, get_type_proxy($<String>1, yylineno));
			}
			| assignable assignable_end
			{
				strcpy($<Type>$, $<Type>1);
			}
			;

// NOTE: Pointer is not handled
assignable_end
			: OPEN_SQUARE expression CLOSE_SQUARE {
				check_if_single_variable(cur_symbol, yylineno);
			}
			| '.' IDENTIFIER;

fixed_value
			: OPEN_BRACKET expression CLOSE_BRACKET
			{
				strcpy($<Type>$, $<Type>2);
			}
			| function_call
			{
				strcpy($<Type>$, $<Type>1);
			}
			| constant 
			{
				$<Integer>$ = $<Integer>1;
				strcpy($<Type>$, $<Type>1);
			}
			;

function_call
			: IDENTIFIER OPEN_BRACKET arguments_list CLOSE_BRACKET
			{
				if(!check_present_function_proxy($<String>1)) 
				{
					printf("Line %d\: Semantic error\: Function is not defined\n", yylineno);
					exit(1);
				}

				check_number_of_args($<String>1, $<Status>3);
				check_type_of_args($<String>1);
				
				strcpy($<Type>$, $<Type>1);	
			};

arguments_list
			: expression COMMA_DELIMITER arguments_list
			{
				// for no of args
				$<Status>$ = 1 + $<Status>3;
				// printf("%s1\n", $<Type>1);

				// miggght cause some consistency issues
				strcpy(arglist_type[arglist_type_ptr++], $<Type>1);
			}
			| expression
			{
				// for no of args
				$<Status>$ = 1;
				// check_for_argtype_mismatch($<Type>1, $<Status>$-1);
				// char req_type = get_arg_type_proxy($<Type>1 ,$<Status>$-1);
				// printf("%s2\n", $<Type>1);

				arglist_type_ptr = 0;
				strcpy(arglist_type[arglist_type_ptr++], $<Type>1);
			}
			| ;

constant
			: INTEGER_CONSTANT 
			{
				$<Integer>$ = $<Integer>1;
				strcpy($<Type>$, $<Type>1);
			}
			| STRING_CONSTANT 
			{
				strcpy($<String>$, $<String>1);
				strcpy($<Type>$, $<Type>1);
			}
			| FLOAT_CONSTANT 
			{
				$<Float>$ = $<Float>1;
				strcpy($<Type>$, $<Type>1);
			}
			| CHARACTER_CONSTANT 
			{
				$<Char>$ = $<Char>1;
				strcpy($<Type>$, $<Type>1);
			}

/*** Operators ***/

// According to precedence, grouping is done
sum_operators
			: ADD {strcpy($<Op>$, $<Op>1);}
			| SUBTRACT {strcpy($<Op>$, $<Op>1);};

multiplicative_operators
			: MULTIPLICATION_OPERATOR {strcpy($<Op>$, $<Op>1);}
			| DIVISION {strcpy($<Op>$, $<Op>1);}
			| MODULO {strcpy($<Op>$, $<Op>1);};

relational_operators
			: GREATER_THAN_OR_EQUAL_TO {strcpy($<Op>$, $<Op>1);}
			| LESSER_THAN_OR_EQUAL_TO {strcpy($<Op>$, $<Op>1);}
			| LESSER_THAN {strcpy($<Op>$, $<Op>1);}
			| GREATER_THAN {strcpy($<Op>$, $<Op>1);}
			| NOT_EQUAL_COMPARATOR {strcpy($<Op>$, $<Op>1);}
			| EQUAL_COMPARATOR {strcpy($<Op>$, $<Op>1);};

/*** Statement ***/

// Different kinds of statements
statement
			: expression_statement
			| conditional_statements
			| compound_statement
			| loop_statement
			| return_statement
			| variable_declaration
			| BREAK SEMICOLON_DELIMITER // break statement
			| PREPROCESSOR_DIRECTIVE
			| MACRO;

// To produce multiple statements
statement_list
			: statement statement_list
			| ;

// statements within { }
compound_statement
			: OPEN_BRACES {push("{"); nesting++; ;} statement_list CLOSE_BRACES {push("}"); nesting--; ;} ;


expression_statement
			: expression SEMICOLON_DELIMITER
			| SEMICOLON_DELIMITER ;

// Different conditional statements
conditional_statements
			: if_statement
			| switch_statement
			;

// If statements
if_statement
			:IF OPEN_BRACKET simple_expression CLOSE_BRACKET statement else_part;

// Takes care of dangling else problem
else_part
			: ELSE statement
			| ;

// Switch case structure
switch_statement
			: SWITCH OPEN_BRACKET simple_expression CLOSE_BRACKET OPEN_BRACES {nesting++; ;} case_statements CLOSE_BRACES {nesting--; ;};

// Any number of case statements
case_statements
			: CASE simple_expression COLON statement case_statements
			| DEFAULT COLON statement case_statements_continuation;

// Once a default statement is seen only case statements can repeat
case_statements_continuation
			: CASE simple_expression COLON statement case_statements_continuation
			| ;

// Different loop statements
loop_statement
			: for_statement
			| while_statement
			| do_while_statement;

// Structure of a for loop
for_statement
			: FOR OPEN_BRACKET expression SEMICOLON_DELIMITER simple_expression SEMICOLON_DELIMITER expression CLOSE_BRACKET statement;

// Structure of a while loop
while_statement
			: WHILE OPEN_BRACKET simple_expression 
			{

			}
			CLOSE_BRACKET statement;

// Structure of a do-while loop
do_while_statement
			: DO statement WHILE OPEN_BRACKET simple_expression CLOSE_BRACKET SEMICOLON_DELIMITER;

// Return statements can return a value or void
return_statement
			: RETURN SEMICOLON_DELIMITER {
				if(strcmp(cur_fun_type, "void"))
				{
					printf("Line %d\: Semantic error\: The function has to return type %s\n", yylineno, cur_fun_type);
					exit(1);
				}
			}
			| RETURN expression {
				if(!strcmp(cur_fun_type, "void"))
				{
					printf("Line %d\: Semantic error\: The function has return type void\n", yylineno);
					exit(1);
				}
				if(strcmp(cur_fun_type, $<Type>2) != 0) {
					char error[100];
					sprintf(error, "Function has return type %s but it is returning %s", cur_fun_type, $<Type>2);
					print_semantic_error(error);
				}
				// printf("%s \n",cur_fun_type);
			} SEMICOLON_DELIMITER;


%%

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
