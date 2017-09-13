/******************
Giavinh Lam
0925571
CIS3490 A3
This function will be run via entering '2' in the main menu of the program (main.c).
This program contains the function to run problem P2.2:
Given a 2D char array to search in, a user-inputted char array, and an array size, it will output the occurences of string matches using Horspool's Algorithm
******************/

#include "functions.h"

int table[300];
int * ShiftTable(char pattern[30])
{
    int i, j;
    for (i = 0; i < 300; i++)
    {
        table[i] = strlen(pattern);
    }
    for (j = 0; j < strlen(pattern)-1; j++)
    {
        table[pattern[j]+'0'] = strlen(pattern)-1-j;
    }
    return table;
}

int HorspoolMatch(char ** array, char pattern[30], int n)
{
    int k = 0;
    int z = 0;
    int counter = 0;
    int shifts = 0;
    ShiftTable(pattern);
    int i = strlen(pattern) - 1;

    for (z = 0; z < n; z++)
    {
        while (i <= strlen(array[z])-1)
        {
            k = 0;
            while (k <= strlen(pattern)-1 && pattern[strlen(pattern)-1-k] == array[z][i-k])
            {
                k++;
            }
            if (k == strlen(pattern))
            {
                counter++;
                shifts++;
                i = i + table[array[z][i]+'0'];
                if (!(array[z][i]+'0' >= 0 && array[z][i]+'0' <= 300))
                {
                    i++;
                }
            }
            else
            {
                shifts++;
                i = i + table[array[z][i]+'0'];
                if (!(array[z][i]+'0' >= 0 && array[z][i]+'0' <= 300))
                {
                    i++;
                }
            }
        }
        i = strlen(pattern) - 1;
    }
    printf("Pattern Shifts: %d\n", shifts);
    return counter;
}
