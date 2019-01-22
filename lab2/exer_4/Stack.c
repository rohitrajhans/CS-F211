#include"Stack.h"

void push(struct Stack* stack, int ele) {
    if( stack->head == NULL) {
        stack->head = (struct linkedlist*) malloc(sizeof(struct linkedlist));
    }
    insertFirst(stack->head, ele);
}

int pop(struct Stack* stack) {
    deleteFirst(stack->head);
}

void printStack(struct Stack* stack) {
    printList(stack->head);
}
