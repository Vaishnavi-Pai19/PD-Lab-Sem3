//Vaishnavi B220070CS: Assignment 3, Question 3

#include <stdio.h>

int sortingrunes (int rune_potency[], int number)
{
    int find_max;
    for (int i=0;i<(number-1);i++)
    {
        find_max=rune_potency[i];                                   //Finding the maximum element in the unsorted array each iteration
        int j=i+1;

        while (j<number)
        {
            if (rune_potency[j]>find_max)
            { int temporary;
            
              temporary=rune_potency[i];
              rune_potency[i]=rune_potency[j];                       //Swapping elements of the array using a temporary variable
              rune_potency[j]=temporary; 
              
              find_max=rune_potency[i]; }
            j++;
        }
    }
    
    for (int i=0;i<(number-1);i++)
    {
        printf ("%d ",rune_potency[i]);
    }
    printf ("%d",rune_potency[number-1]);                            //Done to avoid an extra space at the end of output
    return 0;
}



int main ()
{
    int num_of_runes, rune_potency[1000], literal;
    scanf ("%d", &num_of_runes);
    for (int p=0;p<num_of_runes;p++)
    {
        scanf ("%d",&rune_potency[p]);
    }

    sortingrunes (rune_potency, num_of_runes);
    return 1;
}