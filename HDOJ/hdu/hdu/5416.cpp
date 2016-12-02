#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "vector"
#include "set"
#define MAX 100010
using namespace std;
int w[MAX*10];
int has[MAX*30];
int len;
int vis[MAX];
struct node
{
        int v,w;
};
vector <node> g[MAX],g1[MAX];
void dfs(int u,int s)
{
        for(int i=0;i<g[u].size();i++)
        {
                node temp=g[u][i];
                int v=temp.v;
                if(vis[v])
                        continue;
                w[len]=(s^temp.w);
                has[s^temp.w]++;
                len++;
                vis[v]=1;
                if(g[v].size()!=0)
                  {
                        dfs(v,(s^temp.w));
                  }
        }
}
int main()
{
        int t,n,q;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d",&n);
                for(int i=1;i<=n;i++)
                        g[i].clear();
                memset(w,0,sizeof(w));
                memset(has,0,sizeof(has));
                memset(vis,0,sizeof(vis));
                for(int i=1;i<=n-1;i++)
                {
                        int a,b,c;
                        scanf("%d%d%d",&a,&b,&c);
                        node temp;
                        temp.v=b;
                        temp.w=c;
                        g[a].push_back(temp);
                        temp.v=a;
                        g[b].push_back(temp);
                }
                if(n!=1)
                       {
                           w[0]=0;
                           has[0]=1;
                           len=1;
                           vis[1]=1;
                           dfs(1,0);
                           sort(w,w+len);
                       }
                scanf("%d",&q);
                while(q--)
                {
                        int s;
                        long long ans=0;
                        scanf("%d",&s);
                        if(n==1)
                        {
                                if(s==0)
                                        puts("1");
                                else
                                        puts("0");
                                continue;
                        }
                        for(int i=0;i<len;i++)
                        {
                              if(i>0&&w[i]==w[i-1])
                                        continue;
                                //printf("W,S^W:%d %d\n",w[i],(s^w[i]));
                               if((s^w[i])==w[i])
                                        ans=ans+(long long)(1+has[w[i]])*(long long)has[w[i]]/2;
                                else
                                    if((s^w[i])>w[i])
                                        ans=ans+(long long)has[w[i]]*(long long)has[s^w[i]];
                        }
                        printf("%I64d\n",ans);
                }
        }
        return 0;
}
