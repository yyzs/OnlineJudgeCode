#include "stdio.h"
int main()
{int sum=0,m,k;
 while(1)
 {scanf("%d%d",&m,&k);
  sum=0;
  if(m==0&&k==0)
     break;
  while(m>=k)
  {m+=1;
   sum+=k;
   m-=k;
   }
   sum+=m;
   printf("%d\n",sum);
  }
  return 0;
  }

