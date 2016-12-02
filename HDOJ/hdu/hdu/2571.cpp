#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "stdlib.h"
#define MAX 1010
#define INF 100000000
using namespace std;
int dp[22][MAX];
int a[22][MAX];
int n,m;
void debug()
{
    int i,j;
    for(i=1;i<=n;i++)
    {for(j=1;j<=m;j++)
        printf("%d ",dp[i][j]);
     puts("");
    }
}
int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
              { scanf("%d",&a[i][j]);
                 dp[i][j]=-INF;
                 dp[0][j]=-INF;
              }
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++){
                 if(i==1&&j==1)
                     {dp[i][j]=a[i][j];
                      continue;
                     }
                 int maxtemp=max(dp[i][j-1],dp[i-1][j])+a[i][j];
                 for(k=1;k<j;k++)
                        if(j%k==0)
                               if(dp[i][k]+a[i][j]>maxtemp)
                                   maxtemp=dp[i][k]+a[i][j];
                 dp[i][j]=maxtemp;
            }
        //debug();
        printf("%d\n",dp[n][m]);
    }
    return 0;
}

