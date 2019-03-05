#include<stdio.h>
#include<stdlib.h>
// #include"quicksort.h"
// #include "insertionsort.h"
#include "sort.h"
#include<time.h>
#include<string.h>

#define lli long long int
#define MAX 130

double testRun(employee* emp, int count) {
	clock_t start, end;
	double qs_time;
	double is_time;
	int i;

	printf("count: %d\n", count);

	if( !count) {
		return 0;
	}

	employee emp_copy[count], emp_copy_2[count];

	for( i=0; i<count; i++) {
		emp_copy[i] = (employee) malloc(sizeof(struct record));
		emp_copy_2[i] = (employee) malloc(sizeof(struct record));
		emp_copy[i] = emp[i];
		emp_copy_2[i] = emp[i];
	}

	start = clock();
		quickSort(emp_copy_2, 0, count-1);
	end = clock();
	qs_time = ( (double) end - start) / CLOCKS_PER_SEC *100;

	start = clock();
		insertionSort(emp_copy, count);
	end = clock();
	is_time = ( (double) end - start) / CLOCKS_PER_SEC*100;

	printf("\nQuick Sort time: %lf, Insertion Sort time %lf\n", qs_time, is_time);

	return is_time - qs_time;
	
}

int estimateCutoff(employee* emp, int count) {
	int min = 0, max = count, mid;
	double tt1, tt2, tt;

	do {
		mid = (int)(min+max)/2;
		tt1 = testRun(emp, (min+mid)/2);
		tt = testRun(emp, mid);
		tt2 = testRun(emp, (mid+max)/2);
		printf("\nmin: %d, mid: %d, max: %d, %lf %lf %lf\n", min, mid, max, tt1, tt, tt2);
		
		if( tt2 < tt) {
			min = mid;
			continue;
		}
		else {
			max = mid;
			continue;
		}
	} while( min < (min + max)/2 && max > (min + max)/2);

	return mid;
}


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

	// printRecords(emp, count);
	// quickSort(emp, 0, count-1);
	// insertionSort(emp, count);

	// lli time_diff = testRun(emp, count);

	// printf("\n\nAfter sorting\n\n");
	// printRecords(emp, count);

	int cutoff = estimateCutoff(emp, count);
	printf("Cutoff is: %d\n", cutoff);

	return 0;
}