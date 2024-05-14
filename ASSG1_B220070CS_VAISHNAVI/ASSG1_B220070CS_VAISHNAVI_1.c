#include <stdio.h>

int main ()
{
    char str[1000],val;
    int n;
    fgets (str,sizeof(str),stdin);
    scanf ("%c",&val);
    if (val>=65&&val<=90)
    val+=32;
    int count=0;
    for (int i=0;str[i]!='\0';i++)
   { if (str[i]==' ')
     continue; 
     else if (str[i]==val||str[i]==(val-32))
     count++; 
     
   }
    printf ("%d",count);
}