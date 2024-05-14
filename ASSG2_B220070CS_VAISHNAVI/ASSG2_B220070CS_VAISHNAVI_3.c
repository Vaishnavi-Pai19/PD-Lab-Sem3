//Vaishnavi B220070CS: Assignment 2, Question 3

#include <stdio.h>

int main()
{
    int n, right, left, mid, count=0, peak=-1, mount_arr[100];

    scanf ("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf ("%d",&mount_arr[i]);
    }
    
    left=0;
    right=n-1;
    
    if (mount_arr[left]>mount_arr[left+1])                    //Checking whether first element is the peak
    { peak=mount_arr[left];
    count++; 
    printf ("%d ",peak);
    return 1; }

    else if (mount_arr[right]>mount_arr[right-1])             //Checking whether last element is the peak
    { peak=mount_arr[right];
    count++; 
    printf ("%d ",peak); 
    printf ("%d",count);
    return 1; }

    do 
    {   count++;
        mid=(left+right)/2;

        if ((mount_arr[mid]>mount_arr[mid-1]) && (mount_arr[mid]<mount_arr[mid+1]))           //If middle element is part of the ascending numbers in the array, peak lies to the right
        {   count++;
            left = mid+1; }
        else if ((mount_arr[mid]>=mount_arr[mid-1]) && (mount_arr[mid]>=mount_arr[mid+1]))    //Checking if middle element lies in between the ascending and descending numners ie. if it is the peak
        {
            count++;
            peak=mount_arr[mid];
            break;
        }
        else                                                                                  //If middle element is part of the descending numbers in the array, peak lies to the left
            {   count++;
                right = mid-1;  }
        mid=(left+right)/2;
    } while (left<=right);

    printf ("%d ",peak);
    printf ("%d",count);

    return 1;
}