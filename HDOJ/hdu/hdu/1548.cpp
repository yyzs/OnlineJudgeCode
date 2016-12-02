#include "stdio.h"
#include "string.h"
#define MAX 210
#define INF 1000000
int g[MAX][MAX];
int k[MAX],dis[MAX],vis[MAX];
int n,a,b;
void dijkstra()
{
     int temp,t;
     int i,j;
     memset(vis,0,sizeof(vis));
     for(i=1;i<=n;i++)
           { if(i==a)
                   dis[i]=0;
              else
                   dis[i]=g[a][i];
           }
      vis[a]=1;
      for(i=1;i<=n;i++)
      {
           temp=INF;
           t=a;
           for(j=1;j<=n;j++)
                   if(temp>dis[j]&&!vis[j])
                            {temp=dis[j];
                              t=j;
                             }
           if(t==a)
                   break;
           vis[t]=1;
           for(j=1;j<=n;j++)
                    if(dis[j]>dis[t]+g[t][j]&&!vis[j]&&g[t][j]<INF)
                           dis[j]=dis[t]+g[t][j];
        }
}
int main()
{
   int i,j;
   while(scanf("%d%d%d",&n,&a,&b)==3&&n)
   {
        memset(k,0,sizeof(k));
        for(i=1;i<=n;i++)
                  for(j=1;j<=n;j++)
                              g[i][j]=INF;
        for(i=1;i<=n;i++)
                 {
                     scanf("%d",&k[i]);
                      if(i+k[i]<=n)
                                  g[i][i+k[i]]=1;
                      if(i-k[i]>=1)
                                  g[i][i-k[i]]=1;
                    }
         dijkstra();
         if(dis[b]==INF)
                    printf("-1\n");
         else
                    printf("%d\n",dis[b]);
    }
    return 0;
}

