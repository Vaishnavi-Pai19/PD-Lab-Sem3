#include <stdio.h>
#include <string.h>

int func(int i)
{
    return ((i*(i+1))/2);
}

char freq(char arr[])
{
    int n=strlen(arr),count,max=0;
    char x=arr[0];
    for (int i=0;i<n;i++)
    { 
      count=0;
      for (int j=0;j<n;j++)
      { 
         if (arr[i]==arr[j])
          count++;
      }
      if (count>max)
      {
        max=count;
        x=arr[i];
      }
    }
   
    printf ("%c",x);
}

int main()
{
    int n,m;
    char str[100],fancystr[1000];
    scanf ("%s",str);
    n=strlen(str);
    str[n]='\0';
    int z=0;
    for (int i=0;i<n;i++)
      {  for (int j=func(i);j<func(i+1);j++)
          {
            fancystr[z]=str[i];
            z++;
          }
      }
      fancystr[z]='\0';
      
   freq(fancystr);
}