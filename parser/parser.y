%{
	#include "stdlib.h"
	#include "string.h"
	#include "stdio.h"
	#include "ctype.h"
	//#include "malloc.h"

	void type_insert();
	void insert_symbol_type_proxy(char *,char *);
	void print_constant_table_proxy(void);
	void print_symbol_table_proxy(void);
	void insert_symbol_class_proxy(char *);
	void insert_symbol_array_dimension_proxy();
	void insert_arg_list_proxy(char *, char *);
	void append_star_proxy(char *);

	void push(char *);
	void start_pop(void);
	void pop(void);
	int check_present_proxy(void);	
	void insert_start_line(int, char *);
	void insert_end_line(int, char *);
	void nesting_insert(int);
	void class_insert(char* class);
	void array_dim_insert(int empty);

	void yyerror(char* s);
	int yylex();

	extern FILE *yyin;
	extern int yylineno;
	extern char *yytext;
	extern char cur_symbol[100];
	extern char cur_type[100];
	extern char cur_value[100];

	char symbol_stack[100][100];
	char cur_fun[100];
	char arglist[1000];
	int line_stack[100];
	int top=-1;
	int cur_line;
	int cur_open_line;
	int error_flag=0;
	int pointer_flag = 0;
	int nesting = 0;
	// extern struct_symbol_table_entry *identifiers_list;
%}

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

//%define parse.error verbose
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
			: type_specifier function_name function_parameters statement;

// Stores necessary informationt to be output
function_name
			: IDENTIFIER {
				type_insert();
				class_insert("Function");
				strcpy(cur_fun, cur_symbol);
				// nesting_insert(nesting);
			};

// The funtion may or may not have parameters
function_parameters
			: OPEN_BRACKET parameters_list CLOSE_BRACKET 
			| OPEN_BRACKET CLOSE_BRACKET
			;

// Stores necessary informationt to be output
parameters_list 
			: type_specifier param_identifier {
				char cpy[100];
				strcpy(cpy, cur_symbol);
				strcat(cpy, ",");
				strcat(arglist, cpy);
			} COMMA_DELIMITER parameters_list 
			| type_specifier param_identifier {
				char cpy[100];
				strcpy(cpy, cur_symbol);
				strcat(arglist, cpy);
				insert_arg_list_proxy(cur_fun, arglist);
				arglist[0] = '\0';
			};

// Any identifier in the parameters
param_identifier 
			: IDENTIFIER { 
				$$ = 1;
				type_insert(); 
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
single_element_declaration
			: IDENTIFIER { type_insert(); push(cur_symbol); pointer_flag = 0;  nesting_insert(nesting);} array_declaration initilization
			| MULTIPLICATION_OPERATOR {pointer_flag++;} single_element_declaration // Pointer
			;

// For arrays to be declared
array_declaration
			: OPEN_SQUARE first_dimension
			| ;

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
			: INTEGER_CONSTANT {array_dim_insert(0);} CLOSE_SQUARE
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
				type_insert(); 
				class_insert("Structure");
			} OPEN_BRACES struct_variable_declaration CLOSE_BRACES SEMICOLON_DELIMITER;

struct_variable_declaration : variable_declaration struct_variable_declaration 
							| ;

/*** TYPE DECLARATION ***/

// Different datatypes
type_specifier 
			: INT 
			| FLOAT 
			| DOUBLE 
			| CHAR  
			| UNSIGNED unsigned 
			| SIGNED signed
			| SHORT short
			| LONG long 
			| VOID ;

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
			: INT 
			| ;

/*** EXPRESSION ***/

// Some elements can be on the LHS and some can't
expression
			: assignable assignment_type
			| simple_expression ;

