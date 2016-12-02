#include "stdio.h"
#include "string.h"
#define MOD 10000
#define MAX 110
int a[MAX][MAX],dp[MAX][MAX];
int main()
{
    int n,m;
    int i,j,x,y;
    int ans;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
               scanf("%d",&a[i][j]);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                if(i==1&&j==1)
                         dp[i][j]=1;
                for(x=i;x<=i+a[i][j]&&x<=n;x++)
                    for(y=j;y<=j+a[i][j]&&y<=m;y++)
                        {
                            if(x==i&&y==j)
                                   continue;
                            if((x-i+y-j)<=a[i][j])
                                  dp[x][y]=(dp[i][j]%MOD+dp[x][y]%MOD)%MOD;
                        }
            }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}

