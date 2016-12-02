#include "stdio.h"
#include "string.h"
#define MAX 110
#include "algorithm"
using namespace std;
int a[MAX][MAX],b[MAX][MAX];
int link[MAX],vis[MAX];
int n,k;
int dfs(int u)
{
        for(int i=0;i<n;i++)
        {
                if(b[u][i]&&!vis[i])
                {
                        vis[i]=1;
                        if(link[i]==-1||dfs(link[i]))
                        {
                                link[i]=u;
                                return 1;
                        }
                }
        }
        return 0;
}
int hungary()
{
        int ans=0;
        memset(link,-1,sizeof(link));
        for(int i=0;i<n;i++)
        {
                memset(vis,0,sizeof(vis));
                if(dfs(i))
                        ans++;
        }
        return ans;
}
int main()
{
    while(scanf("%d%d",&n,&k)==2,n+k)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        int ok=0;
        for(int i=1; i<=50; i++)
        {
            memset(b,0,sizeof(b));
            for(int x=0; x<n; x++)
                for(int y=0; y<n; y++)
                    if(a[x][y]==i)
                    {
                        b[x][y]=1;
                    }
            if(hungary()>k)
            {
                if(ok)
                    printf(" %d",i);
                else
                    printf("%d",i);
                ok=1;
            }
        }
        if(!ok)
            puts("-1");
        else
            puts("");
    }
    return 0;
}

