//Vaishnavi B220070CS:Assignment 5:Question 1

#include <stdio.h>

void merge (int unsorted[], int l, int m, int r)
{
    int i, j, k;
    int n1 = (m-l+1);
    int n2 = (r-m);

    int L[n1], R[n2];

    for (i=0; i<n1; i++)
       L[i] = unsorted[l+i];

    for (j=0; j<n2; j++)
       R[j] = unsorted[m+1+j];

    i=0;
    j=0;
    k=l;

    while ((i<n1) && (j<n2))
    {
        if (L[i] <= R[j])
        {
            unsorted[k]=L[i];
            i++;
        }
        else 
        {
            unsorted[k]=R[j];
            j++;
        }
        k++;
    }

    while (i<n1)
    {
        unsorted[k] = L[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        unsorted[k] = R[j];
        j++;
        k++;
    }
}

void mergesort (int sort[], int p, int r)
{
    if (p<r)
    {
        int q=(p+r)/2;
         
        mergesort (sort, p, q);
        mergesort (sort, q+1, r);

        merge (sort, p, q, r);
    }
      
}

void printarray (int arr[], int l, int r)
{
    for (int i=l; i<(r-1); i++)
    {
        printf ("%d ", arr[i]);
    }
    printf ("%d", arr[r-1]);
}

int main ()
{
    int n;
    scanf ("%d", &n);
    int arr[10000];

    for (int i=0; i<n; i++)
    {
        scanf ("%d", &arr[i]);
    }
    
    int l=0;
    int r=n;

    mergesort (arr, l, r-1);
    printarray (arr, 0, n);
    
    return 0;
}