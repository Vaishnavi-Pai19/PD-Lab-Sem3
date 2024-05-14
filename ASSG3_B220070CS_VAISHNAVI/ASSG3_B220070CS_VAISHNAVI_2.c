//Vaishnavi B220070CS: Assignment 3, Question 2

#include <stdio.h>

int arrangethebooks (int isbn[], int num)                            //General algorithm for insertion sort
{
    for (int y=1;y<num;y++)
    {
        int particular, z;
        particular = isbn[y];
        z=y-1;
        while ((z>=0) && (isbn[z]>particular))                      //Comparing to elements before until the start of the array
        {
            isbn[z+1]=isbn[z];
            z--;
        }
        isbn[z+1]=particular;
    }
    return 0;
}


int printlastelement (int isbn[], int num)
{
    printf ("%d",isbn[num-1]);
}

int printorder (int isbn[], int num)
{
    for (int x=0;x<(num-1);x++)
    {
       printf ("%d ",isbn[x]); 
    }
    printlastelement (isbn,num);                                   //Done to avoid an extra space at the end
    return 0;
}

int main()
{
    int num_of_books;
    scanf ("%d",&num_of_books);                                    //Getting details of input from the user
    int isbn[num_of_books];
    for (int i=0;i<num_of_books;i++)
    {
        scanf ("%d",&isbn[i]);
    }

    arrangethebooks (isbn, num_of_books);
    printorder (isbn, num_of_books);
    return 1;
}