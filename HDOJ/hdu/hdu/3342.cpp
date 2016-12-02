#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "queue"
#define MAX 210
using namespace std;
int hash[MAX];
int n,m;
struct edge
{
    int next,v;
}e[MAX];
int cnt,head[MAX];
void addedge(int u,int v)
{
    e[cnt].v=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}
int main()
{
    int i,j,ok,u,v;
    int a,b;
    int d=0;
    while(scanf("%d%d",&n,&m)==2,n+m)
    {
        cnt=0;
        memset(head,-1,sizeof(head));
        memset(hash,0,sizeof(hash));
        while(m--)
        {
            scanf("%d%d",&a,&b);
            addedge(a,b);
            hash[b]++;
        }
        priority_queue<int> que;
        for(i=0;i<n;i++)
             if(!hash[i])
                {que.push(i);
                 // break;
                 //printf("i:%d\n",i);
                }
        d=0;
        while(!que.empty())
        {
             u=que.top();
             d++;
             que.pop();
             for(i=head[u];i!=-1;i=e[i].next)
            {
                v=e[i].v;
                hash[v]--;
                if(!hash[v])
                    {//printf("v:%d\n",v);
                     que.push(v);
                    }
            }
        }
        //printf("%d\n",d);
        if(d!=n)
              puts("NO");
        else
              puts("YES");
    }
    return 0;
}

