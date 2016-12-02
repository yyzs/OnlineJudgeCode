#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 100
using namespace std;
struct node
{
    int a,b,col;
} node[MAX];
long long ans;
int a[MAX],b[MAX],num[MAX];
int u,v,n,m,t;
void dfs(int x)
{
    if(x==m)
        return;
    int u=node[x].a;
    int v=node[x].b;
    a[u]++;
    a[v]++;
    int ok=1;
    if(a[u]+b[u]==num[u])
    {
        if(a[u]!=b[u])
            ok=0;
    }
    if(a[v]+b[v]==num[v])
    {
        if(a[v]!=b[v])
            ok=0;
    }
    if(ok)
    {
        dfs(x+1);
        if(x==m-1)
        {
           /* int judge=1;
            for(int i=1; i<=n; i++)
                if(a[i]+b[i]!=num[i]||a[i]!=b[i])
                    {
                        judge=0;
                        break;
                    }
            if(judge)*/
                ans++;
        }
    }
    a[v]--;
    a[u]--;
    b[u]++;
    b[v]++;
    ok=1;
    if(a[u]+b[u]==num[u])
    {
        if(a[u]!=b[u])
            ok=0;
    }
    if(a[v]+b[v]==num[v])
    {
        if(a[v]!=b[v])
            ok=0;
    }
    if(ok)
    {
        dfs(x+1);
        if(x==m-1)
        {
           /*int judge=1;
            for(int i=1; i<=n; i++)
                if(a[i]+b[i]!=num[i]||a[i]!=b[i])
                    {
                        judge=0;
                        break;
                    }
            if(judge)*/
                ans++;
        }
    }
    b[u]--;
    b[v]--;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(m==0)
        {
            puts("1");
            continue;
        }
        ans=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(num,0,sizeof(num));
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            num[u]++;
            num[v]++;
            node[i].a=u;
            node[i].b=v;
        }
        int ok=1;
        for(int i=1; i<=n; i++)
        {
            if(num[i]%2==1)
            {
                ok=0;
                break;
            }
        }
        if(!ok)
        {
            puts("0");
            continue;
        }
        dfs(0);
        printf("%I64d\n",ans);
    }
    return 0;
}
