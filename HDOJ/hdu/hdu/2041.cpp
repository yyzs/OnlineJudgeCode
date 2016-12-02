#include "stdio.h"
int main()
{int  n,m,j,a[41],k;
 while(scanf("%d",&n)!=EOF)
  {
   for(k=0;k<n;k++)
   {
   a[1]=0;
   a[2]=1;
   a[3]=2;
   for(j=4;j<41;j++)
       a[j]=a[j-1]+a[j-2];
   scanf("%d",&m);
    printf("%d\n",a[m]);
   }
   }
   return 0;
 }

