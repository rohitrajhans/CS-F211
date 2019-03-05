#include"sort.h"

#define MAX_STACK 100

int pivot( employee* emp, int low, int high) {
	return high;
}

int partition(employee* emp, int low, int high, int piv) {
	int i = low - 1;
	int j;
	for( j = low; j<=high-1; j++) {
		if( emp[j]->empID <= emp[piv]->empID) {
			i++;
			swapRecords(emp[i], emp[j]);
		}
	}
	swapRecords(emp[i+1], emp[piv]);
	return i+1;
}

void quickSort(employee* emp, int low, int high) {
	stackTop stack = newStack(MAX_STACK);
	struct values val;
	push(stack, low, high);
	while( !isEmpty(stack)) {
		val = pop(stack);
		int piv = pivot(emp, val.low, val.high);
		piv = partition(emp, val.low, val.high, piv);
		if( piv-1 > val.low)
			push(stack, val.low, piv-1);
		if( piv+1 <  val.high)
			push(stack, piv+1, val.high);
	}
}

void insertionSort(employee* emp, int size) {
    int i, j;
    employee key;

    for( i = 1; i<size; i++) {
        key = emp[i];
        j = i-1;

        while( j >= 0 && emp[j]->empID > key->empID) {
            emp[j+1] = emp[j];
            j = j-1;
        }
        emp[j+1] = key;
    }
}