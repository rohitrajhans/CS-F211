#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int size;
int count;
struct record {
	char card[30];
	char bank_code[30];
	char date[30];
	char fname[30];
	char lname[30];
};
struct record * records;

void printRecords() {
	int i;
	for( i = 0; i<count; i++) {
		printf("%s, %s, %s, %s, %s\n", records[i].card, records[i].bank_code, records[i].date, records[i].fname, records[i].lname);
	}
}

int insertInOrder(int n) {

    struct record last = records[n-1];
    int j = n-2;

    while (j >= 0 && (strcmp(records[j].card, last.card) > 0 )) 
    { 
        records[j+1] = records[j];
        j--; 
    } 
    records[j+1] = last; 
}

void addRecord(char* card, char* bank_code, char* date, char* fname, char* lname) {
	if( size==0 ) {
		records = (struct record *)malloc(sizeof(struct record));
		size += sizeof(struct record);
	}
	else if( (sizeof(struct record) * (count+1)) >= size) {
		records = (struct record *)realloc(records, size*2);
		size *= 2;
	}
	int i = count;
	strcpy(records[i].card, card);
	strcpy(records[i].bank_code, bank_code);
	strcpy(records[i].date, date);
	strcpy(records[i].fname, fname);
	strcpy(records[i].lname, lname);
	count++;
	insertInOrder(count);
}

void main() {
	FILE * ptr = NULL;
	ptr = fopen("10.txt", "r");
	if( ptr == NULL) {
		printf("Error! File not found.\n");
		return;
	}
	char card[30], bank_code[30], date[30], fname[30], lname[30];

	count = 0;
	size = 0;

	clock_t start = clock();

	while( !feof(ptr)) {
		fgetc(ptr);
		fscanf(ptr, "%29[^,], %29[^,], %29[^,], %29[^,], %[^\"]\"\n", card, bank_code, date, fname, lname);
		addRecord(card, bank_code, date, fname, lname);
		// printf("Read: %s %s %s %s %s\n", card, bank_code, date, fname, lname);
	}

	clock_t end = clock();

	printRecords();
	printf("Count: %d\n", count);
	printf("Elapsed: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
	fclose(ptr);
}