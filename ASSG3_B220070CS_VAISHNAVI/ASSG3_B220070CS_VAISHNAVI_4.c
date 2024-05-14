//Vaishnavi B220070CS: Assignment 3, Question 4

#include <stdio.h>

int sorted_sales_figures (int figures[], int products, int extra)
{
    for (int i=1;i<products;i++)
    {
        int find=figures[i];
        int j=i-1;

        while(j>=0 && figures[j]<find)                                       //Sorting the array in descending order
        {
            figures[j+1]=figures[j];
            j=j-1;
        }
        figures[j+1]=find;
    }
}

int print_highest_sales (int figures[], int analyse)
{
    int i=0;
    while (i<(analyse-1))                                                  //Printing only the highest elements required
    {
        printf ("%d ", figures[i]); 
        i++;
    }
    printf ("%d",figures[analyse-1]);
}

int main ()
{
    int N,K,count=0;
    scanf ("%d %d",&N,&K);
    int Arr[N];
    for (int i=0;i<N;i++)
    {
        scanf ("%d",&Arr[i]);
    }
    sorted_sales_figures (Arr,N,count);
    print_highest_sales (Arr,K);
    return 1;
}