#include<stdio.h>

struct Student {
	char name[11];
	float cgpa;
};

typedef struct Student Element;

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);
void mergeSort(Element Ls[], int size);
void iterativeMergeSort(Element Ls[], int n);
void printRecords(Element Ls[], int size);