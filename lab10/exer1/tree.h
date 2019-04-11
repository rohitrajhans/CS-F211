#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node* left;
    struct node* right;
    int hb : 2; //height balance
};

typedef struct node* Node;

Node newNode(int val);

Node add(Node root, int val);

Node find(Node root, int val);

Node deleteNode(Node root, int val);