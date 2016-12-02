#pragma comment(linker, "/STACK:1024000000,1024000000")
#include "stdio.h"
#include "string.h"
#define MAX 100100
#include "vector"
#include "algorithm"
#define MOD    1000000007
using namespace std;
vector<int> g[MAX];
int vis[MAX];
long long fac[MAX];
void  init()
{
    fac[0]=1;
    for(int i=1; i<=MAX-100; i++)
        fac[i]=(fac[i-1]%MOD*i)%MOD;
}
long long dfs(int u,int ok)
{
    int a=0,b=0;
    long long ans;
    if(ok)
        ans=2;
    else
        ans=1;
 //  printf("id,initans1:%d %d\n",u,ans);
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(g[v].size()==0)
            a++;
        else
            b++;
    }
    if(b>=3)
        return 0;
    if((b>1)||(b==1&&a!=0))
        ans=(ans%MOD*2%MOD*fac[a])%MOD;
    else
        ans=(ans*fac[a])%MOD;
  //      printf("id,initans2:%d %d\n",u,ans);
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(g[v].size()==0)
            continue;
        if(g[u].size()>1)
            ans=(ans%MOD*dfs(v,0))%MOD;
        else
            ans=(ans%MOD*dfs(v,1))%MOD;
    }
 //   printf("id,ans:%d %d\n",u,ans);
    return ans;
}
int main()
{
    int t,n,rot;
    int cas=0;
   // freopen("1011.in","r",stdin);
   // freopen("out.txt","w",stdout);
    init();
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        vis[1]=1;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            g[i].clear();
        for(int i=1; i<=n-1; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(vis[a])
                g[a].push_back(b);
            else
                g[b].push_back(a);
            vis[a]=1;
            vis[b]=1;
        }
        cas++;
        if(n!=1)
                printf("Case #%d: %lld\n",cas,dfs(1,1));
        else
                printf("Case #%d: %lld\n",cas,1);
    }
    return 0;
}

