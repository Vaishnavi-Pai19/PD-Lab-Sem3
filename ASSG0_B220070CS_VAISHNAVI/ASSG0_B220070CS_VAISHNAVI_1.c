//Code to merge two linked lists alternatively

#include <stdio.h>
#include <stdlib.h>

struct nodeLL  {
    int data;
    struct nodeLL *next;
};

typedef struct nodeLL *node;

node createnew (int data)
{
    node temp;
    temp = (node)malloc(sizeof(struct nodeLL));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

node insert (int data, node head)
{
    node new = createnew (data);
    node current = head;
   
    if (head == NULL)
    { return new;  }
   
    else
    {
        while (current->next != NULL)
        {  current = current->next;  }
        current->next = new;
        return head;
    }
}

node merge (node head1, node head2)
{
    node current1 = head1;
    node current2 = head2;
    node prev1 = current1->next;
    node prev2 = current2->next;
   
    while (prev2 != NULL)
    {
        prev1 = current1->next;
        prev2 = current2->next;
        current1->next = current2;
        current2->next = prev1;
        current1 = prev1;
        current2 = prev2;
    }
    return head1;
}

int main ()
{
    int n, key;
    scanf ("%d", &n);
    node head1 = NULL;
    for (int i=0; i<n; i++)
    {
        scanf ("%d", &key);
        head1 = insert (key, head1);
    }
   
    node head2 = NULL;
    for (int i=0; i<n; i++)
    {
        scanf ("%d", &key);
        head2 = insert (key, head2);
    }
   
    merge (head1, head2);
    node current = head1;
    while (current != NULL)
    {
        printf ("%d ", current->data);
        current = current->next;
    }
    return 0;
}