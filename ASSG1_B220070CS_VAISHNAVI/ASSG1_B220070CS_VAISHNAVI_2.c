#include <stdio.h>

void main()
{
    int i=1,n;
    scanf ("%d",&n);
    label: printf ("%d ",i);
    i++;
    if (i<n)
    goto label;
    printf ("%d",n);

}