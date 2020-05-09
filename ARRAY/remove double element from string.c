#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    int a[13]={132,12,2,12,12,2,1,2,2,11,12,6,6};
    int *h;
    int max=a[0],i;
    for(i=1;i<13;i++)
    {
        if(a[i]>max)
           {
               max=a[i];
           }
    }
    h=(int*)malloc(sizeof(int)*(max+1));
    for(i=0;i<=max;i++)
    {
        h[i]= 0;
    }
    for(i=0;i<13;i++)
    {
        h[a[i]]+=1;
    }
    int max1=h[0];
    for(i=1;i<=max;i++)
    {
        if(h[i]>max1)
        {
            max1=h[i];
        }
    }
   for(i=0;i<13;i++)
   {
       if(h[a[i]]==max1)
       {
           printf("%d",a[i]);
           break;
       }
   }
    return 0;
}
