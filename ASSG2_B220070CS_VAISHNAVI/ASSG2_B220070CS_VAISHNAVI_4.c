//Vaishnavi B220070CS: Assignment 2, Question 4

#include <stdio.h>

int count=0;

int rot_search (int rot_arr[], int n, int search)
{
    int min_ind=0;
    int max_ind=n-1;
    int mid_ind;

    do 
    {
        count++;
        mid_ind=(min_ind+max_ind)/2;

        if (rot_arr[mid_ind]==search)
        return mid_ind;                                            //Position of secret number                    
        
        else if (rot_arr[min_ind] <= rot_arr[mid_ind])             //Checking if left half of array is sorted
         
          { if (search>rot_arr[min_ind] && search<rot_arr[mid_ind])
              max_ind = mid_ind-1; 
            else 
              min_ind = mid_ind+1; }
 
        else if (rot_arr[mid_ind] <= rot_arr[max_ind])             //Checking if right half of arrayis sorted
         
          { if (search>rot_arr[mid_ind] && search<rot_arr[max_ind])
              min_ind = mid_ind+1; 
            else 
              max_ind = mid_ind-1; } 
        
    } while (min_ind<=max_ind);
    return -1;
}

int main ()
{
    int n, secret_number, a[1000];
    scanf ("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf ("%d",&a[i]);
    }
    scanf ("%d",&secret_number);

    printf ("%d ",rot_search (a, n, secret_number));
    return 1;
}