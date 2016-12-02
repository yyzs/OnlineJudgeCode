#include "stdio.h"
#include "string.h"
#include <queue>
#include "stdlib.h"
#include "algorithm"
#define MAXN 1111
#define MAXM 505000
#define oo 1<<30
using namespace std;
int idx;
int cur[MAXN],pre[MAXN];
int dis[MAXN],gap[MAXN];
int aug[MAXN],head[MAXN];
struct node
{
  int u,v,w;
  int next;
}edge[MAXM];
void addEdge(int u,int v,int w)
{
     edge[idx].u=u;
     edge[idx].v=v;
     edge[idx].w=w;
     edge[idx].next=head[u];
     head[u]=idx++;

     edge[idx].u=v;
     edge[idx].v=u;
     edge[idx].w=0;
     edge[idx].next=head[v];
     head[v]=idx++;
}
int SAP(int s,int e,int n)
{
     int max_flow=0,v,u=s;
     int id,mindis;
     aug[s]=oo;
     pre[s]=-1;
     memset(dis,0,sizeof(dis));
     memset(gap,0,sizeof(gap));
     gap[0]=n;
     for(int i=0;i<=n;++i)
           {
               cur[i]=head[i];
            }
    while(dis[s]<n)
          {
            int flag=0;
            if(u==e)
            {max_flow+=aug[e];
             for(v=pre[e];v!=-1;v=pre[v])
               {
                  id=cur[v];
                  edge[id].w-=aug[e];
                  edge[id^1].w+=aug[e];
                  aug[v]-=aug[e];
                  if(edge[id].w==0)
                         u=v;
                 }
            }
     for(id=cur[u];id!=-1;id=edge[id].next)
     {
            v=edge[id].v;
            if(edge[id].w>0&&dis[u]==dis[v]+1)
               {
                  flag=1;
                  pre[v]=u;
                  cur[u]=id;
                  aug[v]=min(aug[u],edge[id].w);
                  u=v;
                  break;
                }
      }
      if(flag==0)
             {
                if(--gap[dis[u]]==0)
                           break;
                mindis=n;
                cur[u]=head[u];
                for(id=head[u];id!=-1;id=edge[id].next)
                {
                   v=edge[id].v;
                   if(edge[id].w>0&&dis[v]<mindis)
                        {
                           mindis=dis[v];
                           cur[u]=id;
                        }
                 }
                 dis[u]=mindis+1;
                 gap[dis[u]]++;
                 if(u!=s)
                      u=pre[u];
              }
        }
    return max_flow;
}
int main()
{
   int t,n,m,pi,si,ei;
   int MAX,sum,source,sink,vn,cas;
   scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
   {idx=0;
     memset(head,-1,sizeof(head));
     sum=0;source=0;MAX=0;
     scanf("%d%d",&n,&m);
     for(int i=1;i<=n;i++)
     {
         scanf("%d%d%d",&pi,&si,&ei);
         sum+=pi;
         MAX=max(MAX,ei);
         addEdge(source,i,pi);
         for(int j=si;j<=ei;++j)
                  addEdge(i,n+j,1);
      }
      sink=n+MAX+1;
      vn=sink+1;
      for(int i=1;i<=MAX;++i)
             addEdge(n+i,sink,m);
     if(SAP(source,sink,vn)==sum)
            printf("Case %d: Yes\n\n", cas);
      else printf("Case %d: No\n\n", cas);
    }
    return 0;
}

