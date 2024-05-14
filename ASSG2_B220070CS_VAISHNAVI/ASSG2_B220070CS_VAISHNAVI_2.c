//Vaishnavi B220070CS: Assignment 2, Question 2

#include <stdio.h>

int main ()
{
    int N, M, session[1000], session_minutes=0, no_of_days, least_min, max_min;

    scanf ("%d %d",&N,&M);
    for (int i=0;i<M;i++)
    {
        scanf ("%d",&session[i]);
    }

    least_min=session[0];                       
    max_min=0;

    for (int i=0;i<M;i++)
    {
        if (session[i]>least_min)
        least_min=session[i];                       //Least maximum time in a day will be the longest session in the array
        
        max_min+=session[i];                        //Maximum possible time on a day will the total sum of all sessions     
                                                    //ie. when all the sessions are completed on a single day
    }
    
    no_of_days=1;

    int count=0;
    label: for (int i=0;i<M;i++)
    {   
        if (session_minutes+session[i] <= least_min)      //Starting from the first session, checking how many can be done in a day
        { session_minutes += session[i]; 
        count=session_minutes ; }

        else if (session_minutes+session[i]>least_min)    //If the total time exceeds the max. time, it will go on to the next day
        {   count=session[i];
            no_of_days++;
            session_minutes = session[i];  }
    } 

    while (no_of_days > N)
    {  no_of_days=1;
       session_minutes=0;
       least_min++;
       goto label;  }
    
    if (no_of_days<=N)
    {  printf ("%d", count+1); }
    
    return 1;
}
