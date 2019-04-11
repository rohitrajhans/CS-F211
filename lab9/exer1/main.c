#include<stdio.h>
#include"parser.h"
#include"hash.h"

int main() {
	char *filename = "aliceinwonderland.txt";
	char ** books;
	books = parser(filename);
	profiling(books, count);
	return 0;
}