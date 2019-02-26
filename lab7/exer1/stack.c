#include"stack.h"

stackTop newStack(int capacity) {
	stackTop stack;
	stack = (stackTop) malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->arr = (struct values*) malloc(sizeof(capacity*sizeof(struct values)));
	return stack;
}

int isFull(stackTop stack) {
	if( stack->top == stack->capacity)
		return 1;
	else
		return 0;
}

int isEmpty(stackTop stack) {
	if( stack->top == -1)
		return 1;
	else
		return 0;
}

void push(stackTop stack, int low, int high) {
	if( isFull(stack))
			return;
	(stack->arr[ stack->top + 1]).low = low;
	(stack->arr[ stack->top + 1]).high = high;
	stack->top++;	
}

struct values pop(stackTop stack) {
	if( isEmpty(stack)) {
		struct values val;
		return val;
	}
	return stack->arr[stack->top--];
}

struct values top(stackTop stack) {
	if( isEmpty(stack)) {
		struct values val;
		return val;
	}
	return stack->arr[stack->top];
}
