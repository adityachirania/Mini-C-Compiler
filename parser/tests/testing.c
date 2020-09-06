// Preprocessor directives
#include <stdio.h>
#include "stdlib.h"

/* 
    Multi line comment
*/

// Macro
#define PI 3.14

// Variable decalarations
int a = 5;
int b[4] = {4, 5, 7, 8};
int c = {5, 4, 7, 8};
int d[][2][2] = {{1,2},{3,5+6}};
int e = {1,2,3};

// Pointer declaration
int ***f;
int *g[5] = {1, 2, 3, 4};
char *str;


void main()
{
    #define MACRO1 5
    
    int i;
    // for loop
    for(i = 0; i < 6; i++)
    {
        // if condition
        if( i < 2)
        {
            printf("Hello world\n");
        }
        // else condition
        else
        {
            // while condition
            while(i >2 )
            {
                // decrement operator
                i -= 1;
                break;
            }
        }
    }

    switch(i)
    {
        case 1: {
            // statements
        }
        case 2: break;

        default: break;
    }

    // sizeof statement

    int j = i + sizeof(int) * sizeof(i);

    // return statement
    return;
}