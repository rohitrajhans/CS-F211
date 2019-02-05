#include"main.h"
#include<time.h>
#define MAX 100000 

int genRandom() {
	int n;
	n = rand() % 100 + 1;
	return n;
}

listptr createList(int n) {
	int i, num;
	listptr head = (listptr)myalloc(sizeof(struct linkedlist));
	head->key = genRandom();
	head->next = NULL;
	listptr temp = head;
	for( i = 1; i<n; i++) {
		num = genRandom();
		temp->next = (listptr)myalloc( sizeof(struct linkedlist));
		temp = temp->next;
		temp->key = num;
		temp->next = NULL;
	}
	return head;
}

listptr createCyclic( listptr ls) {
	srand(time(0));
	int toss = rand()%2;
	printf("0. Cyclic, 1. Linear: %d\n", toss);
	if( toss == 1) {
		return ls;
	}
	else if( !toss) {
		int count = rand()%MAX;
		listptr temp = ls;
		while( count!=0) {
			temp = temp->next;
			count--;
		}
		listptr last = ls;
		while( last->next != NULL) {
			last = last->next;
		}
		last->next = temp;
		return ls;
	}
	return ls;
}

int testCyclic( listptr ls) {
	listptr temp = ls;
	int count = MAX;
	while( count != 0) {
		if( temp->next == NULL)
			return 0;
		temp = temp->next;
		count--;
		continue;
	}
	return 1;
}

int main() {
	listptr ls = createList(MAX);
	FILE* fp = fopen("heapspace.txt", "w");
	if(fp == NULL) {
		printf("Error!\n");
		return -1;
	}
	fprintf(fp, "Total heap spacee: %d\n", allocatedSpace);
	fclose(fp);
	
	ls = createCyclic(ls);
	int test = testCyclic(ls);
	if( test == 1) {
		printf("Cyclic\n");
	}
	else if(!test) {
		printf("Linear\n");
	}
	
	return 0;
}
