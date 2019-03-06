#include "merge.h"
#include<stdlib.h>
#include<time.h>

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

	clock_t start, end;
	double time_taken;

	start = clock();
	mergeSort(ls, size);
	end = clock();
	printRecords(ls, size);

	// start = clock();
	// iterativeMergeSort(ls, size);
	// end = clock();
	
	time_taken = (double) (end - start);
	time_taken = time_taken / CLOCKS_PER_SEC * 100;
	printRecords(ls, size);
	printf("Time taken for merge sort: %lfms\n", time_taken);
	fclose(fp);
	return;
}