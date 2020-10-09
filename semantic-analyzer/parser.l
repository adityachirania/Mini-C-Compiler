%{

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "y.tab.h"
    #include <malloc.h>

    #include "include/pretty_print.h"
    #include "include/symbol_table.h"

    char cur_symbol[100];
	char cur_type[100];
    char cur_value[100];

    void insert_symbol_type_proxy(char *cur_symbol,char *cur_type) 
    {
        insert_symbol_type(&identifiers_list, cur_symbol, cur_type);
    }

    void print_constant_table_proxy()
    {
        print_constant_table(&constants_list, "Constants");
    }

    void print_symbol_table_proxy()
    {
        print_symbol_table(&identifiers_list);
    }

	void insert_symbol_class_proxy(char *class)
    {
        insert_symbol_class(&identifiers_list, cur_symbol, class);
    }

	void insert_symbol_array_dimension_proxy(int empty)
    {
        // printf("%s\n", empty);
        // return;
        if(empty)
        {
            char nul[100] = "";
            insert_symbol_array_dimension(&identifiers_list, cur_symbol, nul);
            return;
        }
        insert_symbol_array_dimension(&identifiers_list, cur_symbol, cur_value);
    }

    int check_present_proxy()
    {
        return check_present_symbol(&identifiers_list, cur_symbol);
    }

    void insert_start_line(int lineno, char *symbol)
    {
        insert_symbol_start_lineno(&identifiers_list, symbol, lineno);
    }

    void insert_end_line(int lineno, char *symbol)
    {
        insert_symbol_end_lineno(&identifiers_list, symbol, lineno);
    } 

    void insert_arg_list_proxy(char *cur_fun, char *arglist)
    {
	    insert_symbol_arg_list(&identifiers_list, cur_fun, arglist);
    }

    void append_star_proxy(char *symbol)
    {
        append_pointer_type(&identifiers_list, symbol);
    }

    void nesting_insert(int nesting)
    {
        insert_symbol_nesting(&identifiers_list, cur_symbol, nesting);
    }

    int check_present_function_proxy(char *symbol)
    {
        return check_present_function(&identifiers_list, symbol);
    }

    int check_present_identifier_proxy(char *symbol, int lineno)
    {
        return check_present_identifier(&identifiers_list, symbol, lineno);
    }

    char* get_type_proxy(char *symbol, int lineno) {
        return get_type(&identifiers_list, symbol, lineno);
    }

    void insert_arglist_type_proxy(char *symbol, char arglist_type[][100]) {
        insert_arglist_type(&identifiers_list, symbol, arglist_type);
    }

    char* get_arg_type_proxy(char *symbol, int index) {
        return get_arg_type(&identifiers_list, symbol, index);
    }

%}

 /* Definitions */
ALPHA [A-Za-z]
ALPHA_NUM [A-Za-z0-9]
DIGIT [0-9]
FILENAME .+
ID ([_]|[a-zA-Z])([_]|[a-zA-Z]|[0-9])*
MULTI_LINE_COMMENT_START \/\* 
MULTI_LINE_COMMENT_END \*\/

%x multi_line_comment_end_check

%%

 /* Removing unnecessary spaces */
[ ]+

[\t]+

 /* Counting number of lines */
[\n] {
    yylineno++;
}

 /* Error for unmatched multiline comments */
{MULTI_LINE_COMMENT_START} {
    BEGIN(multi_line_comment_end_check);
};

<multi_line_comment_end_check>(\n) {
    yylineno++;
    yymore();
}

<multi_line_comment_end_check>{MULTI_LINE_COMMENT_END} {
    BEGIN INITIAL;
}

<multi_line_comment_end_check>. {
    yymore();
}

<multi_line_comment_end_check><<EOF>> {
    return 0;
}

{MULTI_LINE_COMMENT_END} {
}

 /* Detect Single line comments */
\/\/(.*) { }

 /* Preprocessor directive */
(#[ ]*include[ ]*<{ALPHA}{ALPHA}*\.h>)|(#[ ]*include[ ]*\"{ALPHA}{ALPHA}*\.h\")  {
    return PREPROCESSOR_DIRECTIVE;
}
 /* Macros */
(#[ ]*define[ ]+{ID}[ ]+.*) {
    return MACRO;
}

 /* Keywords */
