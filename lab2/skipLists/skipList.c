#include"skipList.h"

void insertFirst(struct skiplist* head, int ele) {
    struct node* newNode = (struct node*) malloc( sizeof(struct node));
    
    newNode->element = ele;
    newNode->next = (head->h1)->first;

    (head->h1)->first = newNode;
    (head->h1)count++;
}
