#include "stdio.h"
#include "string.h"
long long dp[30][30];
int main()
{int i,j;
 int n;
 int t;
 long long ans;
 scanf("%d",&t);
 while(t--)
  {scanf("%d",&n);
  memset(dp,0,sizeof(dp));
  dp[1][1]=1;
  for(i=2;i<=n;i++)
      for(j=1;j<=n;j++)
         dp[i][j]=dp[i-1][j]*j+dp[i-1][j-1];
   ans=0;
   for(i=1;i<=n;i++)
        ans+=dp[n][i];
   printf("%I64d\n",ans);
   }
   return 0;
}

