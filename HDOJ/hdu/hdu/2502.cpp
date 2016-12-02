#include "stdio.h"
#include "string.h"
#include "math.h"
int main()
{int a[22];
 int i,n,t;
 a[1]=1;
 a[2]=3;
 for(i=3;i<=20;i++)
   a[i]=a[i-1]*2+pow(2,i-2);
 scanf("%d",&t);
 while(t--)
    {scanf("%d",&n);
     printf("%d\n",a[n]);
    }
 return 0;
 }

