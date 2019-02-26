#include<stdio.h>
#include<stdlib.h>
#include"quicksort.h"
#define MAX 10

int main() {
	FILE * fp = NULL;
	fp = fopen("10", "r");
	if( fp==NULL) {
		printf("File not found! \n");
		return -1;
	}

	char name[11];
	int empID, count = -1;

	employee emp[MAX];

	while( !feof(fp)) {
		count++;
		emp[count] = (employee) malloc(sizeof(struct record));
		fscanf(fp, "%s %d", emp[count]->name, &emp[count]->empID);
	}

	printRecords(emp, count);
	quickSort(emp, 0, count-1);
	printf("\n\nAfter sorting\n\n");
	printRecords(emp, count);

	return 0;
}