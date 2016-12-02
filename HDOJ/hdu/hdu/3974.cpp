#include "stdio.h"
#include "algorithm"
#include "string.h"
#include "vector"
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define MAX  50010
using namespace std;
vector<int> g[MAX],g1[MAX];
int id[MAX],len[MAX],s;
int col[MAX<<2];
int dfs(int u)
{
        len[u]=1;
        id[u]=s;
        s++;
        if(g[u].size()==0)
                return 1;
        for(int i=0;i<g[u].size();i++)
        {
                int v=g[u][i];
                len[u]+=dfs(v);
        }
        return len[u];
}
void push_down(int rt)
{
        if(col[rt]!=-1)
        {
                col[rt<<1]=col[rt];
                col[rt<<1|1]=col[rt];
                col[rt]=-1;
        }
}
void update(int L,int R,int c,int l,int r,int rt)
{
        if(l>=L&&r<=R)
        {
                col[rt]=c;
                return;
        }
        push_down(rt);
        int m=(l+r)/2;
        if(L<=m)
                update(L,R,c,lson);
        if(R>m)
                update(L,R,c,rson);
}
int query(int x,int l,int r,int rt)
{
        if(l==r)
        {
                return col[rt];
        }
        push_down(rt);
        int m=(l+r)/2;
        if(x<=m)
                return query(x,lson);
        if(x>m)
                return query(x,rson);
}
int main()
{
        int n,t,m;
        char c[3];
        int cas=0;
        scanf("%d",&t);
        while(t--)
        {
                cas++;
                printf("Case #%d:\n",cas);
                scanf("%d",&n);
                for(int i=1;i<=n;i++)
                       {g[i].clear();
                        g1[i].clear();
                        }
                for(int i=1;i<=n-1;i++)
                        {
                                int u,v;
                                scanf("%d%d",&u,&v);
                                g[v].push_back(u);
                                g1[u].push_back(v);
                        }
                memset(len,0,sizeof(len));
                memset(id,0,sizeof(id));
                for(int i=1;i<=n;i++)
                {
                        if(g[i].size()!=0&&g1[i].size()==0)
                                {
                                        s=1;
                                        len[i]=dfs(i);
                                        break;
                                }
                }
                if(n==1)
                {
                        len[1]=1;
                        id[1]=1;
                }
               // for(int i=1;i<=n;i++)
                  //      printf("i,id,len:%d %d %d\n",i,id[i],len[i]);
                memset(col,-1,sizeof(col));
                scanf("%d",&m);
                while(m--)
                {
                        scanf("%s",c);
                        if(c[0]=='C')
                        {
                                int x;
                                scanf("%d",&x);
                                printf("%d\n",query(id[x],1,n,1));
                        }
                        else
                        {
                                int x,y;
                                scanf("%d%d",&x,&y);
                             //   printf("x,L,R:%d %d %d\n",x,id[x],id[x]+len[x]-1);
                                update(id[x],id[x]+len[x]-1,y,1,n,1);
                        }
                }
        }
        return 0;
}

