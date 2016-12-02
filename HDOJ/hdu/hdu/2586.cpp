#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
using namespace std;
#define N 51111
struct node
{
    int v,w;
    node(int vv,int ww)
    {
        v=vv;
        w=ww;
    }
};
int f[N],dis[N],ans[N],vis[N],n;
vector<node>mp[N],q[N];
int find(int x)
{
    if(f[x]!=x)
        f[x]=find(f[x]);
    return f[x];
}
void lca(int u)
{
    for(int i=0;i<mp[u].size();i++)
    {
        int v=mp[u][i].v;
        if(vis[v]) continue;
        vis[v]=1;
        dis[v]=dis[u]+mp[u][i].w;
        lca(v);
        f[v]=u;
        for(int j=0;j<q[v].size();j++)
        {
            int c=q[v][j].v;
            if(vis[c]&&ans[q[v][j].w]==-1)
            {
                if(v==c) ans[q[v][j].w]=0;
                else ans[q[v][j].w]=dis[v]+dis[c]-2*dis[find(c)];
            }
        }
    }
}
int main()
{
    int m,n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            mp[i].clear();
            q[i].clear();
            ans[i]=-1;
            f[i]=i;
            vis[i]=0;
        }
        for(int i=1; i<n; i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            mp[a].push_back(node(b,c));
            mp[b].push_back(node(a,c));
        }
        for(int i=1; i<=m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            q[a].push_back(node(b,i));
            q[b].push_back(node(a,i));
        }
        vis[1]=1;
        dis[1]=0;
        lca(1);
        for(int i=1; i<=m; i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}

