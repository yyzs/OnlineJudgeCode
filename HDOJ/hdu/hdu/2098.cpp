#include "stdio.h"
int prime(int i)
{int j,ok=1;
 if(i==2)
     return 1;
 else
    {for(j=2;j*j<=i;j++)
        if(i%j==0)
          {ok=0;
           break;
           }
      if(ok)
         return 1;
      else
         return 0;
     }
}
int main()
{int i,sum,n;
 while(scanf("%d",&n)&&n)
  {sum=0;
   for(i=2;i<=n/2;i++)
     if(prime(i)&&prime(n-i)&&i!=n-i)
        sum++;
     printf("%d\n",sum);
    }
  return 0;
  }

