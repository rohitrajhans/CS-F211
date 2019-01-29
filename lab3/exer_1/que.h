#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Element {
    int value;
    struct Element * next;
	int priority;
};

struct Queue {
    struct Element * head;
    struct Element * tail;
	int priority;
};

struct Queue* newQ();

bool isEmptyQ(struct Queue* q);

struct Queue* delQ(struct Queue* q);

struct Element* front(struct Queue* q);

struct Queue* addQ(struct Queue* q, struct Element* e);

int lengthQ( struct Queue* q);

struct Element* newElement(int i);

void printQueue(struct Queue* q);
