#include<stdio.h>

struct node {
    int ele;
    struct node *next;
};

struct linkedlist {
    struct node*first;
};

struct expresslistnode {
    int ele;
    struct expresslistnode* next;
    struct node* link;
}

struct expresslist {
    struct expresslistnode *first;
};

struct skiplist {
    struct expresslist* h2;
    struct linkedlist* h1;
};

void insertFirst( struct skiplist* head, int ele);
struct node* delete( struct skiplist* head, int ele);
struct node* search( struct skiplist* head, int ele);
void initializeExpressList( struct skiplist* head);
