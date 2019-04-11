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
	return ht;
}
