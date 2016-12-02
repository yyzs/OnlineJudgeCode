#include "stdio.h"
#include "vector"
#include "string.h"
#include "algorithm"
#define MAX 1010
using namespace std;
vector<int> g[MAX];
int vis[MAX];
int ok;
void dfs(int u)
{
    //    printf("u:%d\n",u);
        if(g[u].size()==0)
                return;
        int num=0;
        int len=0;
        for(int i=0;i<g[u].size();i++)
        {
                int v=g[u][i];
                if(vis[v])
                        continue;
                len++;
                if(g[v].size()-1>0)
                        num++;
        }
       // printf("u,num,len:%d %d %d\n",u,num,len);
        if(num>=1&&len>=2)
                {
                        ok=1;
                        return;
                }
         for(int i=0;i<g[u].size();i++)
        {
                int v=g[u][i];
                if(!vis[v])
                        {
                                vis[v]=1;
                                dfs(v);
                        }
        }
}
int main()
{
        int n;
        while(scanf("%d",&n)==1)
        {
                for(int i=1;i<=1000;i++)
                        g[i].clear();
                memset(vis,0,sizeof(vis));
                for(int i=1;i<=n-1;i++)
                {
                        int u,v;
                        scanf("%d%d",&u,&v);
                        g[u].push_back(v);
                        g[v].push_back(u);
                }
                vis[1]=1;
                ok=0;
                dfs(1);
                if(ok)
                        puts("NO");
                else
                        puts("YES");
        }
        return 0;
}

