#include "stdio.h"
#include "string.h"
#include "queue"
#include "algorithm"
#define MAXN 1010
#define INF 100000000
using namespace std;
int ans[MAXN];
struct qnode
{
   int v,c;
   qnode(int v=0,int c=0):v(v),c(c){}
   bool operator<(const qnode&r)const
   {
       return c>r.c;
   }
};
struct edge
{
    int v,cost;
    edge(int v=0,int cost=0):v(v),cost(cost){}
};
vector<edge> E[MAXN];
bool vis[MAXN];
int dist[MAXN];
void dijkstra(int n,int start)
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++) dist[i]=INF;
    dist[start]=0;
    priority_queue<qnode>que;
    while(!que.empty())
         que.pop();
    dist[start]=0;
    que.push(qnode(start,0));
    while(!que.empty())
    {
        qnode tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u])
             continue;
        vis[u]=true;
        for(int i=0;i<E[u].size();i++)
        {
            int v=E[tmp.v][i].v;
            int cost=E[tmp.v][i].cost;
            if(!vis[v]&&dist[u]+cost<dist[v])
                 {dist[v]=dist[u]+cost;
                  que.push(qnode(v,dist[v]));
                 }
        }
    }
}
void addedge(int u,int v,int w)
{
    E[u].push_back(edge(v,w));
}
int dfs(int v)
{
    if(ans[v]!=-1)
           return ans[v];
    if(v==2)
           return 1;
    ans[v]=0;
    for(int i=0;i<E[v].size();i++)
    {
        int u=E[v][i].v;
        if(dist[u]<dist[v])
           ans[v]+=dfs(u);
    }
    return ans[v];
}
int main()
{
    int n,m,a,b,c;
    while(scanf("%d",&n)==1,n)
    {
        scanf("%d",&m);
        for(int i=0;i<n;i++)
           E[i].clear();
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c);
            addedge(b,a,c);
        }
        dijkstra(n,2);
        memset(ans,-1,sizeof(ans));
        printf("%d\n",dfs(1));
    }
    return 0;
}

