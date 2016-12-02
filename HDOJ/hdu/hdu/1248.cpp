#include "stdio.h"
#include "string.h"
int dp[10010];
int w[3]={150,200,350};
int c[3]={150,200,350};
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{int n;
  int ans;
  int i,j;
  int t;
  scanf("%d",&t);
  while(t--)
  {scanf("%d",&n);
     ans=0;
   for(i=0;i<3;i++)
         for(j=w[i];j<=n;j++)
              dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
    printf("%d\n",n-dp[n]);
    }
    return 0;
}

