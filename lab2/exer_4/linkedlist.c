#include<stdlib.h>
#include"linkedlist.h"

void insertFirst(struct linkedlist* head, int ele) {
    struct node* link = (struct node*) malloc( sizeof(struct node));

    link->element = ele;
    link->next = head->first;

    head->first = link;
    head->count++;
}

struct node* deleteFirst(struct linkedlist* head) {
    struct node* temp = head->first;
    head->first = temp->next;
    free(temp);
    head->count--;
    return NULL;
}

void printList(struct linkedlist* head) {
    struct node* ptr = head->first;
    printf("\n[ ");
    while( ptr != NULL) {
        printf("%d, ", ptr->element);
        ptr = ptr->next;
    }
    printf(" ]\n");
}

int search( struct linkedlist* head, int ele) {
    struct node* temp = head->first;
    while( temp != NULL) {
        if( temp->element == ele) {
            printf("Element %d is found\n", ele);
            return 1;
        }
        temp = temp->next;
    }
    printf("Element %d is not found\n", ele);
    return 0;
}

struct node* delete( struct linkedlist* head, int ele) {
    struct node * temp = head->first;
    if( temp->element == ele) {
        printf("Element %d is deleted\n", ele);
        return deleteFirst(head);   
    }
    while( (temp->next) != NULL) {
        if( (temp->next)->element == ele) {
            printf("Element %d is deleted\n", ele);
            struct node* deletedElement = temp->next;
            temp->next = deletedElement->next;
            head->count--;
            free(deletedElement);
            return NULL;
        }
        temp = temp->next;
    }
    printf("Element %d is not found\n", ele);
    return NULL;
}
