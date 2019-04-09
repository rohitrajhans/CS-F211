#include "driver.h"

void populateData(char * filename, Node root) {
    readData(filename, root);
}

void readData(char *filename, Node root) {
    FILE* fp = NULL;
    fp = fopen(filename, "r");
    if( fp == NULL) {
        printf("File does not exist.\n");
        exit(-1);
    }
    
    int action, size;
    char domain[50];

    while(!feof(fp)) {
        fscanf(fp, "%d", &action);
        if( action == 1) {
            fscanf(fp, "%d\n", &size);
            readDomains(fp, size, root);
        }
        else if (action == 2) {
            fscanf(fp, "%s", domain);
            // searchForDomain(domain);
        }
        else if(action == -1){
            exit(-1);
        }
    }
}

void readDomains(FILE* fp, int size, Node root) {
    int i;
    char domain[50];
    char ip[20], cat;
    for( i=0; i<size; i++) {
        fscanf(fp, "%s", domain);
        fscanf(fp, "%s", ip);
        printf("%s %s\n", domain, ip);
        insertDomain(domain, ip, root);
    }
}