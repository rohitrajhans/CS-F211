#include"employee.h"
#include<string.h>

void swapRecords(employee e1, employee e2) {
	struct record temp;
	strcpy(temp.name, e1->name);
	temp.empID = e1->empID;
	strcpy(e1->name, e2->name);
	e1->empID = e2->empID;
	strcpy(e2->name, temp.name);
	e2->empID = temp.empID;
	return;
}

void printRecords(employee* emp, int capacity) {
	int i;
	for( i=0; i<capacity; i++) {
		printf("%s, ID:%d\n", emp[i]->name, emp[i]->empID);
	}
}