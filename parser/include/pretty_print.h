#pragma once

#include <stdio.h>

// Constants defined for pretty printing
#define MAX_TOKEN_SIZE 24
#define MAX_TOKEN_NAME_SIZE 32
#define MAX_LINENO_SIZE 8


// Helper functions for pretty printing

void print_dash_plus(int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("-");
    }
    printf("+");
}

void print_row_dash()
{
    printf("+");
    print_dash_plus(MAX_TOKEN_SIZE + 7);
    print_dash_plus(MAX_TOKEN_NAME_SIZE + 1);
    print_dash_plus(MAX_LINENO_SIZE + 1);
    printf("\n");
}

void pretty_print(char *token, char token_name[], int line_no)
{
    printf("| %-*s\t| %-*s| %-*d|\n", MAX_TOKEN_SIZE, token,
           MAX_TOKEN_NAME_SIZE, token_name, MAX_LINENO_SIZE, line_no);
}

void pretty_print_error(char *token, char token_name[], int line_no) 
{
    printf("\033[0;31m");
    pretty_print(token, token_name, line_no);
    printf("\033[0m");
}

void print_header()
{
    print_row_dash();
    printf("| %-*s\t| %-*s| %-*s|\n", MAX_TOKEN_SIZE, "TOKEN",
           MAX_TOKEN_NAME_SIZE, "TOKEN_NAME", MAX_LINENO_SIZE, "LINENO");
    print_row_dash();
}

// void print_generic_header(int count, char *header)
// {
//     int i = 0;
//     printf("+");
//     for (i = 0; i < count; i++)
//     {
//         printf("-");
//     }
//     printf("+\n");
//     printf("| %-*s|\n", MAX_TOKEN_SIZE, header);
//     printf("+");
//     for (i = 0; i < count; i++)
//     {
//         printf("-");
//     }
//     printf("+\n");
// }

// n is the length of the header array
void print_generic_header(int count, char *header[], int n)
{
    int i = 0, j = 0;
    printf("+");
    for(i = 0; i < n; i++)
    {
        for (j = 0; j < count; j++)
        {
            printf("-");
        }
        printf("+");
    }
    printf("\n|");
    for(i = 0; i < n; i++)
    {
        printf(" %-*s|", MAX_TOKEN_SIZE, header[i]);
    }
    printf("\n");
    printf("+");
    for(i = 0; i < n; i++)
    {
        for (j = 0; j < count; j++)
        {
            printf("-");
        }
        printf("+");
    }
    printf("\n");
}