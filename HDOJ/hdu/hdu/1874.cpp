#include "stdio.h"
#include "string.h"
#include <queue>
#define INF 1000000000
#define MAX 10000
using namespace std;
int dis[MAX+10];
int vis[MAX+10];
int g[MAX+10][MAX+10];
using namespace std;
typedef pair<int,int> P;
priority_queue<P,vector<P>,greater<P> > que;
void dijkstra(int a,int b,int n)
{
    P p;
    memset(vis,0,sizeof(vis));
    int i,j,temp,t;
    for(i=0;i<n;i++)
          {if(i==a)
              {dis[i]=0;
               que.push(P(0,a));
               }
          else
              {que.push(P(g[a][i],i));
               dis[i]=g[a][i];
               }
          }
    vis[a]=1;
    while(!que.empty())
          { p=que.top();
            que.pop();
            t=p.second;
            temp=p.first;
            if(vis[t])
                continue;
            vis[t]=1;
            if(t==a)
                 break;
             for(j=0;j<n;j++)
                  if(!vis[j]&&g[t][j]<INF&&dis[j]>(dis[t]+g[t][j]))
                          {dis[j]=dis[t]+g[t][j];
                           que.push(P(dis[j],j));
                          }
            }
  if(dis[b]==INF)
            printf("-1\n");
  else
            printf("%d\n",dis[b]);
}
int main()
{int n,m,a,b,t,x,y;
 int i,j;
 while(scanf("%d%d",&n,&m)==2)
 {for(i=0;i<n;i++)
      for(j=0;j<n;j++)
          {g[i][j]=INF;
           g[j][i]=INF;
          }
  for(i=1;i<=m;i++)
      {scanf("%d%d%d",&x,&y,&t);
       if(g[x][y]>t)
           {g[x][y]=t;
            g[y][x]=t;
            }
       }
   scanf("%d%d",&a,&b);
   if(a==b)
        printf("0\n");
   else
        dijkstra(a,b,n);
  }
  return 0;
}

