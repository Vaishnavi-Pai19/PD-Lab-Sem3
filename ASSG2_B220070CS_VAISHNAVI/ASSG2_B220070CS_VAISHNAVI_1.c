//Vaishnavi B220070CS: Assignment 2, Question 1

#include <stdio.h>

//Function to find missing k'th element using binary search
int bin_search_miss (int arr[], int n, int k_miss)
{
    int first=0;
    int last=(n-1);

    while (first<=last)
    {
        int mid=(first + last)/2;
        int num_of_missing = arr[mid]-mid-1; 

        if (num_of_missing < k_miss)
        { first = mid+1; }
        else 
        { last = mid-1; }

    }
    return first + k_miss;
}

int bin_search_miss2 (int arr[], int n, int k_miss)
{
    int first=0;
    int last=(n-1);
    int num_of_missing=0;

    while (first<=last)
    {
        int mid=(first + last)/2;
        num_of_missing = arr[mid]-mid-arr[0]; 

        if (num_of_missing < k_miss)
        { first = mid+1; }
        else 
        { last = mid-1; }

    }
    return first+k_miss+arr[0]-1;
}

int main ()
{
    int n, A[1000], k_miss, B[100], low, high, mid, extra;
    
    scanf ("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf ("%d",&A[i]);
    }
    scanf ("%d", &k_miss);

    //Checking if the k'th missing element exists out of the range of the array
    if (k_miss > A[n-1]-n)                   
      { printf ("-1");
        return 1; }  
    
    //Case 1: First element of array is 1
    if (A[0]==1)
    {   
        printf ("%d",bin_search_miss (A, n, k_miss));                             
    }
    
    //Case 2: Array does not start with first element as 1 ie. there are missing elements before the start of the array
    if (A[0]>1)                              
    {   
        int i;
        for (i=1;i<A[0];i++)
        { B[i-1]=i; }
               
        if (k_miss<A[0])                                       //Missing element exists before the start of array
        printf ("%d", B[k_miss-1]);

        else if (k_miss>=A[0])                                 //Missing element lies within the array
        {
          int extra=k_miss-A[0]+1;
          int start_value=A[0];                           //No. of missing elements in the array=Total missing-Missing outside the array
          printf ("%d", (bin_search_miss2 (A, n, extra)));
        }
    }
    
    return 1;
}