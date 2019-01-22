#include<stdio.h>

int main( int argc, char *argv[] ) {
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "w");
    fp2 = fopen(argv[2], "r");
    if( fp1 == NULL) {
        printf("Error!\n");
        return 0;
    }
    if(fp2 == NULL) {
        printf("Error! opening file\n");
        return 0;
    }

    char c;
    while( (c = fgetc(fp2)) != EOF ) {
        fputc(c, fp1);
    }
    fclose(fp1);
    fclose(fp2);

    return 0;
}
    
