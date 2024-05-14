//Vaishnavi B220070CS: Assignment 4, Question 3

#include <stdio.h>

void swap (char *xptr, char *yptr)           //Swapping using pointers
{
    int not_req;
    not_req=*xptr;
    *xptr=*yptr;
    *yptr=not_req;
} 

int partition (char A[], int first, int last)
{
    int pivot=A[last];                       //Taking last element as pivot and placing it in the correct position 
    int i=(first-1);

    for (int j=first; j<=(last-1); j++)
    {
        if (A[j]<pivot)
        {
            i++;
            swap (&A[i], &A[j]);
        }
    }
    swap (&A[i+1], &A[last]);
    return (i+1);
}

void quick_sort (char arr[], int first, int last)       //The basic algorithm for quick sort
{
    if (first<last)
    {
        int pivot = partition(arr, first, last);

        quick_sort (arr, pivot+1, last);                
        quick_sort (arr, first, pivot-1);
    }
}

void printarray (char arr[], int n)
{
    for (int i=(n-1); i>0; i--)
    {
        printf ("%c ",arr[i]);
    }
    printf ("%c",arr[0]);
}

int main ()
{
    int num;
    scanf ("%d",&num);
    char arr[num];
    for (int i=0; i<num; i++)
    {
        scanf (" %c", &arr[i]);
    }

    quick_sort (arr, 0, num-1);            //At the beginning, first and last indices are 0 and n-1 respectively
    printarray (arr, num);
    return 0;
}