#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

void populateData(char * filename, Node root);

void readData(char * filename, Node root);

void readDomains(FILE* fp, int size, Node root);