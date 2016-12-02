#include "stdio.h"
int main()
{int t,n,sum=0;
 int i,j;
 scanf("%d",&t);
 while(t--)
 {sum=0;
  scanf("%d",&n);
  n%=10000;
  for(i=1;i<=n;i++)
     sum=(sum+n)%10000;
  printf("%d\n",sum);
  }
  return 0;
  }

