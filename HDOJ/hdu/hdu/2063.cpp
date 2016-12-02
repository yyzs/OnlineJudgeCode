#include "stdio.h"
#include "string.h"
#define MAX 1010
int used[MAX],linker[MAX],g[MAX][MAX];
int n,m;
int dfs(int u)
{
    int v,i;
    for(v=1; v<=m; v++)
    {
        if(g[u][v]&&!used[v])
        {
            used[v]=1;
            if(linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int hungary()
{
    int i,j;
    int ans=0;
    memset(linker,-1,sizeof(linker));
    for(i=1; i<=n; i++)
    {
        memset(used,0,sizeof(used));
        if(dfs(i))
            ans++;
    }
    return ans;
}
int main()
{
    int k,i,j,a,b;
    while(scanf("%d%d%d",&k,&m,&n)==3,k)
    {
        memset(g,0,sizeof(g));
        for(i=1; i<=k; i++)
        {
            scanf("%d%d",&a,&b);
            g[b][a]=1;
        }
        printf("%d\n",hungary());
    }
    return 0;
}

