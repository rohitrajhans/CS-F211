#include"Stack.h"

int main(int argc, char *argv[]) {
    struct Stack* stack = (struct Stack*) malloc(sizeof( struct Stack));
    FILE *fp = NULL;
    fp = fopen(argv[1], "r");

    while( !feof(fp)) {
        int temp;
        fscanf(fp, "%d ", &temp);
        push(stack, temp);
    }

    fclose(fp);

    printStack(stack);
    pop(stack);
    printStack(stack);
    return 0;
}

