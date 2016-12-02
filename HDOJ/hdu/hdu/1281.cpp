#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 110
using namespace std;
int g[MAX][MAX];
int n,m,k;
int link[MAX],vis[MAX];
struct node
{
        int u,v;
}node[MAX*MAX];
int dfs(int u)
{
        for(int i=1;i<=m;i++)
        {
                if(g[u][i]&&!vis[i])
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
        for(int i=1;i<=n;i++)
        {
                memset(vis,0,sizeof(vis));
                if(dfs(i))
                        ans++;
        }
        return ans;
}
int main()
{
        int cas=0;
        while(scanf("%d%d%d",&n,&m,&k)==3)
        {
                memset(g,0,sizeof(g));
                for(int i=0;i<k;i++)
                {
                        scanf("%d%d",&node[i].u,&node[i].v);
                        g[node[i].u][node[i].v]=1;
                }
                int ans1=0;
                int ans=hungary();
                for(int i=0;i<k;i++)
                {
                                g[node[i].u][node[i].v]=0;
                                if(hungary()<ans)
                                        ans1++;
                                g[node[i].u][node[i].v]=1;
                }
                cas++;
                printf("Board %d have %d important blanks for %d chessmen.\n",cas,ans1,ans);
        }
        return 0;
}

