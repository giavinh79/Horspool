/**************************************************************************************
CIS3490 Assignment 3
Gia Vinh Lam
0925571
glam01@mail.uoguelph.ca
March 2017
This program lets the user find anagrams of a given string in a data file or enter a pattern and find all matching strings in another data file.
***************************************************************************************/

#include "functions.h"

// Main function used to run program from beginning to end.
int main(int argc, char** argv)
{
    if (argc != 3)
    {
        printf("Need to add arguments for two data files (first is for anagrams, second for string matching).\n");
        exit(0);
    }
    FILE * data = NULL;
    FILE * dataTwo = NULL;
    struct timeb start, end;
    int diffOne, diffTwo; //execution time
    char dataText[100000];
    char dataTextTwo[100000];
    char * token;
    int choice;

    char ** arrayOne = (char**) calloc(50000, sizeof(char*));
    for (int i = 0; i < 50000; i++ )
    {
        arrayOne[i] = (char*) calloc(10, sizeof(char));
    }

    char ** arrayTwo = (char**) calloc(44049, sizeof(char*));
    for (int i = 0; i < 44049; i++ )
    {
        arrayTwo[i] = (char*) calloc(81, sizeof(char));
    }

    char string[20]; //input for anagrams function
    int size = 0;
    int n; //array size for part 2
    int j = 0;
    choice = 1;
    diffOne = 0;
    data = fopen(argv[1], "r"); // Open first data file and parses information into an array

    while (fgets(dataText, 100000, data))
    {
        if (dataText[strlen(dataText)-2] == ' ')
        {
            dataText[strlen(dataText)-2] = '\0';
        }
        token = strtok(dataText, " ");
        strcpy(arrayOne[j], token);
        while (token != NULL)
        {
            j++;
            token = strtok(NULL, " ");
            if (token != NULL)
            {
                strcpy(arrayOne[j], token);
            }
        }
    } size = j;
    j = 0;

    dataTwo = fopen(argv[2], "r"); // Opens second data file and parses information into an array
    while (fgets(dataTextTwo, 100000, dataTwo))
    {
        strcpy(arrayTwo[j], dataTextTwo);
        j++;
    }
    n = j;

    printf("Welcome to the program! This program was written by Gia Vinh Lam for CIS3490.\n");
    printf("P1.1 and P1.2 use the first data file. P2.1, P2.2, and P2.3 use the second\n");
    while (choice == 1 || choice == 2)
    {
        printf("Press 1 for P1.1 && P1.2, 2 for P2.1 && for P2.2, or any other number to exit.\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Please enter a string to find anagrams of (<20 characters).\n");
            scanf("%s", string);

            printf("Anagrams: \n");
            ftime(&start);
            printf("%d anagrams found from data file via brute force.\n", BruteForceAnagram(arrayOne, string, size));
            ftime(&end);
            diffOne = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
            printf("Execution time of Brute Force: %u milliseconds.\n\n", diffOne); 

            printf("Anagrams: \n"); BruteForceAnagram(arrayOne, string, size);
            ftime(&start);
            printf("%d anagrams found from data file via Presort.\n", PreSortAnagram(arrayOne, string, size));
            ftime(&end);
            diffTwo = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
            printf("Execution time of presort approach: %u milliseconds.\n", diffTwo);
        }
        else if (choice == 2)
        {
            printf("Please enter a pattern (string to search for).\n");
            scanf("%s", string);

            ftime(&start);
            printf("%d occurences found via brute force.\n", BruteForceMatch(arrayTwo, string, n));
            ftime(&end);
            diffOne = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
            printf("Execution time of Brute Force: %u milliseconds.\n\n", diffOne);

            ftime(&start);
            printf("%d occurences found via Horspool's Algorithm.\n", HorspoolMatch(arrayTwo, string, n));
            ftime(&end);
            diffOne = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
            printf("Execution time of Horspool's: %u milliseconds.\n", diffOne);

        }
    }

    printf("Thanks for using the program!\n");

    for (int i = 0; i < 44049; i++ )
    {
        free(arrayTwo[i]);
    }

    for (int i = 0; i < 50000; i++ )
    {
        free(arrayOne[i]);
    }

    free(arrayOne);
    free(arrayTwo);
    return 0;
}
