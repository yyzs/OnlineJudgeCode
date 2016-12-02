#include "stdio.h"
int main()
{int t;
 long long a,b;
 scanf("%d",&t);
 while(t--)
 {scanf("%I64d%I64d",&a,&b);
  if(a>=100)
     a%=100;
  if(b>=100)
     b%=100;
  printf("%I64d\n",(a+b)%100);
  }
  return 0;
  }
