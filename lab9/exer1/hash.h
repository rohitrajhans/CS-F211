#include<stdio.h>
#include<string.h>

int hashF(char*, int baseNumber, int tableSize);

int collisionCount(char **, int, int, int);

void profiling(char **, int);

int optimalBase(char**, int, int, int, int, int, int, int, int);