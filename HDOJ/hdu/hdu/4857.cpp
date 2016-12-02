#include "stdio.h"
#include "queue"
#include "algorithm"
#include "string.h"
#define MAX 30010
using namespace std;
int hash[MAX];
int ans[MAX];
struct edge
{
    int next,v;
}e[100001];
int cnt,head[MAX];
void addedge(int u,int v)
{
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}
int main()
{
    int n,m;
    int t,i,j;
    int a,b;
    int temp;
    int d;
    int v,u;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(head));
        memset(hash,0,sizeof(hash));
        memset(ans,0,sizeof(ans));
        while(m--)
        {
              scanf("%d%d",&a,&b);
              addedge(b,a);
              hash[a]++;
        }
        priority_queue<int> que;
        while(!que.empty())
               que.pop();
        for(i=1;i<=n;i++)
               if(hash[i]==0)
                   que.push(i);
        //printf("%d\n",temp);
        d=1;
        while(!que.empty())
        {
               u=que.top();
               que.pop();
               ans[d]=u;
               d++;
               for(i=head[u];i!=-1;i=e[i].next)
                {
                    v =e[i].v;
                    hash[v]--;
                    if(!hash[v])
                          {que.push(v);
                          }
                }
        }
        for(i=n;i>=1;i--)
               {if(i==n)
                     printf("%d",ans[i]);
                else
                     printf(" %d",ans[i]);
               }
        printf("\n");
    }
    return 0;
}

