#include<stdio.h>
#include<time.h>
#define MAX 10000

void main() {

	FILE * fp = NULL; 
	fp = fopen("random.txt", "w");
	if( fp == NULL) {
		printf("Error creating a new file\n");
		return;
	}

	int count = MAX;

	srand(time(0));
	while( count) {
		char credit[17];
		int i;
		for( i = 0; i<16; i++) {
			credit[i] = rand()%10 + 48;
		}
		credit[16] = '\0';
		fprintf(fp, "%s\n", credit);
		count--;
	}
}