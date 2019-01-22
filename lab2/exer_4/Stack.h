#include"linkedlist.h"
#include<stdio.h>
#include<stdlib.h>

struct Stack {
    struct linkedlist* head;
};

void push(struct Stack* stack, int ele);
int pop(struct Stack* stack);
void printStack(struct Stack* stack);