"int" {
    strcpy(cur_type, yytext);
    strcpy(yylval.Type, "int");
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return INT;
}

"short" {
    strcpy(cur_type, yytext);
    strcpy(yylval.Type, "short");
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return SHORT;
}

"long" {
    strcpy(cur_type, yytext);
    strcpy(yylval.Type, "long");
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return LONG;
}

"long long" {
    strcpy(cur_type, yytext);
    strcpy(yylval.Type, "long long");
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return LONG_LONG;
}

"float" {
    strcpy(cur_type, yytext);
    strcpy(yylval.Type, "float");
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return FLOAT;
}

"char" {
    strcpy(cur_type, yytext);
    strcpy(yylval.Type, "char");
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return CHAR;
}

"double" {
    strcpy(cur_type, yytext);
    strcpy(yylval.Type, "double");
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return DOUBLE;
}

"for" {
    strcpy(cur_symbol, yytext);
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return FOR;
}

"while" {
    strcpy(cur_symbol, yytext);
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return WHILE;
}

"do" {
    strcpy(cur_symbol, yytext);
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return DO;
}

"if" {
    strcpy(cur_symbol, yytext);
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return IF;
}

"else" {
    strcpy(cur_type, yytext);
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return ELSE;
}

"signed" {
    strcpy(cur_type, yytext);
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return SIGNED;
}

"unsigned" {
    strcpy(cur_type, yytext);
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return UNSIGNED;
}

"struct" {
    strcpy(cur_symbol, yytext);
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return STRUCT;
}

"continue" {
    strcpy(cur_symbol, yytext);
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return CONTINUE;
}

"break" {
    strcpy(cur_symbol, yytext);
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return BREAK;
}

"void" {
    strcpy(cur_type, yytext);
    strcpy(yylval.Type, yytext);
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return VOID;
}

"return" {
    strcpy(cur_symbol, yytext);
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return RETURN;
}

"switch" {
    strcpy(cur_symbol, yytext);
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return SWITCH;
}

"case" {
    strcpy(cur_symbol, yytext);
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return CASE;
}

"default" {
    strcpy(cur_symbol, yytext);
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return DEFAULT;
}

"sizeof" {
    strcpy(cur_symbol, yytext);
    // add_to_symbol_table(&identifiers_list, yytext, "KEYWORD");
    return SIZEOF;
}


 /* Main check */
 /*(main\(\)) {
    return MAIN_FUNCTION;
}

(main\(void\)) {
    return MAIN_FUNCTION;
}

(main\(int[ ]+{ID}\,[ ]+char\*\*[ ]+{ID}\)) {
    return MAIN_FUNCTION;
}*/

 /* semicolon, comma and brackets */
;   {
    return SEMICOLON_DELIMITER;
}
:   {
    return COLON;
}
,   {
    return COMMA_DELIMITER;
}
\{  {
    return OPEN_BRACES;
}
\}  {
    return CLOSE_BRACES;
}
\(  {
    return OPEN_BRACKET;
}
\)  {
    return CLOSE_BRACKET;
}
\[  {
    return OPEN_SQUARE;
}
\]  {
    return CLOSE_SQUARE;
}

 /* operators */
