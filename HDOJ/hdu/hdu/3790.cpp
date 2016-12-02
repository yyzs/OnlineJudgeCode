#include "stdio.h"
#include "string.h"
#define MAX 1010
#define INF 100000000
int vis[MAX],dis[MAX],g[MAX][MAX];
int co[MAX][MAX];
int cost[MAX];
void dijkstra(int a,int b,int n)
{
   int i,j,temp;
   int t;
   for(i=1;i<=n;i++)
            {dis[i]=g[a][i];
             cost[i]=co[a][i];
             }
  dis[a]=0;
  cost[a]=0;
  memset(vis,0,sizeof(vis));
  vis[a]=1;
  for(i=1;i<n;i++)
  {
    t=a;
    temp=INF;
    for(j=1;j<=n;j++)
          if(dis[j]<temp&&!vis[j])
             {t=j;
              temp=dis[j];
              }
    vis[t]=1;
    for(j=1;j<=n;j++)
          {if(!vis[j]&&dis[j]>dis[t]+g[t][j]&&g[t][j]!=INF)
                       {dis[j]=dis[t]+g[t][j];
                        cost[j]=cost[t]+co[t][j];
                        }
           else
                       if(!vis[j]&&dis[j]==dis[t]+g[t][j]&&cost[j]>cost[t]+co[t][j]&&g[t][j]!=INF)
                             cost[j]=cost[t]+co[t][j];
           }
    }
    printf("%d %d\n",dis[b],cost[b]);
}
int main()
{int n,m,a,b,d,p;
 int s,t,i,j;
 while(scanf("%d%d",&n,&m)==2)
 {if(n==0&&m==0)
         break;
  for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
                {g[i][j]=INF;
                 g[j][i]=INF;
                 co[i][j]=INF;
                 co[j][i]=INF;
                 }
   while(m--)
   {scanf("%d%d%d%d",&a,&b,&d,&p);
    if(d<g[a][b])
            {
                g[a][b]=g[b][a]=d;
                co[a][b]=co[b][a]=p;
            }
            else if(d==g[a][b] && p<co[a][b])
            {
                co[a][b]=co[b][a]=p;
            }
    }
   scanf("%d%d",&s,&t);
   dijkstra(s,t,n);
   }
   return 0;
}

