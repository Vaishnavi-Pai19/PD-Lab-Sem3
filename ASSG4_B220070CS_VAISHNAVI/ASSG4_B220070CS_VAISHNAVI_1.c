//Vaishnavi B220070CS: Assignment 4, Question 1

#include <stdio.h>

void insertion_sort (float bucket[], int num)       //Standard algorithm of insertion sort for sorting elements in a bucket
{
    for (int i=1; i<num; i++)
    {
        float key = bucket[i];
        int j=i-1;

        while ((j>=0) && (bucket[j]>key))
        {
            bucket[j+1]=bucket[j];
            j--;
        }
        bucket[j+1]=key;
    }
}

void bucket_sort (float array[], int array_size)
{   
    //Creating a 2D array where each column connotates represents a single bucket
    //Row size is 10 as there are only 10 integers possible from 0-9, column size is the array size since max no. of elements in a single bucket is the array size itself
    float buckets[10][array_size];  

    //Creating an array to keep track of elements stored in each bucket; each element of this array corresponds to a particular bucket out of the total 10
    float count_size_bucket[10]={0};

    for (int i=0; i<array_size; i++)                          //Distributing elements into buckets
    {
        int bucket_index;
        bucket_index = (int)(10 * array[i]);                    //Multiplying by 10 and type-casting to int to convert each floating number to an integer between 0 and 9

        int row_ind = bucket_index;
        int column_ind = count_size_bucket[row_ind];

        buckets[row_ind][column_ind++] = array[i];             //Putting the array element into the correct row and column in the 2D array, ie into the correct bucket and position
        count_size_bucket[row_ind] = column_ind;               //Updating the count of bucket size
    }
    
    int total_index=0;
    for (int i=0; i<10; i++)
    {
        if (count_size_bucket[i]>0)                     //Checking if a bucket has more than 1 element and then sorting it using insertion sort
        {
            insertion_sort (buckets[i], count_size_bucket[i]);
            for (int j=0; j<count_size_bucket[i]; j++)
            {
                array[total_index++]=buckets[i][j];
            }
        }
    }                               
}

void print_sorted_array (float array[], int num)
{
    for (int i=0; i<(num-1); i++)
    {
        printf ("%.2f ", array[i]);          //Using %.2f for 2 decimal point precision
    }
    printf ("%.2f", array[num-1]);           //Printing last element separately to ensure there's no extra space after it
}

int main ()
{
    int num_of_elements;
    scanf ("%d", &num_of_elements);

    float Array[num_of_elements];
    for (int p=0; p<num_of_elements; p++)
    {
        scanf ("%f", &Array[p]);
    }

    bucket_sort (Array, num_of_elements);
    print_sorted_array (Array, num_of_elements);
    return 0;
}