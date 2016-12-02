#include "stdio.h"
#include "string.h"
#define MAX 504
int g[MAX][MAX];
int ans[MAX][MAX];
int hash[MAX];
int win[MAX][MAX];
int  n;
void dfs(int u)
{
    int v,i;
    if(hash[u])
        return;
    hash[u]=1;
    for(v=1;v<=n;v++)
    {
        if(v==u)
            continue;
        if(g[u][v])
            {dfs(v);
             ans[u][v]=1;
             for(i=1;i<=n;i++)
             {
               if(ans[v][i])
                  {ans[u][i]=1;
                  }
             }
            }
    }
}
int main()
{
    int t;
    int m;
    int i,j;
    int s;
    int a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(g,0,sizeof(g));
        memset(ans,0,sizeof(ans));
        memset(hash,0,sizeof(hash));
        while(m--)
        {
            scanf("%d%d",&a,&b);
            g[a][b]=1;
        }
        for(i=1;i<=n;i++)
            dfs(i);
        s=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
        {
            if(ans[i][j])
                ans[j][i]=1;
        }
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
                if(!ans[i][j])
                     { //printf("%d %d\n",i,j);
                        s++;
                     }
        printf("%d\n",s);
    }
    return 0;
}

