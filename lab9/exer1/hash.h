#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define BASE 100
int TSIZE;

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

void insert(Hash hashTable, char ** str, int j);

int insertAll( Hash hashtable, char ** str, int size);

rec lookup( Hash hashTable, char ** books, char * str);

int lookupAll(Hash hashTable, char ** books, float m);

void htProfiling(Hash hashTable, char ** books);

void cleanup(Hash hashTable, char ** books, char * filename);

void deleteWord(Hash hashTable, char ** books, char *word);

void printHashTable(Hash hashTable, char ** books);