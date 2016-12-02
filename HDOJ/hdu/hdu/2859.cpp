#include "stdio.h"
#include "string.h"
#define MAX 1010
#include "algorithm"
using namespace std;
char g[MAX][MAX];
int dp[MAX][MAX];
int main()
{
    int n,maxnum,v;
    while(scanf("%d",&n)==1,n)
    {
        for(int i=1; i<=n; i++)
            scanf("%s",&g[i][1]);
        memset(dp,0,sizeof(dp));
        maxnum=0;
        for(int x=1; x<=n; x++)
            for(int y=n; y>=1; y--)
            {
                for(v=1;v<=dp[x-1][y+1]; v++)
                {
                    if(x-v>=1&&x-v<=n&&y+v>=1&&y+v<=n&&g[x-v][y]==g[x][y+v])
                        continue;
                    else
                        break;
                }
                if(v>dp[x-1][y+1]) dp[x][y]=dp[x-1][y+1]+1;
                else dp[x][y]=v;
                if(dp[x][y]>maxnum)
                    maxnum=dp[x][y];
            }
        printf("%d\n",maxnum);
    }
    return 0;
}

