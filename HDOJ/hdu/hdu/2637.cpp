#include "stdio.h"
#include "stdio.h"
int main()
{long long n,a,b;
 long long sum;
 long long t;
 long long i;
 scanf("%I64d",&t);
 while(t--)
 {scanf("%I64d%I64d%I64d",&n,&a,&b);
  sum=a;
  for(i=0;i<n;i++)
      sum=sum*(b-i);
  printf("%I64d\n",sum);
  }
  return 0;
}

