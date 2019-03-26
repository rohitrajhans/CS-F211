#include<stdio.h>
#include"parser.h"
#include"hash.h"

int main() {
	char *filename = "aliceinwonderland.txt";
	char ** books;
	books = parser(filename);
	profiling(books, 12863);
	// collisionCount(books, 8527, 5000, 12863);
	return 0;
}