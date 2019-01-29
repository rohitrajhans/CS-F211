#include"multiQ.h"

mq createMQ(int num)
{
    mq MultiQ;
    MultiQ = (mq)malloc(sizeof(que)*num);
    int i;
    for(i=0;i<num;i++) {
        MultiQ[i] = newQ();
		MultiQ[i]->priority = i;
	}
	return MultiQ;
}

int sizeMQ( mq multiq) {
	return sizeof(multiq)/sizeof(que);
}

mq addMQ( mq multiq, Task t) {
	int  i;
	int size = sizeMQ(multiq);
	for( i=0; i<size; i++) {
		if( t->priority == multiq[i]->priority) {
			addQ( multiq[i], t);
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

int sizeMQbyPriority( mq multiq, priority p) {
	int count = 0;
	int size = sizeMQ(multiq);
	int i;
	for( i=0; i<size; i++) {
		if( multiq[i]->priority == p) {
			count++;
		}
	}
	return count;
}

que getQueuefromMQ( mq multiq, priority p) {
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
		printf("\n");
	}
	return;
}

