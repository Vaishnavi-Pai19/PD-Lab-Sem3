//Vaishnavi B220070CS: Assignment 3, Question 1

#include <stdio.h>

int sort_the_items (float sorted_articles[], int num_of_items, int X, int num_of_days, float extra)  
{                                                                                            //Insertion sort algorithm to sort the elements 
    int x=0;
    for (int i=(num_of_items-X);i<num_of_items;i++)                                          //Sorting begins at the start of the new elements placed as the previous elements are sorted
    {
        float key=sorted_articles[i];
        int j=i-1;

        while ((j>=0) && (key<sorted_articles[j]))
        {    
            if (x>=num_of_days)                                                              //Ensuring that the comparisons do not continue after the given number of days
            { break; }
            else
            sorted_articles[j+1]=sorted_articles[j];
            j--;
        }
        sorted_articles[j+1]=key;
        x++;
       }
       return 0;
}

int print_final_order (float sorted_articles[], int num_of_items, int X, int num_of_days)
{    
    for (int i=0;i<(num_of_items-1);i++)
    {
        printf ("%.2f ",sorted_articles[i]);
    }
    printf ("%.2f",sorted_articles[num_of_items-1]);
    return 0;
}

int extra (float extra)
{
    printf ("%f",extra);
    return 0;
}


int main ()
{
    int number, new, D;
    float extra=0.0;
    scanf ("%d",&number);
    float article_arr[number];

    for (int i=0;i<number;i++)
    {
        scanf ("%f",&article_arr[i]);
    }
    
    scanf ("%d",&new);                                                          //The number of new items unwillingly placed at the end
    scanf ("%d",&D);
    extra++;

    sort_the_items (article_arr,number,new,D,extra);
    print_final_order (article_arr,number,new,D);

    return 1;
}