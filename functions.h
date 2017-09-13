#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/timeb.h>
#include <stdint.h>
#include <stdlib.h>

int BruteForceAnagram(char ** array, char string[20], int n);
int PreSortAnagram(char ** array, char string[20], int n);
int BruteForceMatch(char ** array, char pattern[30], int n);
int HorspoolMatch(char ** array, char pattern[30], int n);
uint8_t* boyer_moore (uint8_t *string, uint32_t stringlen, uint8_t *pat, uint32_t patlen);
