#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "que.h"
#define MAX 50

typedef struct Element* Task;

typedef struct Queue* que;

typedef que* mq;

mq createMQ(int num);

int sizeMQ(mq multiq);

mq addMQ(mq multiq, Task t);

int maxId(mq multiq);

Task nextMQ(mq multiq);

que delNextMQ(mq multiq);

bool isEmptyMQ(mq multiq);

int sizeMQbyPriority(mq multiq, int p);

que getQueuefromMQ( mq multiq, int p);

void printMQ(mq multiq);

int totalMQSize(mq multiq);
