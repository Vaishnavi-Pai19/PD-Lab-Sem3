#include <stdio.h>

float power(float a,int i)
{
    if (i==0)
    return 1.0;
    if (i>0)
    return a*power(a,(i-1));
}

int fact(int a) 
{ 
    if(a <= 1) 
    { return 1; } 
    else
    return a * fact(a - 1); 
}

int main ()
{
   float x;
   int n;
   scanf ("%f",&x);
   scanf ("%d",&n);
   x=x*(3.1415/180);
  
   float sine,a,b;
   for (int i=1;i<=n;i+=2)
   {
       a=power(-1,((i-1)/2));
       b=power(x,i);
       sine+=(a*b)/fact(i);
   }
   printf ("%.4f",sine);
}