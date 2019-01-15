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


int inputJobs (JobList list)
{
    int i; int size;

    printf("\n Enter the Number of Jobs :");
    scanf("%d", &size);

    for (i=0;i<size;i++)
    {
        printf ("\nEnter job ID");
        scanf ("%d",&list[i].id);
        printf ("Enter Priority (from 0 - 2)");
        scanf ("%d",&list[i].pri);
        printf ("Execution Time");
        scanf ("%d",&list[i].et);
        printf ("Arrival Time");
        scanf ("%d",&list[i].at);
    }
    return size;
}

void initialize_elements (JobList ele)
{
    int i,size;
    printf ("No of Jobs");
      scanf ("%d",&size);
      for (i=0;i<10;i++)
      {
      printf ("Enter job ID");
      scanf ("%d",ele[i].id);
      printf ("Enter Priority (from 0 - 2)");
      scanf ("%d",ele[i].pri);
      printf ("Execution Time");
      scanf ("%d",ele[i].et);
      printf ("Arrival Time");
      scanf ("%d",ele[i].at);
      }
    i=0;
    ele[0].id=1;
    ele[0].pri=0;
    ele[0].at=1;
    ele[0].et=5;
    ele[1].id=2;
    ele[1].pri=1;
    ele[1].at=9;
    ele[1].et=3;
    ele[2].id=3;
    ele[2].pri=2;
    ele[2].at=11;
    ele[2].et=12;
    ele[3].id=4;
    ele[3].pri=0;
    ele[3].at=4;
    ele[3].et=7;
    ele[4].id=5;
    ele[4].pri=1;
    ele[4].at=8;
    ele[4].et=2;
    ele[5].id=6;
    ele[5].pri=2;
    ele[5].at=12;
    ele[5].et=11;
    ele[6].id=7;
    ele[6].pri=0;
    ele[6].at=3;
    ele[6].et=9;
    ele[7].id=8;
    ele[7].pri=1;
    ele[7].at=7;
    ele[7].et=4;
    ele[8].id=9;
    ele[8].pri=2;
    ele[8].at=13;
    ele[8].et=10;
    ele[9].id=10;
    ele[9].pri=0;
    ele[9].at=2;
    ele[9].et=15;

    ele[0].pri = ele[3].pri = ele[6].pri = PRI_0;
       ele[1].pri = ele[4].pri = ele[7].pri = PRI_1;
       ele[2].pri = ele[5].pri = ele[8].pri = ele[9].pri = PRI_2;
       for (i=0;i<MAX;i++)
       {
       ele[i].id = i+1;
       ele[i].et = i+2;
       ele[i].at = i;
       }
       ele[2].at = 10;
       ele[5].at = 1;
       ele[6].at = 5;
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
    printlist(seq[0]);   
    printlist(seq[1]);
    printlist(seq[2]);
    copy_sorted_ele (seq , list); 
}
