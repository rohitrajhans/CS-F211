// #include"que.h"
#include"multiQ.h"
int size;

mq createMQ(int num)
{
    mq MultiQ;
    MultiQ = (mq)malloc(sizeof(que)*num);
	size = num;
    int i;
    for(i=0;i<num;i++) {
        MultiQ[i] = newQ();
		MultiQ[i]->priority = i;
	}
	return MultiQ;
}

int sizeMQ( mq multiq) {
	return size;
}

mq addMQ( mq multiq, Task t) {
	int  i;
	int size = sizeMQ(multiq);
	for( i=0; i<size; i++) {
		if( t->priority == multiq[i]->priority) {
			printf("Task priority: %d\n", t->priority);
			multiq[i] = addQ( multiq[i], t);
			printf("Size of que %d\n", lengthQ(multiq[i]));
			return multiq;
		}
	}
	printf("Task not added as matching priority not found!.\n");
	return multiq;
}

int maxId(mq multiq) {
	que q = multiq[0];
	int max = 0;
	int size = sizeMQ(multiq);	
	int i;
	for( i=0; i<size; i++) {
		if( q->priority < multiq[i]->priority) {
			q = multiq[i];
			max = i;
		}
	}
	return max;
}

Task nextMQ(mq multiq) {
	return front( multiq[ maxId(multiq) ]);
}

que delNextMQ(mq multiq) {
	return delQ( multiq[ maxId(multiq)]);
}

bool isEmptyMQ(mq multiq) {
	int size = sizeMQ(multiq);
	int i;
	for( i = 0; i<size; i++) {
		if( isEmptyQ(multiq[i]) == 0) {
			return false;
		}
	}
	return true;
}

int sizeMQbyPriority( mq multiq, int p) {
	int count = 0;
	int sizeofmq = sizeMQ(multiq);
	int i;
	for( i=0; i<sizeofmq; i++) {
		if( multiq[i]->priority == p) {
			count += lengthQ(multiq[i]);
		}
	}
	return count;
}

que getQueuefromMQ( mq multiq, int p) {
	int size = sizeMQ(multiq);
	int i;
	for(i=0; i<size; i++) {
		if( multiq[i]->priority == p) {
			return multiq[i];
		}
	}
	printf("No queue with priority %d found\n", p);
	return NULL;
}

void printMQ(mq multiq) {
	int size = sizeMQ(multiq);
	int i;
	for(i=0; i<size; i++) {
		printf("Printing queue with priority %d: ", multiq[i]->priority);
		printQueue(multiq[i]);
	}
	return;
}

int totalMQSize(mq multiq) {
	int sizeofmq = sizeMQ(multiq);
	printf("%d\n", lengthQ(multiq[1]));
	int i, count=0;
	for( i=0; i<sizeofmq; i++) {
		count += lengthQ(multiq[i]);
	}
	return count;
}

