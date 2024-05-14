//Vaishnavi B220070CS: Assignment 4, Question 2

#include <stdio.h>

int getmaximum (int arr[], int n)
{
   int max=arr[0];
   
   for (int x=0;x<n;x++)
   {
      if (arr[x]>max)
        {  max=arr[x]; }
   }
   return max;
}

int getminimum (int arr[], int n)
{
   int min=arr[0];
   
   for (int x=0;x<n;x++)
   {
      if (arr[x]<min)
        {  min=arr[x]; }
   }
   return min;
}

int countingsortalgo (int arr[], int n, int place_val)
{
    int out[n+1];                                      //Having an array with one more element than the original array
    int count[10] = {0};                               //Initializing all elements to 0 in the beginning
    int min=getminimum (arr, n);

    for (int i=0;i<n;i++)
    {
       count[(arr[i]/place_val)%10]++;                 //Doing modulus by 10 to find out the integer value and incrementing the corresponding index
    }
    
    for (int x=1;x<10;x++)
    {
       count[x]=count[x]+count[x-1];
    }
    
    for (int j=(n-1);j>=0;j--)
    {
       out[count[((arr[j]/place_val)%10)]-1]=arr[j];
       count[((arr[j]/place_val)%10)]--;
    }
       
    for (int k=0;k<n;k++)
    arr[k]=out[k];
    
    return 0;
}
    
void radixsortarray (int unsorted[], int n)        //Basic algorithm for radix sort
{
   int max = getmaximum (unsorted,n);
   int place, num_positions;
   
   for (place=1; (max/place)>0; place*=10)
     countingsortalgo (unsorted, n, place);
}     

void printsortedarray (int sorted[], int n)
{ 
   for (int p=1; p<n; p++)
   {  
       printf ("%d ",sorted[p-1]);
   }
   printf ("%d", sorted[n-1]);                           //Done to print the last element without an extra space after it
}


int main ()
{
   int n;
   scanf ("%d", &n);
   int arr[n];
   for (int i=0;i<n;i++)
   {
      scanf ("%d", &arr[i]);
   }
   
   radixsortarray (arr,n);
   printsortedarray (arr,n);
   return 0;
}
