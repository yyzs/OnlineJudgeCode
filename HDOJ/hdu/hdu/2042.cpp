#include "stdio.h"
int main()
{int a,n,i,m,j;
 while(scanf("%d",&m)==1)
  {for(j=0;j<m;j++)
   {scanf("%d",&a);
    n=3;
    for(i=1;i<=a;i++)
      n=(n-1)*2;
    printf("%d\n",n);
    }
   }
   return 0;
   }
