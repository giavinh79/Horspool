/******************
Giavinh Lam
0925571
CIS3490 A3
This function will be run via entering '1' in the main menu of the program (main.c).
This program contains the function to run problem P1.1:
Given a 2D char array to search in, a user-inputted char array, and an array size, it will output the anagrams found through brute force
******************/

#include "functions.h"

int BruteForceAnagram(char ** array, char string[20], int n)
{
    int countOne[100] = {0};
    int countTwo[100] = {0};
    int counter = 0; // number of anagrams found
    int i, z, y, g;
    int check = 0;

    for (z = 0; z < strlen(string); z++)
    {
        countOne[(int)string[z]]++;
    }

    for (i = 0; i < n; i++)
    {
        if (strlen(string) != strlen(array[i]))
        {
            continue;
        }

        for (y = 0; y < strlen(string); y++)
        {
            countTwo[(int)array[i][y]]++;
        }

        for (g = 0; g < 100; g++)
        {
            if (countOne[g] != countTwo[g])
            {
                check = 1;
            }
        }

        if (check == 0)
        {
            printf("%s\n", array[i]);
            counter++;
        }
        check = 0;
        memset(countTwo, 0, sizeof(int)*100);
    }
    return counter;
}
