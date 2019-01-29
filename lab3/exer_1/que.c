#include"que.h"

struct Queue* newQ() {
    struct Queue* newQ = (struct Queue*) malloc (sizeof(struct Queue));
    newQ->head = NULL;
    newQ->tail = NULL;
    return newQ;
}

bool isEmptyQ(struct Queue* q) {
    if( q->head == NULL) {
        return true;
    }
    return false;
}

struct Queue* delQ(struct Queue* q) {
    struct Element * temp = q->head;
    q->head = (q->head)->next;
    printf("Element %d is deleted.\n", temp->value);
    free(temp);
    return q;
}

struct Element* front(struct Queue* q) {
    return (q->head);
}

struct Queue* addQ(struct Queue* q, struct Element* e) {
    if( q->head == NULL) {
        q->head = e;
        q->tail = e;
	printf("Element %d added.\n", e->value);
        return q;
    }
    (q->tail)->next = e;
    q->tail = e;
    return q;
}

int lengthQ(struct Queue* q) {
    struct Queue* temp = q;
    int size = 0;
    if( temp->head == NULL) {
        return 0;
    }
    while( temp->head != temp->tail) {
        printf("Value at temp head: %d\n", (temp->head)->value); 
        size++;
        temp->head = (temp->head)->next;
    }
    return size++;
}

struct Element* newElement(int i) {
    struct Element* e = (struct Element*) malloc(sizeof(struct Element));
    e->value = i;
    e->next = NULL;
    return e;
}

void printQueue(struct Queue* q) {
    if( q->head == NULL) {
        printf("Queue is empty\n");
        return;
    }
    while(q->head != q->tail) {
        printf("%d, ", (q->head)->value);
        q->head = (q->head)->next;
    }
    printf("%d\n", (q->head)->value);
    return;
}
