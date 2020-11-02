%{
	#include "stdlib.h"
	#include "string.h"
	#include "stdio.h"
	#include "ctype.h"

	void yyerror(char* s);
	int yylex();

	extern FILE *yyin;
	extern int yylineno;
	extern char *yytext;

	// Temp generation
	char temp_var[10] = "t0";
	int temp_counter = 0;
	char *new_temp();

	// DS to hold generated code
	int line_ptr = 0;
	char code[1000][30];
	void gen(int n, const char*[]);

	// Back patch operation
	void backpatch(int backpatch_line, int goto_line);
%}

%union
{
	// Hack
	struct
	{
		char *Value;

		// line number for goto (for backpatch)
		int GotoLine;
		int BackPatchLine;

		// extra variable in times of needs
		int Extra;

		// string extra
		char *S_Extra;
	}
}

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
				const char* line[] = {"end"};
				gen(1, line);
			};

// Stores necessary informationt to be output
function_name
			: IDENTIFIER
			{
				const char* line[] = {"begin", $<Value>$};
				gen(2, line);
			};

// The funtion may or may not have parameters
function_parameters
			: OPEN_BRACKET parameters_list CLOSE_BRACKET 
			| OPEN_BRACKET CLOSE_BRACKET
			;

// Stores necessary informationt to be output
parameters_list 
			: type_specifier param_identifier COMMA_DELIMITER parameters_list 
			{
				const char *line[] = {"param", $<Value>2};
				gen(2, line);
			}
			| type_specifier param_identifier
			{
				const char *line[] = {"param", $<Value>2};
				gen(2, line);
			};

// Any identifier in the parameters
// TODO: no array support
param_identifier 
			: IDENTIFIER parameter_identifier_array_check
			{
				$<Value>$ = $<Value>1;
			};

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
			: IDENTIFIER array_declaration initilization
			| MULTIPLICATION_OPERATOR single_element_declaration // Pointer
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
			: CLOSE_SQUARE
			;

array_dimension_with_integer
			: INTEGER_CONSTANT CLOSE_SQUARE
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
			: STRUCT IDENTIFIER OPEN_BRACES struct_variable_declaration CLOSE_BRACES SEMICOLON_DELIMITER;

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
// TODO: Support for pre-increment and pre-decrement
expression
			: assignable assignment_type expression
			{
				const char *line[] = {$<Value>1, $<Value>2, $<Value>3};
				gen(3, line);

				$<Value>$ = $<Value>1;
			}
			| assignable INCREMENT_OPERATOR
			{
				// TODO: Check if this is correct ICG generation
				const char *line[] = {$<Value>1, "=", $<Value>1, "+", "1"};
				gen(5, line);

				$<Value>$ = $<Value>1;
			}
			| assignable DECREMENT_OPERATOR
			{
				// TODO: Check if this is correct ICG generation
				const char *line[] = {$<Value>1, "=", $<Value>1, "-", "1"};
				gen(5, line);

				$<Value>$ = $<Value>1;
			}
			| simple_expression
			{
				$<Value>$ = $<Value>1;
			};

// Different methods to assign RHS value to LHS
assignment_type
			: ASSIGNMENT_OPERATOR
			{
				$<Value>$ = $<Value>1;
			};
			| ADD_ASSIGNMENT_OPERATOR
			{
				$<Value>$ = $<Value>1;
			};
			| SUBTRACTION_ASSIGNMENT_OPERATOR
			{
				$<Value>$ = $<Value>1;
			};
			| DIVISION_ASSIGNMENT_OPERATOR
			{
				$<Value>$ = $<Value>1;
			};
			| MULTIPLICATION_ASSIGNMENT_OPERATOR
			{
				$<Value>$ = $<Value>1;
			};
			| MODULO_ASSIGNMENT_OPERATOR
			{
				$<Value>$ = $<Value>1;
			};
			| LEFT_SHIFT_ASSIGNMENT_OPERATOR
			{
				$<Value>$ = $<Value>1;
			};
			| RIGHT_SHIFT_ASSIGNMENT_OPERATOR
			{
				$<Value>$ = $<Value>1;
			};
			| AND_ASSIGNMENT_OPERATOR
			{
				$<Value>$ = $<Value>1;
			};
			| OR_ASSIGNMENT_OPERATOR
			{
				$<Value>$ = $<Value>1;
			};
			| XOR_ASSIGNMENT_OPERATOR
			{
				$<Value>$ = $<Value>1;
			};

