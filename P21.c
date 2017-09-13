/******************
Giavinh Lam
0925571
CIS3490 A3
This function will be run via entering '2' in the main menu of the program (main.c).
This program contains the function to run problem P2.1:
Given a 2D char array to search in, a user-inputted char array, and an array size, it will output the occurences of string matches using brute force
******************/

#include "functions.h"

int BruteForceMatch(char ** array, char pattern[30], int n)
{
    int counter = 0;
    int length = strlen(pattern);
    int plength = 0;
    int shifts = 0;
    int z = 0;
    int i = 0;
    int j = 0;

    for (z = 0; z < n; z++)
    {
        plength = strlen(array[z]);
	for (i = 0; i < plength-length; i++) 
        {
            while (j < length && pattern[j] == array[z][i+j])
            {
                j++;
            }
            if (j == length)
            {
                counter++;
            } j = 0;
            shifts++;
        }
    }
    printf("Pattern Shifts: %d\n", shifts);
    return counter;
}