(">=") {
    strcpy(yylval.Op, ">=");
    return GREATER_THAN_OR_EQUAL_TO;
}
("<=") {
    strcpy(yylval.Op, "<=");
    return LESSER_THAN_OR_EQUAL_TO;
}
("==") {
    strcpy(yylval.Op, "==");
    return EQUAL_COMPARATOR;
}
("!=") {
    strcpy(yylval.Op, "!=");
    return NOT_EQUAL_COMPARATOR;
}
("<") {
    strcpy(yylval.Op, "<");
    return LESSER_THAN;
}
(">") {
    strcpy(yylval.Op, ">");
    return GREATER_THAN;
}
("&&") {
    strcpy(yylval.Op, "&&");
    return AND_OPERATOR;
}
("||") {
    strcpy(yylval.Op, "||");
    return OR_OPERATOR;
}
("!") {
    strcpy(yylval.Op, "!");
    return EXCLAMATION_OPERATOR;
}
("&") {
    strcpy(yylval.Op, "&");
    return BITWISE_AND_OPERATOR;
}
("|") {
    strcpy(yylval.Op, "|");
    return BITWISE_OR_OPERATOR;
}
("~") {
    strcpy(yylval.Op, "~");
    return BITWISE_COMPLEMENT_OPERATOR;
}
(">>") {
    strcpy(yylval.Op, ">>");
    return RIGHT_SHIFT_OPERATOR;
}
("<<") {
    strcpy(yylval.Op, "<<");
    return LEFT_SHIFT_OPERATOR;
}
("+") {
    strcpy(yylval.Op, "+");
    return ADD;
}
("-") {
    strcpy(yylval.Op, "-");
    return SUBTRACT;
}
("*") {
    strcpy(yylval.Op, "*");
    return MULTIPLICATION_OPERATOR;
}
("/") {
    strcpy(yylval.Op, "/");
    return DIVISION;
}
("%") {
    strcpy(yylval.Op, "%");
    return MODULO;
}
("=") {
    strcpy(yylval.Op, "=");
    return ASSIGNMENT_OPERATOR;
}
("+=") {
    return ADD_ASSIGNMENT_OPERATOR;
}
("-=") {
    return SUBTRACTION_ASSIGNMENT_OPERATOR;
}
("/=") {
    return DIVISION_ASSIGNMENT_OPERATOR;
}
("*=") {
    return MULTIPLICATION_ASSIGNMENT_OPERATOR;
}

("^") {
    return CARET_OPERATOR;
}

("++") {
    return INCREMENT_OPERATOR;
}

("--") {
    return DECREMENT_OPERATOR;
}

("<<=") {
    return LEFT_SHIFT_ASSIGNMENT_OPERATOR;
}

(">>=") {
    return RIGHT_SHIFT_ASSIGNMENT_OPERATOR;
}

("^=") {
    return XOR_ASSIGNMENT_OPERATOR;
}

("|=") {
    return OR_OPERATOR;
}

("&=") {
    return AND_ASSIGNMENT_OPERATOR;
}

("%=") {
    return MODULO_ASSIGNMENT_OPERATOR;
}

 /* Identifers */
{ID} {
    strcpy(cur_symbol, yytext);
    strcpy(yylval.String, yytext);
    add_to_symbol_table(&identifiers_list, yytext, "IDENTIFIER");
    return IDENTIFIER;
}

 /* Literals */
{DIGIT}* {
    strcpy(cur_value, yytext);
    yylval.Integer = atoi(yytext);
    add_to_constant_table(&constants_list, yytext);
    strcpy(yylval.Type, "int");
    return INTEGER_CONSTANT;
}

{DIGIT}*{ALPHA_NUM}* {
    add_to_constant_table(&constants_list, yytext);
    return INVALID_INTEGER;
}

{DIGIT}*\.{DIGIT}* {
    yylval.Float = atof(yytext);
    add_to_constant_table(&constants_list, yytext);
    strcpy(yylval.Type, "float");
    return FLOAT_CONSTANT;
}

{DIGIT}*\.{ALPHA_NUM}*([\.]*{ALPHA_NUM}*)+ {
    return  INVALID_FLOAT;
}

\'(.)?\' {
    yylval.Char = yytext[1];
    add_to_constant_table(&constants_list, yytext);
    strcpy(yylval.Type, "char");
    return CHARACTER_CONSTANT;
}

\'(.)*\' {
    return INVALID_CHARACTER;
}
 
\"(.)*\" {
    char *temp = yytext;
    temp++;
    strcpy(yylval.String, temp);
    yylval.String[strlen(temp)-1] = 0;

    add_to_constant_table(&constants_list, yytext);
    // TODO
    strcpy(yylval.Type, "*char");
    return STRING_CONSTANT;
}

\"([^\"]|\n)*    {
    return INVALID_STRING;
}

<<EOF>> {
    return EOF;
}

.|\n   {
    return ILLEGAL_TOKEN;
};

%%

// int main(int argc, char **argv) {
//     if(argc != 2) {
//         printf("usage: ./a.out <c-program>");
//         return 1;
//     }

//     /* open test files */
//     yyin = fopen(argv[1], "r");

//     print_header();
//     yylex();
//     print_row_dash();

//     printf("\n\nLINES: %d\n\n", yylineno);

//     print_symbol_table(&identifiers_list, "Identifier Table");
//     printf("\n");
//     print_symbol_table(&constants_list, "Constant Table");

//     cleanup_table();

//     return 0;
// } 

// int yywrap() {
//     return 1;
// }
