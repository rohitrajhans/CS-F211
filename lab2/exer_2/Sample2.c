#include<stdio.h>
int main() {
    int num;
    FILE *fp;
    fp = fopen("program.txt", "r");
    if( fp == NULL) {
        printf("Error! opening file \n");
        return 0;
    }
    fscanf(fp, "%d", &num);
    printf("Value of n = %d\n", num);
    fclose(fp);
    return 0;
}
