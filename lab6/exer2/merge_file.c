#include"merge_file.h"

void sortAndStore(FILE* fp, Element ls[], int size) {
    iterativeMergeSort(ls, size);

    if( fp==NULL) {
        printf("Error! Could not create file\n");
        return;
    }
    int i;
    for( i=0; i<size; i++) {
        fprintf(fp, "Name: %s, CGPA: %f\n", ls[i].name, ls[i].cgpa);
    }
    fclose(fp);
    return;
}