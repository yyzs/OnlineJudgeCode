#include "stdio.h"
int main()
{
    int a[50];
    int n,i,j;
    for(i=0;i<50;i++)
      a[i]=0;
    while(scanf("%d",&n)==1)
     {
         j=49;
         while(n>1)
         {
           a[j]=n%2;
           n=n/2;
           j--;
         }
        printf("%d",n);
        for(i=j+1;i<50;i++)
          printf("%d",a[i]);
        printf("\n");     
     }
    return 0;
}
