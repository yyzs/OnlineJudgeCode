#include "math.h"
#include "stdio.h"
#include "string.h"
int main()
{long long n;
 long long k,i;
 double sum;
 while(scanf("%I64d",&n)==1&&n)
 {n=1<<((n-1960)/10+2);
  k=1;
  sum=1.0;
  for(i=1;i<=n;i++)
  {
      sum*=2.0;
      if(sum>k)
        {
            k++;
            sum/=k;
        }
  }
  printf("%I64d\n",k);
 }
 return 0;
}

