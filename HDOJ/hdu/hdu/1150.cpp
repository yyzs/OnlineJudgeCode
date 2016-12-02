#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 220
using namespace std;
int dp[MAX][MAX];
int link[MAX],vis[MAX];
void floyd(int n)
{
        for(int k=0;k<n;k++)
                for(int i=0;i<n;i++)
                        for(int j=0;j<n;j++)
                                dp[i][j]=dp[i][j]||(dp[i][k]&&dp[k][j]);
}
int dfs(int u,int n)
{
        for(int i=0;i<n;i++)
        {
                if(!vis[i]&&dp[u][i])
                {
                        vis[i]=1;
                        if(link[i]==-1||dfs(link[i],n))
                                {
                                        link[i]=u;
                                        return 1;
                                }
                }
        }
        return 0;
}
int  hungary(int n)
{
        int ans=0;
        memset(link,-1,sizeof(link));
        for(int i=0;i<n;i++)
        {
                memset(vis,0,sizeof(vis));
                if(dfs(i,n))
                        ans++;
        }
        return ans;
}
int main()
{
        int n,m,k;
        while(scanf("%d",&n),n)
        {
                scanf("%d%d",&m,&k);
               memset(dp,0,sizeof(dp));
                for(int i=0;i<k;i++)
                {
                        int a,b;
                        scanf("%*d%d%d",&a,&b);
                        a--;
                        b--;
                       // if(a==0||b==0)
                                dp[a][b]=1;
                }
              //  floyd(n);
                printf("%d\n",hungary(n));
        }
        return 0;
}

