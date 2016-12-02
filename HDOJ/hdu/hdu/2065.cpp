#include "stdio.h"
#include "math.h"
long long mod(long long a,long long b,long long c)
{long long ans=1;
 a%=c;
 while(b)
 {if(b%2==1)
            ans=ans*a%c;
  b/=2;
  a=a*a%c;
  }
  return ans;
}

int main()
{long long n,i;
  long long ans,t,cas;
  while(scanf("%I64d",&t)==1&&t)
  {  cas=0;
      while(t--)
    {cas++;
      scanf("%I64d",&n);
      ans=(mod(4,n-1,100)+mod(2,n-1,100))%100;
      printf("Case %I64d: %I64d\n",cas,ans);
      }
      printf("\n");
    }
    return 0;
}


