#include<stdio.h>
#include<stdlib.h>

struct values {
	int low;
	int high;
};

struct Stack {
	int top;
	int capacity;
	struct values* arr;	
};

typedef struct Stack* stackTop;

stackTop newStack(int capacity);

void push(stackTop, int, int);

int isFull(stackTop);

int isEmpty(stackTop);

struct values top(stackTop);

struct values pop(stackTop);