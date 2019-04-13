#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node* left;
    struct node* right;
    int hb; //height balance
};

typedef struct node* Node;

Node newNode(int val);

Node add(Node root, int val, Node parent);

Node find(Node root, int val);

Node deleteNode(Node root, int val, Node parent);

Node rotate( Node root, Node x, Node y, Node z, Node parent);

int findHeight(Node z);

int max(int a, int b);

Node inorder(Node root, int k);

void rangeSearch(Node root, int k1, int k2);

void printInorder(Node root);