simple_expression
			: simple_expression OR_OPERATOR and_expression
			{
				const char *temp = new_temp();

				const char *line[] = {temp, "=", $<Value>1, $<Value>2, $<Value>3};
				gen(5, line);

				$<Value>$ = strdup(temp);
			}
			| and_expression
			{
				$<Value>$ = $<Value>1;
			};

and_expression
			: and_expression AND_OPERATOR unary_relational_expression
			{
				const char *temp = new_temp();

				const char *line[] = {temp, "=", $<Value>1, $<Value>2, $<Value>3};
				gen(5, line);

				$<Value>$ = strdup(temp);
			}
			| unary_relational_expression
			{
				$<Value>$ = $<Value>1;
			};

unary_relational_expression
			: EXCLAMATION_OPERATOR unary_relational_expression
			{
				const char *temp = new_temp();

				const char *line[] = {temp, "=", $<Value>1, $<Value>2};
				gen(4, line);

				$<Value>$ = strdup(temp);
			}
			| relational_expression
			{
				$<Value>$ = $<Value>1;
			};

relational_expression
			: sum_of_factors relational_operators sum_of_factors
			{
				const char *temp = new_temp();

				const char *line[] = {temp, "=", $<Value>1, $<Value>2, $<Value>3};
				gen(5, line);

				$<Value>$ = strdup(temp);
			}
			| sum_of_factors
			{
				$<Value>$ = $<Value>1;
			};

sum_of_factors
			: sum_of_factors sum_operators factor
			{
				const char *temp = new_temp();

				const char *line[] = {temp, "=", $<Value>1, $<Value>2, $<Value>3};
				gen(5, line);

				$<Value>$ = strdup(temp);
			}
			| factor
			{
				$<Value>$ = $<Value>1;
			};

factor
			: factor multiplicative_operators factor_continuation
			{
				const char *temp = new_temp();

				const char *line[] = {temp, "=", $<Value>1, $<Value>2, $<Value>3};
				gen(5, line);

				$<Value>$ = strdup(temp);
			}
			| factor_continuation
			{
				$<Value>$ = $<Value>1;
			};

factor_continuation
			: fixed_value
			{
				$<Value>$ = $<Value>1;
			}
			| assignable
			{
				$<Value>$ = $<Value>1;
			}
			| size_of
			| address_of
			| value_of;

// TODO: No support for below 4
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
			{
				$<Value>$ = $<Value>1;
			};
			| assignable assignable_end
			{
				char id[20] = ""; // NOTE: Hard limit
				const char* t0 = strdup(new_temp());
				const char* line[] = {t0, "=", "&", $<Value>1};
				gen(4, line);
				const char *t1 = strdup(new_temp());
				const char *line1[] = {t1, "=", "sizeof(int)"};
				gen(3, line1);
				const char *t2 = strdup(new_temp());
				const char *line2[] = {t2, "=", t1, "*", $<S_Extra>2};
				gen(5, line2);
				const char* t3 = strdup(new_temp());
				const char *line3[] = {t3, "=", t0, "+", t2};
				gen(5, line3);
				sprintf(id, "*%s", t3);
				

				// strcat(id, $<Value>1);
				// strcat(id, $<Value>2);
				$<Value>$ = strdup(id);
			};;

// NOTE: Pointers not supported
assignable_end
			: OPEN_SQUARE expression CLOSE_SQUARE
			{
				// TODO: Arrays directly implmented for now
				char id[20] = ""; // NOTE: Hard limit
				strcat(id, $<Value>1);
				strcat(id, $<Value>2);
				strcat(id, $<Value>3);

				$<S_Extra>$ = strdup($<Value>2);
				$<Value>$ = strdup(id);
			}
			| '.' IDENTIFIER
			{
				// NOTE: Pointers not supported
			};

fixed_value
			: OPEN_BRACKET expression CLOSE_BRACKET
			{
				$<Value>$ = $<Value>2;
			}
			| function_call
			{
				$<Value>$ = $<Value>1;
			}
			| constant
			{
				$<Value>$ = $<Value>1;
			};

