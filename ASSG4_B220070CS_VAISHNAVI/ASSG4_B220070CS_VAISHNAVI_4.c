//Vaishnavi B220070CS: Assignment 4, Question 4

#include <stdio.h>

void swap_num (int *xptr, int *yptr)
{
    int temp;
    temp=*xptr;
    *xptr=*yptr;
    *yptr=temp;
}

int findminimum (int arr[], int n, int index)
{
    int min; 
    min=arr[index];
    for (int i=index;i<n;i++)
    {
        if (min>arr[i])
        {  min=arr[i];  }
    }
    return min;
}

int findmaximum (int arr[], int n, int index)
{
    int max=arr[index];
    for (int i=index;i<n;i++)
    {
        if (max<arr[i])
        {  max=arr[i];  }
    }
    return max;
}

int sorted_books (int A[], int n, int E)
{
    int count=0;                                          //The variable count keeps track of the amount of energy spent
    for (int i=0; i<(n-1) && count<E; i++)                //Here count<E instead of count<=E since count will get updated once more while in the loop
    {
        if ((i%2)==0)                                     //Even indices have elements going in ascending order
            {
                findminimum (A, n, i);
                int min_index=i;
                for (int j=(i+1); j<n; j++)
                {
                    if (A[j]<A[min_index])
                    {  min_index=j;  }
                }

                if (min_index!=i)
                {
                    swap_num (&A[i],&A[min_index]);
                    count++;                                //Energy is spent only when a swap is done; if the correct element is in the correct place itself, no energy is spent
                }
            }
            else if ((i%2)==1)                              //Odd indices have elements going in descending order
            {
                findmaximum (A, n, i);
                int max_index=i;
                for (int j=(i+1); j<n; j++)
                {
                    if (A[j]>A[max_index])
                    {  max_index=j;  }
                }
                if (max_index!=i)
                {
                    swap_num (&A[i], &A[max_index]);
                    count++;                              //Energy is spent since a swap takes place
                }
            }
        }
    }

void print_books_order (int arr[], int n)
{
    for (int i=0; i<(n-1); i++)
    {
        printf ("%d ",arr[i]);
    }
    printf ("%d",arr[n-1]);
}


int main ()
{
    int num_books, energy;
    scanf ("%d", &num_books);
    int pages[num_books];
    for (int i=0;i<num_books;i++)
    {
        scanf ("%d", &pages[i]);
    }
    scanf ("%d",&energy);

    sorted_books (pages, num_books, energy);
    print_books_order (pages, num_books);
    return 0;
}