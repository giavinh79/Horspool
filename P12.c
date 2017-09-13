/******************
Giavinh Lam
0925571
CIS3490 A3
This function will be run via entering '1' on the main menu of the program (main.c).
This program contains the function(s) to run problem P1.2:
Given a 2D char array to search in, a user-inputted char array and an array size, it will output the anagrams found through presort
******************/

#include "functions.h"

int BinarySearch(char ** array, char string[20], int low, int high) // typical binary search function (searching for a value in a sorted array)
{
    int mid = 0;
    //low = 0;
    //high = N - 1;

    while (low <= high)
    {
          mid = (low + high) / 2;
          if (strcmp(array[mid], string) < 0)
          {
              high = mid - 1;
          }
          else if (strcmp(array[mid], string) > 0)
          {
              low = mid + 1;
          }
          else
          {
              if (mid != 0)
              {
                  while (strcmp(array[mid], string) == 0)
                  {
                      mid--;
                  }
                  return mid+1;
              }
              return mid;
          }
    }
      return -1; // value would be inserted at index "low"
}

int cmpArr(const void *a, const void *b) 
{
    return -1*(*(const char *)a - *(const char *)b); // comparing two characters, -1 in front for descending order
}

int cmp2DArr(const void *a, const void *b) 
{
    return -1*strcmp(*(char **)a, *(char **)b); // comparing two char arrays, -1 in front for descending order
}

// Main Function
// "Double Presorting Method" Sort strings into its "signature" (ex. in ascending order)
int PreSortAnagram(char ** array, char string[20], int n)
{
    int counter = 0; // number of anagrams found
    int i = 0;
    int j = 0;

    qsort(string, strlen(string), 1, cmpArr); // sort string for future comparisons

    for (i = 0; i < n; i++) // sorting each char array in the 2D char array
    {
        qsort(array[i], strlen(array[i]), 1, cmpArr);
    }

    qsort(array, n, sizeof (char*), cmp2DArr); // sorting the 2D char array

    //printf("actual organized string %s\n", string);
    if (BinarySearch(array, string, 0, n-1) != -1)
    {
        while (strcmp(array[BinarySearch(array, string, 0, n-1)+j], string) == 0)
        {
            j++;
            counter++;
        }
    }
    return counter;
}

