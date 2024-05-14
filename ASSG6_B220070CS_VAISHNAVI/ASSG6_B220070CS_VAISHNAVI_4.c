//Vaishnavi B220070CS: Assignment 6, Question 4

#include <stdio.h>
#include <stdlib.h>

struct world {
    int head, tail, size;
    int max;
    int *arr;
};

typedef struct world* queue;

void swap (int *xptr, int *yptr)
{
    int temp=*xptr;
    *xptr=*yptr;
    *yptr=temp;
}

queue crater_queue (int num)
{
    queue new = (queue) malloc(sizeof(struct world));

    if (new==NULL)
    {
        printf ("-1\n");
        exit (0);
    }

    new->head=-1;
    new->tail=-1;
    new->size=0;
    new->max=num;
    new->arr = (int * )malloc(num * sizeof(int));

    return new;
}

int queue_full (queue kitten)     //Function to check if the queue is full
{
    int len=kitten->max;

    if (kitten->size==len)
    {  return -1;  }
    else
    {  return 1;  }
}

int queue_empty (queue puppy)        //Function to check if the queue is empty
{
    if (puppy->size==0)
    {  return -1;  }
    else
    {  return 1;  }
}

void enqueue (queue hello, int val)
{
    if (queue_full(hello)==-1)
    { return; }
    else 
    {
        int len = hello->max;
        hello->tail = (hello->tail + 1) % len;
        hello->arr[hello->tail]=val;
        hello->size++;
    }
}

void dequeue (queue world)
{
    if (queue_empty(world)==-1)
    {  return;  }
    else
    {
        int item = world->arr[world->head];
        int len = world->max;
        world->head = (world->head + 1) % len;
        world->size--;
    }
}

void reverseelements (queue Q, int K)
{
    if (K<=0 || K>Q->max)
    {
        printf ("-1\n");
    }

    queue tempQ = crater_queue (Q->max);

    int i, j;

    for (i=0, j=(K-1); i<j; i++, j--)
        {
            swap (&Q->arr[i], &Q->arr[j]);
        }

    for (int i=0; i<(Q->max-1); i++)
    {
        printf ("%d ", Q->arr[i]);
    }
    printf ("%d", Q->arr[Q->max-1]);
}

int main ()
{
    int num, K;
    scanf ("%d %d", &num, &K);

    queue new = crater_queue (num);
    for (int i=0; i<num; i++)
    {
        scanf ("%d", &new->arr[i]);
    }
    reverseelements (new, K);
    return 0;
}