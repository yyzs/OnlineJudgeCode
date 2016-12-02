#include "stdio.h"
int main()
{long long n,sum,m;
 while(scanf("%I64d",&n)==1)
 {sum=1;
  n%=10000;
  m=(n+1)%10000;
  sum=(n%10000)*(n+1)/2%10000;
  sum=sum*sum%10000;
  printf("%04I64d\n",sum);
 }
 return 0;
}

