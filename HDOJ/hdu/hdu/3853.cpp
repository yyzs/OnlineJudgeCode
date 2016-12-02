#include "stdio.h"
#include "string.h"
#include "math.h"
#define INF 1e-10
#define MAX 1010
double p[MAX][MAX][3],dp[MAX][MAX];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
          for(int i=0;i<n;i++)
              for(int j=0;j<m;j++)
                  {
                      scanf("%lf%lf%lf",&p[i][j][0],&p[i][j][1],&p[i][j][2]);
                  }
        for(int i=0;i<MAX;i++)
               for(int j=0;j<MAX;j++)
                 dp[i][j]=0;
        for(int i=n-1;i>=0;i--)
                  for(int j=m-1;j>=0;j--)
                  {
                       if(i==n-1&&j==m-1)
                                continue;
                       if(fabs(p[i][j][0]-1.0)<INF)
                                {
                                    dp[i][j]=0;
                                    continue;
                                }
                       dp[i][j]=(dp[i][j+1]*p[i][j][1]+dp[i+1][j]*p[i][j][2]+2.0)/(1.0-p[i][j][0]);
                  }
        printf("%.3f\n",dp[0][0]);
    }
    return 0;
}

