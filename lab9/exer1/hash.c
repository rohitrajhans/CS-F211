#include"hash.h"

int hashF(char* string, int base, int ts) {
	int sum = 0, i, hashValue;
	for(i=0; i<strlen(string); i++) {
		sum += string[i];
	}
	hashValue = (sum % base) % ts;
	return hashValue;
}

int collisionCount(char** stringArr, int base, int ts, int n) {
	int arr[ts], i, hashValue, col=0;
	for( i=0; i<ts; i++) {
		arr[i] = 0;
	}
	for( i=0; i<n; i++) {
		hashValue = hashF(stringArr[i], base, ts);
		arr[hashValue]++;
		// printf("%d: %d\n", arr[hashValue], hashValue);
		if( arr[hashValue] > 1)
			col++;
	}

	printf("Total number of collisions are: %d\n", col);
	return col;
}

void profiling( char** book, int n) {
	int base, ts;

	ts = 5000;
	base = optimalBase(book, ts, 7841, 9661, 8527, 6001829, 5770291, 6799159, n);
	printf("When tableSize = %d, baseNumber = %d gives minimal collisions\n", ts, base);

	return;
}

int optimalBase( char** book, int ts, int p1, int p2, int p3, int p4, int p5, int p6, int n) {
	int test[3], col;
	test[1] = ts;
	test[0] = p1;

	test[2] = collisionCount(book, p1, ts, n);
	
	col = collisionCount(book, p2, ts, n);
	if( test[2] > col ) {
		test[0] = p2;
		test[2] = col;
	}
	col = collisionCount(book, p3, ts, n);
	if( test[2] > col ) {
		test[0] = p3;
		test[2] = col;
	}
	col = collisionCount(book, p4, ts, n);
	if( test[2] > col ) {
		test[0] = p4;
		test[2] = col;
	}
	col = collisionCount(book, p5, ts, n);
	if( test[2] > col ) {
		test[0] = p5;
		test[2] = col;
	}
	col = collisionCount(book, p6, ts, n);
	if( test[2] > col ) {
		test[0] = p6;
		test[2] = col;
	}

	return test[0];
}