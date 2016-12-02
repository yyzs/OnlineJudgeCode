#include "stdio.h"
#include "string.h"
#define INF 10000000
#define MAX 110
int dis[MAX],vis[MAX],map[MAX][MAX];
int kruskal(int a,int n)
{int t,temp,i,j;
  int ok=1;
  memset(vis,0,sizeof(vis));
  vis[a]=1;
  for(i=0;i<n;i++)
           dis[i]=(i==a?0:map[a][i]);
  for(i=0;i<n;i++)
  {t=a;
    temp=INF;
    for(j=0;j<n;j++)
         if(!vis[j]&&dis[j]<temp)
             {temp=dis[j];
               t=j;
               }
      if(t==a)
              break;
        vis[t]=1;
      for(j=0;j<n;j++)
           if(!vis[j]&&map[t][j]<INF&&dis[j]>(dis[t]+map[t][j]))
                dis[j]=dis[t]+map[t][j];
      }
      ok=1;
      for(i=0;i<n;i++)
          {
            if(i!=a&&dis[i]>7)
               ok=0;
          }
       return ok;
}
int main()
{int i,j,n;
  int ok;
  int m,a,b;
  while(scanf("%d%d",&n,&m)==2)
  {for(i=0;i<n;i++)
             for(j=0;j<n;j++)
                 map[i][j]=INF;
    while(m--)
    {scanf("%d%d",&a,&b);
      if(map[a][b]>1)
              {map[a][b]=1;
                map[b][a]=1;
                }
    }
        ok=1;
       for(i=0;i<n;i++)
                if(kruskal(i,n)==0)
                            {ok=0;
                               break;
                               }
        if(ok)
                 printf("Yes\n");
        else
                 printf("No\n");
  }
        return 0;
}

