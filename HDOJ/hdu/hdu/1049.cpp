#include "stdio.h"
int main()
{int n,u,d;
 int sum;
 int v,t;
 while(scanf("%d%d%d",&n,&u,&d)==3)
 {if(n==0&&u==0&&d==0)
         break;
  sum=0;
  t=0;
  v=u-d;
  while(n-sum>u)
  {sum+=v;
   t+=2;
   }
   printf("%d\n",t+1);
   }
   return 0;
   }

