#include <stdio.h>
#include <stdlib.h>

struct world {
    int head, tail, size;
    int max;
    int *arr;
};

typedef struct world* queue;

queue create_queue (int num)
{
    queue new = (queue) malloc(sizeof(struct world));

    if (new==NULL)
    {
        exit (0);
    }

    new->head=-1;
    new->tail=-1;
    new->size=0;
    new->max=num;
    new->arr = (int * )malloc(num * sizeof(int));

    return new;
}

int queue_full (queue world)     
{
    int len=world->max;

    if (world->size==len)
    {  return -1;  }
    else
    {  return 1;  }
}

int queue_empty (queue green)        
{
    if (green->size==0)
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

void display (queue see)
{
    if (queue_empty(see) == -1) 
    {
        return;
    }

    int i;
    int len = see->max;
    int count = see->size;
    int index = see->head;

    for (i = 0; i < count; i++) {
        printf("%d ", see->arr[index]);
        index = (index + 1) % len;
    }
    printf("\n");
}

int front (queue check)
{
    if (queue_empty(check) == -1)
    {  return -1;  }
    return check->arr[check->head];
}

int rear (queue lake)
{
    if (queue_empty(lake) == -1)
    {  return -1;  }
    return lake->arr[lake->tail];
}

int main ()
{
    int num, K;
    scanf ("%d %d", &num, &K);

    queue new = create_queue (num);
    for (int i=0; i<num; i++)
    {
        scanf ("%d", &new->arr[i]);
    }
    
    return 0;
}