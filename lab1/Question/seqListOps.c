/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
    SeqList sl;
    sl.head = nextfreeloc++;
    sl.size = 0;
    st[sl.head].next = -1;
    return (sl);
}

void printJob (Job j)
{
    printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}

int initialize_elements (JobList ele)
{
    int i,size;
    printf ("No of Jobs: ");
      scanf ("%d",&size);
      for (i=0;i<size;i++)
      {
      printf ("Enter job ID: ");
     // printf("Segmentation fault 1\n");
      scanf ("%d", &ele[i].id);
     // printf("%d\n", ele[i].id);
     // printf("Segmentation fault 2\n");
      printf ("Enter Priority (from 0 - 2): ");
      scanf ("%d", &ele[i].pri);
     // printf("%d\n", ele[i].pri);
      printf ("Execution Time: ");
      scanf ("%d", &ele[i].et);
     // printf("%d\n", ele[i].et);
      printf ("Arrival Time: ");
      scanf ("%d", &ele[i].at);
     // printf("%d\n", ele[i].at);
      }
      return size;
}
SeqList insert(Job j , SeqList sl)
{
    int i;
    int temp;
    temp = nextfreeloc++;
    for( i = sl.head; st[i].next != -1; i = st[i].next) {
        if( compare( j, st[st[i].next].ele) == LESSER)
                break;
    }
    st[temp].next = st[i].next;
    st[i].next = temp;
    st[temp].ele = j;
    sl.size++;
    return sl;
}
  
void insertelements (JobList list , int size, SeqList s[3])
{
    s[0] = createlist();
    s[1] = createlist();
    s[2] = createlist();
    for( int i = 0; i<size; i++) {
        insert( list[i], s[(list[i].pri)] );
    }

}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{
    int index = 0;
    for( int i = 0; i<3; i++) {
        for( int j=s[i].head; st[j].next != -1; j = st[j].next) {
            ele[index] = st[ st[j].next].ele;
            index++;
        }
    }
}

void printlist(SeqList sl)
{
    for( int i = sl.head; st[i].next != -1; i = st[i].next) {
        printJob( st [ st[i].next].ele );
    }

}

void printJobList(JobList list, int size)
{
    for( int i =0; i<size; i++) {
        printJob( list[i] );
    }
}

void sortJobList(JobList list, int size)
{
    SeqList seq[3];
    seq[0] = createlist();
    seq[1] = createlist();
    seq[2] = createlist();
    insertelements (list, size, seq);
   // printlist(seq[0]);   
   // printlist(seq[1]);
   // printlist(seq[2]);
    copy_sorted_ele (seq , list); 
}
