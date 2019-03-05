#include "insertionsort.h"

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