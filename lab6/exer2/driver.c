#include "merge_file.h"
#include <string.h>
#define NO_OF_SLOTS 512
#define MAX 10240

void main( int argc, char* argv[]) {
    FILE* fp = NULL;
    FILE *fpw;
    fp = fopen(argv[1], "r");
    if( !fp) {
        printf("Error! in opening file\n");
        return;
    }

    int k = NO_OF_SLOTS;
    char name[11];
    char file_name[15];
    
    float cgpa;
    int tot_size = MAX;
    int size = tot_size/k;
    Element ls[size];
    int i = 0, c = 0;
    while( !feof(fp)) {
        while( ( i < size) && (!feof(fp))) {
            fscanf(fp, "%10[^,], %f\n", ls[i].name, &ls[i].cgpa);
            i++;
            if( i>=size) {
                break;
            }
        }
        k--;
        c++;
        sprintf(file_name, "temp%d.txt", c);
        fpw = fopen(file_name, "w");
        sortAndStore(fpw, ls, size);
        i = 0;
        // printf("%s\n", file_name);
    }

    

    fclose(fp);
    return; 
}