#include "stdio.h"
#include "string.h"
int a[10000];
long long cal(int n)
{long long i,ans;
  if(n==0)
        return 1;
  ans=1;
  for(i=1;i<=n;i++)
        ans=ans*i%2009;
  return ans;
}
int main()
{int i,j,n;
  while(scanf("%d",&n)==1)
  {if(n>=41)
              printf ("0\n");
    else
              printf("%d\n",cal(n));
  }
  return 0;
}

