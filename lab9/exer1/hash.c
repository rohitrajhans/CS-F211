#include"hash.h"

int hashF(char* string, int base, int ts) {
	int sum = 0, i, hashValue;
	for(i=0; i<strlen(string); i++) {
		sum += string[i];
	}
	hashValue = (sum % base) % ts;
	// printf("%d %d\n", hashValue, sum);
	return hashValue;
}

int collisionCount(char** stringArr, int base, long long int ts, int n) {
	int arr[ts], i, hashValue, col=0;
	for( i=0; i<ts; i++) {
		arr[i] = 0;
	}
	for( i=0; i<n; i++) {
		hashValue = hashF(stringArr[i], base, ts);
		// printf("%s %d %d\n", stringArr[i], hashValue, arr[hashValue]);
		arr[hashValue]++;
		// printf("%d: %d\n", arr[hashValue], hashValue);
		if( arr[hashValue] > 1)
			col++;
	}

	// printf("Total number of collisions are: %d\n", col);
	return col;
}

void profiling( char** book, int n) {
	long long int base, ts;

	int arr1[18];
	int i, c1, c2, c3;
	ts = 5000;
	c1 = optimalBase(book, n, ts);
	ts = 50000;	
	c1 = optimalBase(book, n, ts);
	ts = 500000;	
	c1 = optimalBase(book, n, ts); 

}

int isPrime(int n) {
	int i = 2, flag = 0;
	while( i < n) {
		if( n % i == 0) {
			flag = 1;
			break;
		}
		i++;
	}
	if( flag) {
		return 0;
	}
	return 1;
}	

int optimalBase( char** book, int n, long long int ts) {

	int colcount = (int)INFINITY, count = 3;
	int i;
	long long int j, base;
	long long int minrange = ts;
	long long int maxrange = ts*1000;
	for( i = 0; i<6; i++) {
		if( i > 2) {
			ts = maxrange;
		}

		j = ts;
		for(j=ts; j<2*ts; j=j+9) {
			if( !count)
				break;
			if( isPrime(j)) {
				int temp = collisionCount(book, j, ts, n);
				count--;
				if( temp < colcount) {
					base = j;
					colcount = temp;
				}
			}
		}
	}
	printf("Minimum collision count for tablesize %lld is %d for base number %lld\n", minrange, colcount, base);
	return colcount;
}

int min(int a,int b) {
	if(a<b)
		return a;
	else
		return b;
}

/******************************* Exercise 2 **********************************/

Hash createHashTable(int size) {
	Hash ht;
	ht = (Hash) malloc( sizeof( struct hashTable));
	ht->elementCount = 0;
	ht->insertionCost = 0;
	ht->queryingCost = 0;
	ht->slot = (rec *) malloc( sizeof(rec)*size);
	TSIZE = size;
	int i;
	for( i = 0; i<TSIZE; i++) {
		ht->slot[i] = NULL;
	}
	return ht;
}

void printHashTable( Hash hashTable, char ** books) {
	int i, count;
	// COUNT variable only there to make print output look good
	// No other use, can be omitted

	rec temp;
	for( i = 0; i<TSIZE; i++) {
		count = 0;
		temp = hashTable->slot[i];
		while( temp) {
			printf("%s ", books[temp->index]);
			count++;
			temp = temp->next;
		}

		if( count != 0)
			printf("\n");
	}
}

void insert( Hash hashTable, char ** str, int j) {
	int hashValue = hashF(str[j], BASE, TSIZE);

	// printf("%d: %s\n", hashValue, str[j]);
	
	if( hashTable->slot[hashValue] == NULL) {
		rec newRecord = (rec) malloc( sizeof( struct record));
		hashTable->slot[hashValue] = newRecord;
		newRecord->index = j;
		newRecord->count = 1;
		newRecord->next = NULL;
	}
	else {
		int flag = 0;
		rec hashSlot = hashTable->slot[hashValue];
		while( hashSlot->next != NULL) {
			if( !strcmp(str[hashSlot->index], str[j])) {
				flag = 1;
				hashSlot->count++;
				break;
			}
			hashSlot = hashSlot->next;
			hashTable->insertionCost++;
		}
		if( !flag) {
			if( !strcmp(str[hashSlot->index], str[j])) {
				flag = 1;
				hashSlot->count++;
			}
			else
			{
				rec newSlot = (rec) malloc( sizeof( struct record));
				hashSlot->next = newSlot;
				newSlot->index = j;
				newSlot->count = 1;
				newSlot->next = NULL;
			}
		}
	}

	hashTable->elementCount++;
	
}

int insertAll(Hash hashtable, char ** books, int size) {
	int i;
	for( i = 0; i<size; i++) {
		insert(hashtable, books, i);
	}
	return hashtable->insertionCost;
}

rec lookup(Hash hashTable, char ** books, char * str) {
	int hashvalue = hashF(str, BASE, TSIZE);
	rec temp = hashTable->slot[hashvalue];

	if( temp == NULL) {
		return NULL;
	}
	else {
		while(temp != NULL) {
			if( !strcmp(str, books[temp->index])) {
				return temp;
			}
			else {
				temp = temp->next;
				hashTable->queryingCost++;
			}
		}
	}

	return temp;
}

int lookupAll( Hash hashTable, char ** books, float m) {
	float querySize = m*100;
	int i;
	hashTable->queryingCost = 0;

	for(i=0; i<querySize; i++) {
		lookup(hashTable, books, books[i]);
	}

	return hashTable->queryingCost;
}

/****************************** Exercise 3 *************************************/

void deleteWord(Hash hashTable, char ** books, char * word) {
	int hashValue = hashF(word, BASE, TSIZE);
	rec temp =  hashTable->slot[hashValue];
	rec prev;

	if( temp == NULL) {
		return;
	}
	else {
		if( !strcmp(books[temp->index], word)) {
			hashTable->slot[hashValue] = temp->next;
			free(temp);
			return;
		}

		prev = temp;
		temp = temp->next;

		while( temp) {
			if( !strcmp(books[temp->index], word)) {
				prev->next = temp->next;
				free(temp);
			}
			else {
				prev = temp;
				temp = temp->next;
			}
		}
	}
}

void htProfiling(Hash hashTable, char ** books) {
	float i = 0.1;
	int queryC;

	while( i<=2) {
		queryC = lookupAll(hashTable, books, i);
		if( hashTable->queryingCost > hashTable->insertionCost) {
			printf("Querying cost overtakes insertion cost at %f percent\n", i*100);
			return;
		}
		else {
			i = i + 0.1;
		}
	}
}

void cleanup(Hash hashTable, char ** books, char * filename) {

	FILE * fp = NULL; 
	fp = fopen(filename, "r");

	if( fp == NULL) {
		printf("Error! in opening file\n");
		return;
	}

	char word[50];

	while( !feof(fp)) {
		fscanf(fp, "%s", word);
		deleteWord(hashTable, books, word);
	}

	htProfiling(hashTable, books);
}
