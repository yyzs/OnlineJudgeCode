#include "cstdio"
#include "string.h"
#define MAX 110
int g[MAX][MAX],linker[MAX],used[MAX];
int a[MAX][MAX];
int n;
int dfs(int u)
{
    int v;
    for(v=1;v<=n;v++)
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
    int i;
    memset(linker,-1,sizeof(linker));
    for(i=1;i<=n;i++)
    {
        memset(used,0,sizeof(used));
        if(!dfs(i))
            return 0;
    }
    return 1;
}
int getans()
{
    int i,j;
    int ans,minnum,maxnum;
    for(ans=0;ans<=100;ans++)
        for(minnum=0;minnum<=100-ans;minnum++)
    {
        memset(g,0,sizeof(g));
        maxnum=ans+minnum;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
        {
            if(a[i][j]>=minnum&&a[i][j]<=maxnum)
                g[i][j]=1;
        }
        if(hungary())
            return ans;
    }
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
              scanf("%d",&a[i][j]);
        printf("%d\n",getans());
    }
    return 0;
}

