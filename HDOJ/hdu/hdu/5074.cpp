#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m;
int mt[100][100];
int a[110];
int dp[110][55];

int main()
{
  int T_T;
  scanf("%d",&T_T);
  while(T_T--)
    {
      scanf("%d%d",&n,&m);
      for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
          scanf("%d",&mt[i][j]);
      for(int i=1;i<=n;i++)
        scanf("%d",a+i);
      memset(dp,0,sizeof(dp));

      for(int i=2;i<=n;i++)
        {
          if(a[i]>0)
            {
              if(a[i-1]>0)
                dp[i][a[i]]=max(dp[i][a[i]],dp[i-1][a[i-1]]+mt[a[i-1]][a[i]]);
              else
                {
                  for(int j=1;j<=m;j++)
                    dp[i][a[i]]=max(dp[i][a[i]],dp[i-1][j]+mt[j][a[i]]);
                }
            }
          else
            {
              if(a[i-1]>0)
                {
                  for(int j=1;j<=m;j++)
                    dp[i][j]=max(dp[i][j],dp[i-1][a[i-1]]+mt[a[i-1]][j]);
                }
              else
                {
                  for(int j=1;j<=m;j++)
                    for(int k=1;k<=m;k++)
                      dp[i][k]=max(dp[i][k],dp[i-1][j]+mt[j][k]);
                }
            }
        }
      int ans=0;
      for(int i=1;i<=m;i++)
        ans=max(ans,dp[n][i]);
      printf("%d\n",ans);
    }
  return 0;
}


