#include<stdio.h>

struct record {
	char name[11];
	int empID;
};

typedef struct record* employee;

void swapRecords(employee, employee);

void printRecords(employee*, int);