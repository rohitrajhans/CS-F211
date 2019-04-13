#include<stdio.h>
#include"parser.h"
#include"hash.h"

int main() {
	char *filename = "aliceinwonderland.txt";
	char ** books;
	books = parser(filename);
	profiling(books, count);

	/****** Testing exercise 2 and exercise 3 *****************/

	Hash hashTable = createHashTable(300);
	insertAll(hashTable, books, count);
	printHashTable(hashTable, books);

	return 0;
}