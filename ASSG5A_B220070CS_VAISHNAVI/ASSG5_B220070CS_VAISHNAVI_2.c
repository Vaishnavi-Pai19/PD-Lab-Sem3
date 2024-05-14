//Vaishnavi B220070CS:Assignment 5:Question 2

#include <stdio.h>

void swap (int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void max_heapify (int heap[], int len, int i)
{
    int left=(2*i)+1;
    int right=(2*i)+2;
    int largest=i;

    if ((left<len) && (heap[left]>heap[largest]))
       {  largest=left;  }
    
    if ((right<len) && (heap[right]>heap[largest]))
       {  largest=right;  }
    
    if (largest!=i)
    {
        swap(&heap[i], &heap[largest]);  
        max_heapify (heap, len, largest);
    }
}

void build_maxheap (int arr[], int n)
{
    int length=(n/2);
    for (int i=(length-1); i>=0; i--)
    {  max_heapify (arr, n, i);  }
}

void heapsort (int A[], int n)
{
    build_maxheap (A, n);
    for (int i=(n-1); i>0; i--)
    {
        swap (&A[0], &A[i]);
        max_heapify (A, i, 0);
    }

}

void printarray (int arr[], int length)
{
    for (int i=0; i<(length-1); i++)
    {
        printf ("%d ", arr[i]);
    }
    printf ("%d", arr[length-1]);
}

int main ()
{
    int num;
    scanf ("%d", &num);
    int arr[10000];
    for (int i=0; i<num; i++)
    {
        scanf ("%d", &arr[i]);
    }

    heapsort (arr, num);
    printarray (arr, num);
    return 0;
}