function_call
			: IDENTIFIER OPEN_BRACKET arguments_list CLOSE_BRACKET
			{
				const char *temp = new_temp();

				const char* line[] = {"out", temp};
				gen(2, line);
				const char* line1[] = {"call", $<Value>1};
				gen(2, line1);

				$<Value>$ = strdup(temp);
			};

arguments_list
			: expression COMMA_DELIMITER arguments_list
			{
				$<Value>$ = $<Value>1;

				const char *line[] = {"arg", $<Value>$};
				gen(2, line);
			}
			| expression
			{
				$<Value>$ = $<Value>1;

				const char *line[] = {"arg", $<Value>$};
				gen(2, line);
			}
			| ;

constant
			: INTEGER_CONSTANT
			{
				$<Value>$ = $<Value>1;
			}
			| STRING_CONSTANT
			{
				$<Value>$ = $<Value>1;
			}
			| FLOAT_CONSTANT
			{
				$<Value>$ = $<Value>1;
			}
			| CHARACTER_CONSTANT
			{
				$<Value>$ = $<Value>1;
			}

/*** Operators ***/

// According to precedence, grouping is done
sum_operators
			: ADD
			{
				$<Value>$ = $<Value>1;
			}
			| SUBTRACT 
			{
				$<Value>$ = $<Value>1;
			};

multiplicative_operators
			: MULTIPLICATION_OPERATOR
			{
				$<Value>$ = $<Value>1;
			}
			| DIVISION
			{
				$<Value>$ = $<Value>1;
			}
			| MODULO
			{
				$<Value>$ = $<Value>1;
			};

relational_operators
			: GREATER_THAN_OR_EQUAL_TO
			{
				$<Value>$ = $<Value>1;
			}
			| LESSER_THAN_OR_EQUAL_TO
			{
				$<Value>$ = $<Value>1;
			}
			| LESSER_THAN
			{
				$<Value>$ = $<Value>1;
			}
			| GREATER_THAN
			{
				$<Value>$ = $<Value>1;
			}
			| NOT_EQUAL_COMPARATOR
			{
				$<Value>$ = $<Value>1;
			}
			| EQUAL_COMPARATOR
			{
				$<Value>$ = $<Value>1;
			};

/*** Statement ***/

// Different kinds of statements
statement
			: expression_statement
			{
				$<Value>$ = $<Value>1;
			}
			| conditional_statements
			| compound_statement
			| loop_statement
			| return_statement
			| variable_declaration
			| BREAK SEMICOLON_DELIMITER // break statement
			| PREPROCESSOR_DIRECTIVE
			| MACRO;

// statements within { }
compound_statement
			: OPEN_BRACES statement_list CLOSE_BRACES;

// To produce multiple statements
statement_list
			: statement statement_list
			| ;

expression_statement
			: expression SEMICOLON_DELIMITER
			{
				$<Value>$ = $<Value>1;
			}
			| SEMICOLON_DELIMITER ;

// Different conditional statements
conditional_statements
			: if_statement
			| switch_statement
			;

// If statements
// Todo: No if else statement
if_statement
			:IF if_condition statement else_part
			{
				backpatch($<BackPatchLine>2, $<GotoLine>4);
			};

if_condition
			: OPEN_BRACKET simple_expression CLOSE_BRACKET
			{
				// False condition
				const char* line[] = {"if", $<Value>2, "= 0", "goto"};			
				gen(4, line);
			
				$<BackPatchLine>$ = line_ptr-1;
			};

// Takes care of dangling else problem
else_part
			: ELSE empty_else statement
			{
				backpatch($<BackPatchLine>2, line_ptr);
				$<GotoLine>$ = $<GotoLine>2;
			}
			|
			{
				$<GotoLine>$ = line_ptr;
			};

empty_else	:
			{
				const char *line[] = {"goto"};
				gen(1, line);

				$<BackPatchLine>$ = line_ptr-1;
				$<GotoLine>$ = line_ptr;
			};

