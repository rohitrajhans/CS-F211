#include "merge.h"
#include<string.h>

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]) {
	int i = 0;
	int j = 0;
	int k = 0;
	while( i<sz1 && j<sz2) {
		if( Ls1[i].cgpa <= Ls2[j].cgpa) {
			Ls[k++] = Ls1[i++];
		}
		else {
			Ls[k++] = Ls2[j++];
		}
	}

	while( i<sz1) {
		Ls[k++] = Ls1[i++];
	}

	while( j<sz2) {
		Ls[k++] = Ls2[j++];
	}
}

void mergeSort(Element Ls[], int size) {
	if( size > 1) {
		int mid = size/2;

		int sz1 = mid;
		int sz2 = size-mid;

		Element Ls1[sz1];
		Element Ls2[sz2];

		int i;

		for(i=0; i<sz1; i++) {
			Ls1[i] = Ls[i];
		}
		for(i=0; i<sz2; i++) {
			Ls2[i] = Ls[i+mid];
		}

		mergeSort(Ls1, sz1);
		mergeSort(Ls2, sz2);
		merge(Ls1, sz1, Ls2, sz2, Ls);
	}
	return;
}

void printRecords( Element ls[], int size) {
	int i;
	for( i=0; i<size; i++) {
		printf("Record: %s %lf\n", ls[i].name, ls[i].cgpa);
	}
}

void iterativeMergeSort(Element ls[], int n) {
	int i; // size to compare
	int l;

	for( i=1; i<n; i *= 2) {
		for( l=0; l<n-1; l += i*2) {
			
			int m = l+i-1;
			
			int r;
			if(l+(2*i)-1 > n-1) {
				r = n-1;
			}
			else {
				r = l-1 + (2*i);
			}

			int sz1 = m-l+1;
			int sz2 = r-m;

			Element ls1[sz1];
			Element ls2[sz2];

			int k;
			for(k=0; k<sz1; k++) {
				ls1[k] = ls[k];
			}
			for(k=0; k<sz2; k++) {
				ls2[k] = ls[k+m+1];
			}
			merge(ls1, sz1, ls2, sz2, ls);
		}
	}
}