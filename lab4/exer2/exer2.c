#include"main.h"

void * myalloc(int size) {
	void * ptr = malloc(size+4);
	allocatedSpace += size;
	int * pad;
	pad = (int *)ptr;
	pad[0] = size;
	// printf("Allocated Space: %d\n", allocatedSpace);
	return ptr+4;
}

void myfree( void * ptr) {
	if(  ptr == NULL) {
		return;
	}
	int* pad;
	pad = (int *)(ptr - 4);
	allocatedSpace -= pad[0];
	free(ptr);
	return;
}

/*
int main() {
	int *ptr1 = NULL;
	int m = 1;
	int size = m;
	
	while( m!=0) {
		printf("Enter memory to be allocated: ");
		scanf("%d", &m);
		ptr1 = (int *) myalloc(m);
		printPointer(ptr1, m);
		myfree(ptr1);
	}
	
	myfree(ptr1);
	return 0;
}
*/

void printPointer(void * ptr1, int m) {
	printf("First: %u, Last: %u\n", ptr1, &ptr1[m-1]);
	printf("First: %u, Last: %u\n", ptr1, &ptr1[m-1]);
	return;
}

