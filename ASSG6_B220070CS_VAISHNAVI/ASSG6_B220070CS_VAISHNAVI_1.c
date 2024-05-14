//Vaishnavi B220070CS: Assignment 6, Question 1

#include <stdio.h>
#include <stdlib.h>

struct collection {
    int top_index;
    int max;
    char *arr;
};

typedef struct collection* stack;

stack create_stack (int capacity)
{
    stack newstack = (stack)malloc(sizeof(struct collection));

    if (newstack==NULL)
    {
        printf ("-1\n");
        exit(0);
    }

    newstack->max=capacity;
    newstack->top_index=-1;
    newstack->arr=(char*)malloc (capacity * sizeof(char));

    if (newstack->arr==NULL)
    {
        printf ("-1\n");
        exit(0);
    }
    return newstack;
}

int stack_empty (stack check)       //Function to check if stack is empty or not
{
    if (check->top_index>=0)
    {  return 1;  }
    else
    {  return -1;  }
}

int stack_full (stack fullornot)           //Function to check whether stack is full
{
    if (fullornot->top_index==(fullornot->max-1))
    {  return -1;  }
    else
    {  return 1;  }
}

char peek_last (stack see)           //Returns last element of the stack if stack is not empty, if it is empty, prints -1
{
    if (stack_empty(see)==-1)
    {  printf ("-1\n");  }

    else if (stack_empty(see)==1)
    {  
        int top=see->top_index;
        printf ("%c\n", see->arr[top]);
        return see->arr[top];
    }
}

char pop_element (stack vision)         //Function to pop and display the last element of the stack
{
    if (stack_empty(vision)!=-1)
    {
        char val = vision->arr[vision->top_index];
        vision->top_index--;
        printf ("%c\n", val);
    }
    else if (stack_empty(vision)==-1)
    {  printf ("-1\n");  }
}

void push_element (stack help, char x)      //Adds in a element at the end of the stack if it's not full yet
{
    if (stack_full(help)!=-1)
    {
        help->top_index++;
        help->arr[help->top_index]=x;
    }
    else 
    {  printf ("-1\n"); }
}

int main ()
{
    int n;
    scanf ("%d", &n);
    stack acc_stack = create_stack(n);

    char option;
    char val;

    while (1)
    {
        scanf (" %c", &option);

        switch (option)
        {
            case 'i':
            scanf (" %c", &val);
            push_element (acc_stack, val);
            break;

            case 'd':
            pop_element (acc_stack);
            break;

            case 'p':
            peek_last(acc_stack);
            break;

            case 't':
            free (acc_stack->arr);
            free (acc_stack);
            exit (0);
        }
    }
    return 0;
}