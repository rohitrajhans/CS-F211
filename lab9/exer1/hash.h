#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct record* rec;

struct record {
    int index;
    int count;
    rec next;
};

typedef struct hashTable* Hash;

struct hashTable {
    rec* slot; 
    // Create a hash table with given number of slots; Each slot is a linked list of records
    int elementCount;
    int insertionCost;
    int queryingCost;
};

int hashF(char*, int baseNumber, int tableSize);

int collisionCount(char **, int, long long int, int);

void profiling(char **, int);

int optimalBase(char**, int, long long int);

int isPrime(int n);

int min(int, int);

Hash createHashTable(int size);