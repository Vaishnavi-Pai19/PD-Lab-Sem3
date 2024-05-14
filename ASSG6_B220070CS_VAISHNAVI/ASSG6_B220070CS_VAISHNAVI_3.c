//Vaishnavi B220070CS: Assignment 6, Question 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fusion {
    int head;
    int tail;
    int max;
    char arr[10000][21];         //2D array to store strings; column length=21 since string's max length is 20
}; 

typedef struct fusion* queue;

queue crete_queue (int num)      //Function to create a queue and allocate memory to it
{
    queue q = (queue) malloc (sizeof(struct fusion));

    if (q==NULL)
    {
        printf ("-1\n");
        exit (0);
    }

    q->max=num;
    q->head=-1;
    q->tail=-1;
    
    return q;
}

int full_queue (queue hebe)       //Function that returns -1 if queue is full and 1 if it's not full yet
{
    int front=hebe->head;
    int rear=hebe->tail;
    int len=hebe->max;

    if ((rear+1)%len==front)
    {  return -1;  }
    else 
    {  return 1;  }
}

int empty_queue (queue jeebie)       //Function that returns -1 if queue is empty and 1 if it has elements
{
    if (jeebie->head==-1)
    {  return -1;  }
    else 
    {  return 1;  }
}

void enqueue (queue Q, char* string)     
{
    if (full_queue(Q)==-1)        //If queue is full, nothing further can be added
    {
        printf ("-1\n");
    }
    else
    {
        if (empty_queue(Q)==-1)     //If queue is empty, both head and tail need to be incrememted before adding a string to the array
        {
            Q->head=0;
            Q->tail=0;
        }
        else if (empty_queue(Q)==1)      //If queue is not empty, only tail needs to be incremented
        {
            Q->tail=(Q->tail+1)%Q->max;
        }
        strcpy (Q->arr[Q->tail], string);
    }
}

void dequeue (queue Q)
{
    if (empty_queue(Q)==-1)         //If queue is empty, no element can be removed from it
    {
        printf ("-1\n");
    }
    else
    {
        printf ("%s\n", Q->arr[Q->head]);

        if (Q->head==Q->tail)
        {
            Q->head=Q->tail=-1;
        }
        else 
        {
            Q->head = (Q->head+1)%Q->max;      //Head needs to be incremented after an element is removed from the queue
        }
    }
}

int main ()
{
    int len;
    scanf ("%d", &len);
    queue line = crete_queue (len);

    char choice;
    char str[21];

    while (1)
    {
        scanf (" %c", &choice);
        switch (choice)
        {
            case 'i':
               scanf ("%s", str);
               enqueue (line, str);
               break;
            
            case 'd':
               dequeue (line);
               break;

            case 'f':
               int hush = full_queue (line);
               printf ("%d\n", hush);
               break;

            case 'e':
               int check = empty_queue (line);
               printf ("%d\n", check);
               break;

            case 't':
               free (line);
               exit(0);
        }
    }
    return 0;
}

