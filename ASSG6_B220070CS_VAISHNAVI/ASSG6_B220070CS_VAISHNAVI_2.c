//Vaishnavi B220070CS: Assignment 6, Question 2

#include <stdio.h>
#include <stdlib.h>

struct array {
    int top;
    int capacity;
    int *arr;
};

typedef struct array* stack;

stack create_stack (int max)       //Function to create a stack and allocate memory to it
{
    stack hello = (stack)malloc(sizeof(struct array));

    if (hello==NULL)
    {
        printf ("-1\n");
        exit (0);
    }

    hello->capacity=max;
    hello->top=-1;
    hello->arr=(int*)malloc (max * sizeof(int));

    if (hello->arr==NULL)
    {
        printf ("-1\n");
        exit (0);
    }

    return hello;
}

int find_greater (stack array, int i, int n)     //Function to find next greater element of any particular element
{   
    if (i==(n-1))
    {
        return -1;
    }
    else 
    {
        int max = array->arr[i];
        int found=0;
        for (int j=(i+1); j<n; j++)
        {
            if ((array->arr[j])>max)
            {
               max=array->arr[j];
               found=1;
               break;
            }
        }
        if (found)
        {  return max;  }
        else 
        {  return -1;  }            //If the given element has no next greater element, -1 is printed
    }
}

void make_great_array (stack array, int len)    //Function to find next greater element is applied to every element of the array, and the resulting array is printed
{
    int brr[len];

    for (int i=0; i<len; i++)
    {
        brr[i] = find_greater (array, i, len);
    }

    for (int x=0; x<(len-1); x++)
    {
        printf ("%d ", brr[x]);
    }
    printf ("%d", brr[len-1]);     //Done to prevent extra space appearing at the end
}

int main ()
{
    int len;
    scanf ("%d", &len);
    stack new_stack = create_stack (len);

    for (int i=0; i<len; i++)
    {
        scanf ("%d", &new_stack->arr[i]);
        new_stack->top++;
    }

    make_great_array (new_stack, len);
    return 0;
    /*printf ("%d\n", hello_stack->top);
    for (int i=0; i<len; i++)
    {
        printf ("%d ", hello_stack->arr[i]);
    }*/
    
}