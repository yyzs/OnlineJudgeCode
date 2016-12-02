#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#define max 100010
using namespace std;
vector<int> g[max];
vector<int> rg[max];
vector<int> vs;
int used[max],cmp[max];
int n,m;
void addedge(int from,int to)
{
    g[from].push_back(to);
    rg[to].push_back(from);
}
void dfs(int v)
{
    int i;
    used[v]=1;
    for(i=0;i<g[v].size();i++)
        if(!used[g[v][i]])
             dfs(g[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    int i;
    used[v]=1;
    cmp[v]=k;
    for(i=0;i<rg[v].size();i++)
        if(!used[rg[v][i]])
           rdfs(rg[v][i],k);
}
int scc()
{
    int i;
    memset(used,0,sizeof(used));
    vs.clear();
    for(i=1;i<=n;i++)
        if(!used[i])
           dfs(i);
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--)
        if(!used[vs[i]])
           rdfs(vs[i],k++);
    if(k==1)
         return 1;
    return 0;
}
int main()
{
    int x,y;
    while(scanf("%d%d",&n,&m)==2,n+m)
    {
        for(int i=0;i<=100000;i++)
        { g[i].clear();
          rg[i].clear();
        }
        while(m--)
        {
            scanf("%d%d",&x,&y);
            addedge(x,y);
        }
            if(scc())
                  puts("Yes");
            else
                  puts("No");
    }
    return 0;
}