// TODO: No support
// Switch case structure
switch_statement
			: SWITCH OPEN_BRACKET simple_expression CLOSE_BRACKET OPEN_BRACES case_statements CLOSE_BRACES;

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
			:  for_statement_init for_statement_condition for_statement_update for_statement_body
			{
				backpatch($<BackPatchLine>3, $<GotoLine>1);
				backpatch($<BackPatchLine>4, $<GotoLine>2);
				backpatch($<BackPatchLine>2, $<GotoLine>3);
				backpatch($<Extra>2, $<GotoLine>4);
			};

for_statement_init
			: FOR OPEN_BRACKET expression SEMICOLON_DELIMITER
			{
				$<GotoLine>$ = line_ptr;
			};

for_statement_condition
			: simple_expression SEMICOLON_DELIMITER
			{
				const char* line[] = {"if", $<Value>2, "!= 0", "goto"};			
				gen(4, line);

				const char* line1[] = {"goto"};
				gen(1, line1);

				$<BackPatchLine>$ = line_ptr-2;
				$<Extra>$ = line_ptr-1;
				$<GotoLine>$ = line_ptr;
			};

for_statement_update
			: expression CLOSE_BRACKET
			{
				const char* line[] = {"goto"};
				gen(1, line);
				
				$<BackPatchLine>$ = line_ptr-1;
				$<GotoLine>$ = line_ptr;
			};

for_statement_body
			: statement
			{
				const char* line[] = {"goto"};
				gen(1, line);
				
				$<BackPatchLine>$ = line_ptr-1;
				$<GotoLine>$ = line_ptr;
			};

// Structure of a while loop
while_statement
			: while_begin while_end
			{
				backpatch($<BackPatchLine>1, $<GotoLine>2);
				backpatch($<BackPatchLine>2, $<GotoLine>1);
			};

while_begin
			: WHILE OPEN_BRACKET empty_while simple_expression CLOSE_BRACKET
			{
				// False condition
				const char* line[] = {"if", $<Value>2, "= 0", "goto"};			
				gen(4, line);

				$<BackPatchLine>$ = line_ptr-1;
				$<GotoLine>$ = $<GotoLine>3;
			};

empty_while
			:
			{
				$<GotoLine>$ = line_ptr;
			};

while_end
			: statement
			{
				const char* line[] = {"goto"};
				gen(1, line);

				$<BackPatchLine>$ = line_ptr-1;
				$<GotoLine>$ = line_ptr;
			};

// Structure of a do-while loop
do_while_statement
			: DO empty_do_while statement WHILE OPEN_BRACKET simple_expression CLOSE_BRACKET SEMICOLON_DELIMITER
			{
				const char *line[] = {"if", $<Value>6, "= 0", "goto"};
				gen(4, line);

				backpatch(line_ptr-1, $<GotoLine>2);
			};

empty_do_while
			:
			{
				$<GotoLine>$ = line_ptr;	
			};

// Return statements can return a value or void
return_statement
			: RETURN SEMICOLON_DELIMITER
			{
				const char *line[] = {"ret"};
				gen(1, line);
			}
			| RETURN expression SEMICOLON_DELIMITER
			{
				const char *line[] = {"ret", $<Value>2};
				gen(2, line);	
			};


%%

int main(int argc , char **argv)
{
	yyin = fopen(argv[1], "r");

	yyparse();

	// Print ICG output
	for(int i = 0; i <= line_ptr; i++)
	{
		printf("%02d: %s;\n", i, code[i]);
	}

	return 0;
}

int yywrap()
{
	return 1;
}

void yyerror(char *error)
{
	printf("%d %s %s\n", yylineno, error, yytext);
	printf("Parsing Failed: Result- Invalid\n");
}

// Implement ICG helper functions

char *new_temp()
{
	snprintf(temp_var, 10, "t%d", temp_counter);
	temp_counter++;
	return temp_var;
}

void gen(int n, const char *line[]) 
{
	char code_line[20] = "";
	for(int i = 0; i < n; i++)
	{
		strcat(code_line, line[i]);
		if(i != n-1)
		{
			strcat(code_line, " ");
		}
	}

	strcpy(code[line_ptr], code_line);
	line_ptr++;
}

void backpatch(int backpatch_line, int goto_line)
{
	char str_line[10];
	snprintf(str_line, 10, " %02d", goto_line);

	strcat(code[backpatch_line], str_line);
}