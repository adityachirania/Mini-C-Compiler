#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pretty_print.h"

// Data structure for storing symbols in program
struct list
{
    char *item;
    char *type;
    struct list *next;
}  *constants_list = NULL;

struct symbol_table_entry
{
    char *symbol;
    char *class;
    char *type;
    int start_lineno;
    int end_lineno;
    char *arglist;
    char **arglist_type;
    int nesting;
    struct symbol_table_entry *next;
} *identifiers_list;

// Print contents of constant table
void print_constant_table(struct list **table, char *list_name)
{
    int i = 0;
    char *headers[1];
    headers[0] = "Constant";
    print_generic_header(MAX_TOKEN_SIZE + 1, headers, 1);
    struct list *p = *table;
    while (p != NULL)
    {
        printf("| %-*s|\n", MAX_TOKEN_SIZE, p->item);
        p = p->next;
    }
    printf("+");
    print_dash_plus(MAX_TOKEN_SIZE + 1);
    printf("\n");
}

// Check if an element is present in constant table
int check_present(struct list **table, char *str)
{
    struct list *p = *table;
    while (p != NULL)
    {
        if (strcmp(p->item, str) == 0)
        {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

int check_if_declared(struct symbol_table_entry **table, char *str) {
    struct symbol_table_entry *p = *table;
    while (p != NULL)
    {
        if (strcmp(p->symbol, str) == 0)
        {
            if(p->type == NULL) {
                return 0;
            }
            return 1;
        }
        p = p->next;
    }
    return 0;
}

// Add an element to constant table
void add_to_constant_table(struct list **table, char *str)
{
    // Insert to symbol table if element
    // not already present
    if (!check_present(table, str))
    {
        struct list *p = *table;
        struct list *new_item = (struct list *) malloc(sizeof(struct list));
        
        char *str_cpy = (char *)malloc((strlen(str) + 1) * sizeof(char));
        strcpy(str_cpy, str);
        new_item->item = str_cpy;
        new_item->next = NULL;

        // if first element is being
        // inserted to the table
        if (p == NULL)
        {
            *table = new_item;
        }
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = new_item;
        }
    }
}

// Print contents of symbol table
void print_symbol_table(struct symbol_table_entry **table)
{
    int i = 0;
    char *headers[4];
    headers[0] = "Symbol";
    headers[1] = "Class";
    headers[2] = "Type";
    headers[3] = "Boundary";
    headers[4] = "Nesting";
    print_generic_header(MAX_TOKEN_SIZE + 1, headers, 5);
    struct symbol_table_entry *p = *table;
    while (p != NULL)
    {
        char boundary[100];
        char nest[100];
        sprintf(boundary, "%d-%d", p->start_lineno, p->end_lineno);
        if(strcmp(boundary, "0-0") == 0)
        {
            if(strcmp(p->class, "IDENTIFIER") == 0 && !(strcmp(p->type, "UNDECLARED") == 0))
            {
                strcpy(boundary, "global");
            }
            else
            {
                strcpy(boundary, "");
            }
            
        }
        char final_sym[100];
        // strcpy(final_sym, p->symbol);
        sprintf(final_sym, "%s %s", p->symbol, p->arglist);
        if(p->nesting == 0)
        {
            sprintf(nest, "%s", "");
        }
        else
        {
            sprintf(nest, "%d", p->nesting);
        }

        if(p->type == NULL) {
            printf("!!!\n");
        }
        
        printf("| %-*s| %-*s| %-*s| %-*s| %-*s|\n", MAX_TOKEN_SIZE, final_sym, MAX_TOKEN_SIZE, p->class, MAX_TOKEN_SIZE, p->type, MAX_TOKEN_SIZE, boundary, MAX_TOKEN_SIZE, nest);
        p = p->next;
    }
    printf("+");
    print_dash_plus((MAX_TOKEN_SIZE + 1)*5 + 4);
    printf("\n");
}

void insert_symbol_type(struct symbol_table_entry **table, char *symbol, char* type)
{
    struct symbol_table_entry *p = *table;
    while (p != NULL)
    {
        if (strcmp(p->symbol, symbol) == 0)
        {
            char *type_cpy = (char *)malloc((strlen(type) + 1) * sizeof(char));
            strcpy(type_cpy, type);
            p->type = type_cpy;
            return ;
        }
        p = p->next;
    }
}

void insert_symbol_class(struct symbol_table_entry **table, char *symbol, char* class)
{
    struct symbol_table_entry *p = *table;
    while (p != NULL)
    {
        if (strcmp(p->symbol, symbol) == 0)
        {
            char *class_cpy = (char *)malloc((strlen(class) + 1) * sizeof(char));
            strcpy(class_cpy, class);
            p->class = class_cpy;
            return ;
        }
        p = p->next;
    }
}

void insert_symbol_array_dimension(struct symbol_table_entry **table, char *symbol, char* value)
{
    struct symbol_table_entry *p = *table;
    while (p != NULL)
    {
        if (strcmp(p->symbol, symbol) == 0)
        {
            char type_cpy[100];
            strcpy(type_cpy, p->type);
            char open_brack[100] = "[";
            char close_brack[100] = "]";
            strcat(type_cpy, strcat(open_brack, strcat(value, close_brack)));
            strcpy(p->type, type_cpy);
            return ;
        }
        p = p->next;
    }
}

void insert_symbol_start_lineno(struct symbol_table_entry **table, char *symbol, int startlineno)
{
    struct symbol_table_entry *p = *table;
    while (p != NULL)
    {
        if (strcmp(p->symbol, symbol) == 0)
        {
            p->start_lineno = startlineno;
            return ;
        }
        p = p->next;
    }
}

void insert_symbol_end_lineno(struct symbol_table_entry **table, char *symbol, int endlineno)
{
    struct symbol_table_entry *p = *table;
    while (p != NULL)
    {
        if (strcmp(p->symbol, symbol) == 0)
        {
            p->end_lineno = endlineno;
            return ;
        }
        p = p->next;
    }
}

void insert_symbol_arg_list(struct symbol_table_entry **table, char* symbol, char *arglist)
{

    struct symbol_table_entry *p = *table;
    while (p != NULL)
    {
        if (strcmp(p->symbol, symbol) == 0)
        {
            char *arg_cpy = (char *)malloc((strlen(arglist) + 1) * sizeof(char));
            strcpy(arg_cpy, arglist);
            p->arglist = arg_cpy;
        }
        p = p->next;
    }
}

void insert_arglist_type(struct symbol_table_entry **table, char* symbol, char arglist[][100])
{
    struct symbol_table_entry *p = *table;
    while (p != NULL)
    {
        if (strcmp(p->symbol, symbol) == 0)
        {   
            int i = 0;
            while(strlen(arglist[i]) != 0) {
                i++;
            }

            p->arglist_type = malloc(i * sizeof(*arglist));

            for(int j = 0; j < i; j++) {
                p->arglist_type[j] = strdup(arglist[j]);
            }

            break;

        }
        p = p->next;
    }
}

char* get_arg_type(struct symbol_table_entry **table, char* symbol, int index) {
    struct symbol_table_entry *p = *table;
    while (p != NULL)
    {
        if (strcmp(p->symbol, symbol) == 0)
        {  
            return p->arglist_type[index];
        }
        p = p->next;
    }
    return "";
}

int check_present_identifier(struct symbol_table_entry **table, char *symbol, int lineno)
{
    struct symbol_table_entry *p = *table;
    while (p != NULL)
    {
        if (strcmp(p->symbol, symbol) == 0 && lineno >= p->start_lineno && p->end_lineno == 0 && strcmp(p->type, "UNDECLARED") != 0)
        {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

int check_present_function(struct symbol_table_entry **table, char *symbol)
{
    struct symbol_table_entry *p = *table;
    while (p != NULL)
    {
        if (strcmp(p->symbol, symbol) == 0 && strcmp(p->class, "FUNCTION") == 0)
        {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

// Check if an element is present in symbol table
int check_present_symbol(struct symbol_table_entry **table, char *symbol)
{
    struct symbol_table_entry *p = *table;
    while (p != NULL)
    {
        if (strcmp(p->symbol, symbol) == 0)
        {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

char* get_type(struct symbol_table_entry **table, char *symbol, int lineno) {
    struct symbol_table_entry *p = *table;
    while (p != NULL)
    {
        if (strcmp(p->symbol, symbol) == 0)
        {
            // printf("%d %d", p->start_lineno, p->end_lineno);
            return p->type;
        }
        p = p->next;
    }
}

void append_pointer_type(struct symbol_table_entry **table, char *symbol)
{
    struct symbol_table_entry *p = *table;
    while (p != NULL)
    {
        if (strcmp(p->symbol, symbol) == 0)
        {
            char aug_type[100];
            sprintf(aug_type, "*%s", p->type);
            p->type = aug_type;
            return 1;
        }
        p = p->next;
    }
    return 0;
}

void insert_symbol_nesting(struct symbol_table_entry **table, char *symbol, int nesting)
{
    // return;
    struct symbol_table_entry *p = *table;
    while (p != NULL)
    {
        if (strcmp(p->symbol, symbol) == 0)
        {
            p->nesting = nesting;
            return 1;
        }
        p = p->next;
    }
    return 0;
}

// Add an element to constant table
void add_to_symbol_table(struct symbol_table_entry **table, char *symbol, char *class)
{
    // Insert to symbol table if element
    // not already present
    if (!check_present_symbol(table, symbol))
    {
        struct symbol_table_entry *p = *table;
        struct symbol_table_entry *new_item = (struct symbol_table_entry *) malloc(sizeof(struct symbol_table_entry));
        
        char *symbol_cpy = (char *)malloc((strlen(symbol) + 1) * sizeof(char));
        strcpy(symbol_cpy, symbol);
        char *class_cpy = (char *)malloc((strlen(symbol) + 1) * sizeof(char));
        strcpy(class_cpy, class);
        new_item->symbol = symbol_cpy;
        new_item->class = class_cpy;
        new_item->type = "UNDECLARED";
        new_item->arglist = "";
        new_item->nesting = 0;
        new_item->next = NULL;

        // if first element is being
        // inserted to the table
        if (p == NULL)
        {
            *table = new_item;
        }
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = new_item;
        }
    }
}

// Cleanup created symbol table
void cleanup_table()
{
    free(identifiers_list);
    free(constants_list);
}
