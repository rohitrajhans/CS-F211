// #include"que.h"
#include"multiQ.h"

void main() {
    mq multiq = createMQ(10);
    printf("%d\n", totalMQSize(multiq));
    Task e1 = newElementwithPriority(2, 3);
    Task e2 = newElementwithPriority(3, 2);
    Task e3 = newElementwithPriority(1, 2);
    multiq = addMQ(multiq, e1);
    multiq = addMQ(multiq, e2);
    multiq = addMQ(multiq, e3);
    printMQ(multiq);
    printf("%d\n", totalMQSize(multiq));
    return;
}