#include "stdio.h"
#include "string.h"
int dp[100010];
int w[100010],c[100010];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{int n,a,b;
 int i,j;
 int m;
 while(scanf("%d",&n)==1)
 {for(i=0;i<n;i++)
            scanf("%d%d",&c[i],&w[i]);
  memset(dp,0,sizeof(dp));
  scanf("%d",&m);
  for(i=0;i<n;i++)
        for(j=w[i];j<=m;j++)
              dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
  printf("%d\n",dp[m]);
  }
  return 0;
}



