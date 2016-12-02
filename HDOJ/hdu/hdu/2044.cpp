#include "stdio.h"
int main()
{long long c[51];
 int a,b,n;
 int i,j;
 scanf("%d",&n);
 for(j=0;j<n;j++)
    {
     scanf("%d%d",&a,&b);
     for(i=0;i<51;i++)
        c[i]=0;
     c[a+1]=1; 
     c[a+2]=2;
     for(i=a+3;i<=51;i++)
         c[i]=c[i-1]+c[i-2];
     printf("%I64d\n",c[b]);
    }
  return 0;
}
