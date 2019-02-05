#include<stdio.h>
#include<stdlib.h>

int allocatedSpace;

void * myalloc(int size);

void myfree( void * ptr);

struct linkedlist {
	int key;
	struct linkedlist* next;
};

typedef struct linkedlist* listptr;
