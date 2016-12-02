#include "stdio.h"
#include "string.h"
int dp[20];
int main()
{int n;
 int i,t;
 scanf("%d",&t);
 while(t--)
 {scanf("%d",&n);
  memset(dp,0,sizeof(dp));
  dp[1]=1;
  dp[2]=2;
  for(i=3;i<=20;i++)
     dp[i]=dp[i-1]+dp[i-2];
  printf("%d\n",dp[n]);
  }
  return 0;
}

