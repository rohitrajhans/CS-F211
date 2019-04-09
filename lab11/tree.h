#ifndef _tree
#define _tree
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Create a tree structure to maintain the nodes
// Each node stores a left child and a right sibling

typedef struct node* Node;

struct node {
    char * key;
    Node child;
    Node sibling;
};

Node newNode(char *key);

void insert(Node n, Node root);
// Inserts a node in the tree
// eg. 'com' corresponding to "google.'com'"

void insertDomain(char * domain, char * ip, Node root);
// Inserts a domain eg. 
// google.co.in 192.168.1.2

Node findkey(char * value, Node root);
// returns the Node that matches "value"

Node findKeyInChild(char *name, Node root);

void printTree(Node root);
// Traverses the tree and prints domain name and IP

void traverseTree(Node root);

void lookup(char * name, Node root);
// search for "name" in the tree
// Print its IP, if entry is present.
// Otherwise print the child number at each __
// __ level of three (except root)

char* strrev( char *str);

#endif