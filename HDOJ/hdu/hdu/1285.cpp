#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "queue"
#define MAX 250000
using namespace std;
struct edge
{
    int next,v;
}e[MAX];
int cnt,head[MAX],hash[MAX],ans[MAX];
int n,m;
void addedge(int u,int v)
{
    e[cnt].v=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}
int main()
{
    int i,j;
    int a,b,u,v;
    int d=0;
    while(scanf("%d%d",&n,&m)==2)
    {
        cnt=0;
        memset(head,-1,sizeof(head));
        memset(hash,0,sizeof(hash));
        memset(ans,0,sizeof(ans));
        while(m--)
        {
            scanf("%d%d",&a,&b);
            addedge(a,b);
            hash[b]++;
        }
        priority_queue<int, vector<int>, greater<int> > que;
        for(i=1;i<=n;i++)
            if(!hash[i])
                {que.push(i);
                }
        d=0;
        while(!que.empty())
        {
            u=que.top();
            que.pop();
            ans[d]=u;
            d++;
            for(i=head[u];i!=-1;i=e[i].next)
            {
                v=e[i].v;
                hash[v]--;
                if(!hash[v])
                    que.push(v);
            }
        }
        for(i=0;i<=n-1;i++)
             {if(i==0)
                  printf("%d",ans[i]);
             else
                  printf(" %d",ans[i]);
            }
        printf("\n");
    }
    return 0;
}

