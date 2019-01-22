#include<stdlib.h>
#include"linkedlist.h"

void printToFile( FILE *fp, struct linkedlist* head) {
    if( fp == NULL) {
        printf("Error in opening file\n");
        return;
    }   
    struct node* temp = head->first;
    while(temp != NULL) {
        fprintf(fp, "%d\n", temp->element);
        temp = temp->next;
    }
}

int main( int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "r");

    struct linkedlist* head = (struct linkedlist *)malloc( sizeof( struct linkedlist));

    while(!feof(fp)) {
        int temp;
        fscanf(fp, "%d ", &temp);
        insertFirst(head, temp);
    }

    fclose(fp);
    printList(head);
    deleteFirst(head);
    printList(head);
    search(head, 32);
    search(head, 49);
    search(head, 95);
    struct node *deletedElement;
    deletedElement = delete(head, 32);
    deletedElement = delete(head, 49);
    deletedElement = delete(head, 17);
    deletedElement = delete(head, 95);
    fp = fopen(argv[2], "w");
    printToFile(fp, head);

    return 0;
}
