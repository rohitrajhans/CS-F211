#include<stdio.h>

int main() {
    int i, j, sum=0;
    printf("Enter a number: ");
    scanf("%d",&i);
    printf("Enter a number: ");
    scanf("%d", &j);
    sum = i+j;
    printf("Sum of %d and %d is: %d\n", i, j, sum);
    return 0;
}
