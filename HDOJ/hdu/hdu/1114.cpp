#include "stdio.h"
#include "string.h"
#define INF 1000000000
int dp[10010];
int p[50010],w[10010];
int min(int a,int b)
{
  return a<b?a:b;
}
int main()
{int i,j;
 int n;
 int e,f,v;
 int t;
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d%d",&e,&f);
  scanf("%d",&n);
  v=f-e;
  for(i=1;i<=n;i++)
         scanf("%d%d",&p[i],&w[i]);
  for(i=0;i<=v;i++)
         dp[i]=INF;
  dp[0]=0;
  for(i=1;i<=n;i++)
         for(j=w[i];j<=v;j++)
            dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
   if(dp[v]==INF)
         printf("This is impossible.\n");
   else
         printf("The minimum amount of money in the piggy-bank is %d.\n",dp[v]);
  }
  return 0;
}

