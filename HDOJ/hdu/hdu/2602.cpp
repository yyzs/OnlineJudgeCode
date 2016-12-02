#include "stdio.h"
#include "string.h"
int value[1010],volume[1010];
int dp[1010];
int max(int a,int b)
{
   return a>b?a:b;
}
int main()
{int t,n,i,j,v;
 scanf("%d",&t);
 while(t--)
 {scanf("%d%d",&n,&v);
  for(i=1;i<=n;i++)
         scanf("%d",&value[i]);
  for(i=1;i<=n;i++)
         scanf("%d",&volume[i]);
  memset(dp,0,sizeof(dp));
  for(i=1;i<=n;i++)
  {
   for(j=v;j>=volume[i];j--)
         dp[j]=max(dp[j],dp[j-volume[i]]+value[i]);
   }
   printf("%d\n",dp[v]);
   }
   return 0;
}


