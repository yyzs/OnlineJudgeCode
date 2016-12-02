#include "stdio.h"
#include "string.h"
#include "vector"
#define MAX 2000010
using namespace std;
int h[MAX];
int n,k,cnte;
int head,tail;
long long ans;
struct node
{
    int v,p,d;
    node(){}
    node(int v,int p,int d):v(v),p(p),d(d){}
};
struct edge
{
    int v,n;
    edge(){}
    edge(int v,int n):v(v),n(n){}
};
node q[MAX*2];
edge e[MAX];
void addedge(int u,int v)
{
    e[cnte]=edge(v,h[u]);
    h[u]=cnte++;
}
void bfs()
{
    int cnt=0;
    head=tail=0;
    for(int i=1;i<=n;i++)
         q[tail++]=node(i,0,0);
    while(head!=tail){
        node x=q[head++];
        int u=x.v,p=x.p;
        for(int i=h[u];~i;i=e[i].n)
        {
            int v=e[i].v;
            if(v!=p)
            {
                q[tail++]=node(v,u,x.d+1);
                ans+=x.d+1;
                ++cnt;
                if(cnt==k)
                    return;
            }
        }
    }
}
void slove()
{
    int i,j;
    int u,v;
    ans=0;
    k*=2;
    memset(h,-1,sizeof(h));
    cnte=0;
    for(i=0; i<n-1; i++)
    {
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    bfs();
    printf("%I64d\n",ans/2);
}
int main()
{
    int i,j;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        slove();
    }

}

