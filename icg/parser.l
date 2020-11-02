%{

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "y.tab.h"
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
    return INT;
}

"short" {
    return SHORT;
}

"long" {
    return LONG;
}

"long long" {
    return LONG_LONG;
}

"float" {
    return FLOAT;
}

"char" {
    return CHAR;
}

"double" {
    return DOUBLE;
}

"for" {
    return FOR;
}

"while" {
    return WHILE;
}

"do" {
    return DO;
}

"if" {
    return IF;
}

"else" {
    return ELSE;
}

"signed" {
    return SIGNED;
}

"unsigned" {
    return UNSIGNED;
}

"struct" {
    return STRUCT;
}

"continue" {
    return CONTINUE;
}

"break" {
    return BREAK;
}

"void" {
    return VOID;
}

"return" {
    return RETURN;
}

"switch" {
    return SWITCH;
}

"case" {
    return CASE;
}

"default" {
    return DEFAULT;
}

"sizeof" {
    return SIZEOF;
}

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
    yylval.Value = strdup(yytext);
    return OPEN_SQUARE;
}
\]  {
    yylval.Value = strdup(yytext);
    return CLOSE_SQUARE;
}

 /* operators */
(">=") {
    yylval.Value = strdup(yytext);
    return GREATER_THAN_OR_EQUAL_TO;
}
("<=") {
    yylval.Value = strdup(yytext);
    return LESSER_THAN_OR_EQUAL_TO;
}
("==") {
    yylval.Value = strdup(yytext);
    return EQUAL_COMPARATOR;
}
("!=") {
    yylval.Value = strdup(yytext);
    return NOT_EQUAL_COMPARATOR;
}
("<") {
    yylval.Value = strdup(yytext);
    return LESSER_THAN;
}
(">") {
    yylval.Value = strdup(yytext);
    return GREATER_THAN;
}
("&&") {
    yylval.Value = strdup(yytext);
    return AND_OPERATOR;
}
("||") {
    yylval.Value = strdup(yytext);
    return OR_OPERATOR;
}
("!") {
    yylval.Value = strdup(yytext);
    return EXCLAMATION_OPERATOR;
}
("&") {
    yylval.Value = strdup(yytext);
    return BITWISE_AND_OPERATOR;
}
("|") {
    yylval.Value = strdup(yytext);
    return BITWISE_OR_OPERATOR;
}
("~") {
    yylval.Value = strdup(yytext);
    return BITWISE_COMPLEMENT_OPERATOR;
}
(">>") {
    yylval.Value = strdup(yytext);
    return RIGHT_SHIFT_OPERATOR;
}
("<<") {
    yylval.Value = strdup(yytext);
    return LEFT_SHIFT_OPERATOR;
}
("+") {
    yylval.Value = strdup(yytext);
    return ADD;
}
("-") {
    yylval.Value = strdup(yytext);
    return SUBTRACT;
}
("*") {
    yylval.Value = strdup(yytext);
    return MULTIPLICATION_OPERATOR;
}
("/") {
    yylval.Value = strdup(yytext);
    return DIVISION;
}
("%") {
    yylval.Value = strdup(yytext);
    return MODULO;
}
("=") {
    yylval.Value = strdup(yytext);
    return ASSIGNMENT_OPERATOR;
}
("+=") {
    yylval.Value = strdup(yytext);
    return ADD_ASSIGNMENT_OPERATOR;
}
("-=") {
    yylval.Value = strdup(yytext);
    return SUBTRACTION_ASSIGNMENT_OPERATOR;
}
("/=") {
    yylval.Value = strdup(yytext);
    return DIVISION_ASSIGNMENT_OPERATOR;
}
("*=") {
    yylval.Value = strdup(yytext);
    return MULTIPLICATION_ASSIGNMENT_OPERATOR;
}

("^") {
    yylval.Value = strdup(yytext);
    return CARET_OPERATOR;
}

("++") {
    yylval.Value = strdup(yytext);
    return INCREMENT_OPERATOR;
}

("--") {
    yylval.Value = strdup(yytext);
    return DECREMENT_OPERATOR;
}

("<<=") {
    yylval.Value = strdup(yytext);
    return LEFT_SHIFT_ASSIGNMENT_OPERATOR;
}

(">>=") {
    yylval.Value = strdup(yytext);
    return RIGHT_SHIFT_ASSIGNMENT_OPERATOR;
}

("^=") {
    yylval.Value = strdup(yytext);
    return XOR_ASSIGNMENT_OPERATOR;
}

("|=") {
    yylval.Value = strdup(yytext);
    return OR_OPERATOR;
}

("&=") {
    yylval.Value = strdup(yytext);
    return AND_ASSIGNMENT_OPERATOR;
}

("%=") {
    yylval.Value = strdup(yytext);
    return MODULO_ASSIGNMENT_OPERATOR;
}

 /* Identifers */
{ID} {
    yylval.Value = strdup(yytext);
    return IDENTIFIER;
}

 /* Literals */
{DIGIT}* {
    yylval.Value = strdup(yytext);
    return INTEGER_CONSTANT;
}

{DIGIT}*{ALPHA_NUM}* {
    return INVALID_INTEGER;
}

{DIGIT}*\.{DIGIT}* {
    yylval.Value = strdup(yytext);
    return FLOAT_CONSTANT;
}

{DIGIT}*\.{ALPHA_NUM}*([\.]*{ALPHA_NUM}*)+ {
    return  INVALID_FLOAT;
}

\'(.)?\' {
    yylval.Value = strdup(yytext);
    return CHARACTER_CONSTANT;
}

\'(.)*\' {
    return INVALID_CHARACTER;
}
 
\"(.)*\" {
    yylval.Value = strdup(yytext);
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
