#include "stdio.h"
#include "string.h"
#define Max 1010
#define INF 10000000
int map[Max][Max],dis[Max];
int vis[Max];
int w;
int start[Max];
int dijkstra(int a,int n)
{int i,j,temp,t;
 int min;
 memset(vis,0,sizeof(vis));
 vis[a]=1;
 for(i=0;i<=n;i++)
        dis[i]=(i==a?0:map[a][i]);
 for(i=0;i<=n;i++)
        {temp=INF;
         t=a;
         for(j=0;j<=n;j++)
            if(!vis[j]&&dis[j]<temp)
                  {temp=dis[j];
                   t=j;
                   }
         if(t==a)
             break;
         vis[t]=1;
         for(j=0;j<=n;j++)
                 if(!vis[j]&&map[t][j]<INF&&dis[j]>(dis[t]+map[t][j]))
                      dis[j]=dis[t]+map[t][j];
         }
  min=INF;
  for(i=0;i<w;i++)
        if(dis[start[i]]<min)
            min=dis[start[i]];
 if(min==INF)
        return -1;
 return min;
}
int main()
{int n,m,s;
 int k,i,j;
 int p,q,t;
 while(scanf("%d%d%d",&n,&m,&s)==3)
 {for(i=0;i<=n;i++)
         for(j=0;j<=n;j++)
            map[i][j]=INF;
  for(i=0;i<m;i++)
          {scanf("%d%d%d",&p,&q,&t);
           if(map[q][p]>t)
                {map[q][p]=t;
                 }
           }
  scanf("%d",&w);
  for(i=0;i<w;i++)
          scanf("%d",&start[i]);
  printf("%d\n",dijkstra(s,n));
  }
  return 0;
}

