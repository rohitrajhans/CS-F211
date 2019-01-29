#include"que.h"

int main() {
    struct Queue* q = newQ();
    printf("Is queue empty: %d\n", isEmptyQ(q));
    struct Element* e1 = newElement(2);
    struct Element* e2 = newElement(3);
    struct Element* e3 = newElement(1);
    q = addQ(q, e1);
    q = addQ(q, e2);
    printf("Is queue empty: %d\n", isEmptyQ(q));
    printQueue(q);
    q = addQ(q, e3);
    printf("Element at head: %d\n", front(q)->value);
    printf("Length of queue is: %d\n", lengthQ(q));
    q = delQ(q);
    printQueue(q);
    return 0;
}