// Different methods to assign RHS value to LHS
assignment_type
			: ASSIGNMENT_OPERATOR expression
			| ADD_ASSIGNMENT_OPERATOR expression
			| SUBTRACTION_ASSIGNMENT_OPERATOR expression
			| DIVISION_ASSIGNMENT_OPERATOR expression
			| MULTIPLICATION_ASSIGNMENT_OPERATOR expression
			| MODULO_ASSIGNMENT_OPERATOR expression
			| LEFT_SHIFT_ASSIGNMENT_OPERATOR expression
			| RIGHT_SHIFT_ASSIGNMENT_OPERATOR expression
			| AND_ASSIGNMENT_OPERATOR expression
			| OR_ASSIGNMENT_OPERATOR expression
			| XOR_ASSIGNMENT_OPERATOR expression
			| INCREMENT_OPERATOR
			| DECREMENT_OPERATOR ;

// 
simple_expression
			: and_expression simple_expression_end;

simple_expression_end
			: OR_OPERATOR and_expression simple_expression_end 
			| ;

and_expression
			: unary_relational_expression and_expression_end;

and_expression_end
			: AND_OPERATOR unary_relational_expression and_expression_end
			| ;

unary_relational_expression
			: EXCLAMATION_OPERATOR unary_relational_expression
			| relational_expression ;

relational_expression
			: sum_of_factors relational_operators sum_of_factors
			| sum_of_factors;

sum_of_factors
			: sum_of_factors sum_operators factor
			| factor ;

factor
			: factor multiplicative_operators factor_continuation
			| factor_continuation;

factor_continuation
			: fixed_value
			| assignable 
			| size_of
			| address_of
			| value_of;

size_of
			: SIZEOF OPEN_BRACKET size_of_continuation CLOSE_BRACKET;

size_of_continuation
			: assignable
			| type_specifier;

address_of
			: BITWISE_AND_OPERATOR assignable
			;

value_of
			: MULTIPLICATION_OPERATOR assignable
			;

assignable
			: IDENTIFIER
			| assignable assignable_end;

// NOTE: Pointer is not handled
assignable_end
			: OPEN_SQUARE expression CLOSE_SQUARE
			| '.' IDENTIFIER;

fixed_value
			: OPEN_BRACKET expression CLOSE_BRACKET
			| function_call
			| constant;

function_call
			: IDENTIFIER OPEN_BRACKET arguments_list CLOSE_BRACKET;

arguments_list
			: expression COMMA_DELIMITER arguments_list
			| expression
			| ;

constant
			: INTEGER_CONSTANT
			| STRING_CONSTANT
			| FLOAT_CONSTANT
			| CHARACTER_CONSTANT

/*** Operators ***/

// According to precedence, grouping is done
sum_operators
			: ADD
			| SUBTRACT ;

multiplicative_operators
			: MULTIPLICATION_OPERATOR
			| DIVISION
			| MODULO ;

relational_operators
			: GREATER_THAN_OR_EQUAL_TO
			| LESSER_THAN_OR_EQUAL_TO
			| LESSER_THAN
			| GREATER_THAN
			| NOT_EQUAL_COMPARATOR
			| EQUAL_COMPARATOR ;

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
			: WHILE OPEN_BRACKET simple_expression CLOSE_BRACKET statement;

// Structure of a do-while loop
do_while_statement
			: DO statement WHILE OPEN_BRACKET simple_expression CLOSE_BRACKET SEMICOLON_DELIMITER;

// Return statements can return a value or void
return_statement
			: RETURN SEMICOLON_DELIMITER
			| RETURN expression SEMICOLON_DELIMITER;


%%

int main(int argc , char **argv)
{
	yyin = fopen(argv[1], "r");

	yyparse();

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

void class_insert(char* class)
{
	insert_symbol_class_proxy(class);
}

void type_insert()
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


void push(char symbol[])
{
	if(top == -1 && strcmp(symbol, "{") != 0) 
	{
		return;
	}
	if(strcmp(symbol, "}") == 0)
	{
		start_pop();
		return;
	}
	top++;
	if(strcmp(symbol, "{") == 0)
	{
		cur_open_line = yylineno;
	}
	strcpy(symbol_stack[top], symbol);
	line_stack[top] = cur_open_line;
}

void start_pop()
{
	char cur[100];
	cur_line = yylineno;
	while(strcmp(symbol_stack[top], "{") != 0)
	{
		insert_start_line(line_stack[top], symbol_stack[top]);
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