#include "merge.h"
#include<stdlib.h>

void main(int argc, char* argv[]) {
	FILE * fp = NULL;
	fp = fopen(argv[1], "r");
	if(fp == NULL) {
		printf("Incorrect file path %s\n", argv[1]);
		exit(1);
	}

	int size=1024; 
	int i=0;
	Element ls[size];
	char name[11];
	float cgpa;

	while(!feof(fp)) {
		fscanf(fp, "%10[^,], %f\n", ls[i].name, &ls[i].cgpa);
		i++;
		// if(i==9) {
		// 	break;
		// }
	}

	// mergeSort(ls, size);
	// printRecords(ls, size);
	iterativeMergeSort(ls, size);
	printRecords(ls, size);
	fclose(fp);
	return;
}