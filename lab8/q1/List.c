#include "List.h"

List createList(Student studArray, int arraySize) {
	List ls = (List) myalloc( sizeof( struct list));

	ls->count = 0;
	ls->first = null;
	ls->last = null;

	int i;

	if(arraySize == 0)
		return ls;

	Node temp;
	temp = (Node) myalloc(sizeof(struct node));
	temp->record = &studArray[0];
	temp->next = null;

	ls->first = temp;
	ls->last = temp;
	ls->count++;

	for( i = 1; i<arraySize; i++) {
		temp = (Node) myalloc(sizeof(struct node));
		temp->record = &studArray[i];
		temp->next = null;

		(ls->last)->next = temp;
		ls->last = temp;
		ls->count++;
	}

	return ls;
}

void insertInOrder(List list, Node newNode) {

	Node newNode_add = (Node) myalloc(sizeof(struct node));
	newNode_add->record = (Student) myalloc(sizeof(struct student));
	newNode_add->record->name = (char *) myalloc(sizeof(char)*50);
	newNode_add->record->marks = newNode->record->marks;
	strcpy(newNode_add->record->name, newNode->record->name);

	if( !list->count) {
		list->first = newNode_add;
		list->last = newNode_add;
		newNode_add->next = null;
		list->count++;
		return;
	}

	if( (newNode_add->record->marks) < (list->first->record->marks)) {
		newNode_add->next = list->first;
		list->first = newNode_add;
		list->count++;
		return;
	}

	Node temp_prev, temp;
	temp_prev = list->first;
	temp = list->first->next;

	while( temp) {
		if( newNode_add->record->marks < temp->record->marks) {
			temp_prev->next = newNode_add;
			newNode_add->next = temp;
			list->count++;
			return;
		}
		temp_prev = temp;
		temp = temp->next;
	}

	(list->last)->next = newNode_add;
	newNode_add->next = null;
	list->last = newNode_add;
	list->count++;

	return;
}

List insertionSort(List list) {
	List sorted_list = (List) myalloc(sizeof(struct list));
	sorted_list->count = 0;
	sorted_list->first = null;
	sorted_list->last = null;

	Node temp = list->first;

	int count = 0;
	while( temp) {
		insertInOrder(sorted_list, temp);
		temp = temp->next;
	}

	return sorted_list;
}

double measureSortingTime(List list) {
	clock_t start, end;
	double cpu_time_used;

	start = clock();
	insertionSort(list);
	end = clock();

	cpu_time_used = (double) (end - start);
	cpu_time_used = cpu_time_used / CLOCKS_PER_SEC * 100;

	return cpu_time_used;
}

void * myalloc(int size) {
	void * ptr = malloc(size + 4);
	globalCounter += size;
	int * pad;
	pad = (int *)ptr;
	pad[0] = size;
	return ptr+4;
}

void myfree( void * ptr) {
	if(  ptr == NULL) {
		return;
	}
	int* pad;
	pad = (int *)(ptr - 4);
	globalCounter -= pad[0];
	free(ptr);
	return;
}