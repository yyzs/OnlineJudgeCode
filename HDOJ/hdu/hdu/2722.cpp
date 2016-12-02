#include "stdio.h"
#include "string.h"
#define MAX 501
#define INF 100000000
int dp[MAX][MAX],n,m;
int min(int a,int b)
{
    return a<b?a:b;
}
void floyd()
{
    int i,j,k;
    for(k=1; k<=(n+1)*(m+1); k++)
        for(i=1; i<=(n+1)*(m+1); i++)
            for(j=1; j<=(n+1)*(m+1); j++)
                     dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
}
int main()
{
    int i,j;
    int v;
    char c1;
    while(scanf("%d%d",&n,&m)==2,n+m)
    {
        for(i=1; i<=MAX; i++)
            for(j=1; j<=MAX; j++)
               { dp[i][j]=INF;
                  if(i==j)
                      dp[i][j]=0;
                    }
        for(i=1; i<=2*n+1; i++)
        {
            if(i%2==1)
            {
                for(j=1; j<=m; j++)
                {
                    scanf("%d",&v);
                    getchar();
                    scanf("%c",&c1);
                    if(v==0)
                        continue;
                    int c=(m+1)*(i/2)+j;
                    int r=c+1;
                    if(c1=='*')
                    {
                        dp[c][r]=2520/v;
                        dp[r][c]=2520/v;
                    }
                    else if(c1=='<')
                        dp[r][c]=2520/v;
                    else
                        dp[c][r]=2520/v;
                }
                getchar();
            }
            else
            {
                for(j=1; j<=m+1; j++)
                {
                    scanf("%d",&v);
                    getchar();
                    scanf("%c",&c1);
                    if(v==0)
                        continue;
                    int r=(i-1)/2*(m+1)+j;
                    int c=(i+1)/2*(m+1)+j;
                    if(c1=='*')
                    {
                        dp[c][r]=2520/v;
                        dp[r][c]=2520/v;
                    }
                    else if(c1=='v')
                        dp[r][c]=2520/v;
                    else
                        dp[c][r]=2520/v;
                }
                getchar();
            }
        }
        floyd();
        if(dp[1][(n+1)*(m+1)]<INF)
                printf("%d blips\n",dp[1][(n+1)*(m+1)]);
        else
                puts("Holiday");
    }
    return 0;
}


