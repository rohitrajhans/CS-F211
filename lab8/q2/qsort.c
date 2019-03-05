#include "qsort.h"

void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
}

int* readData( char* fileName) {
	FILE* fp = NULL;
	fp = fopen(fileName, "r");

	if(fp == NULL) {
		printf("Error! in opening file\n");
		exit(1);
	}

	fscanf(fp, "%d\n", &size);
	int i=0;
	int * arr = (int *) malloc( sizeof(int) * size);
	char name[11];

	while(!feof(fp)) {
		fscanf(fp, "%s %d\n", name, &arr[i]);
		i++;
	}

	fclose(fp);
	return arr;
}

void quickSortKnownKeyRange( int* Ls, int size, int lo, int hi) {
	KeyStruct keyst = extractKeys(ls, size, lo, hi);
	return;
}