#include "stdio.h"
#include "string.h"
#define INF 10000000
#define MAX 152
char a[MAX][32];
char u[32],v[32];
int map[MAX][MAX],vis[MAX];
int dis[MAX];
int dijkstra(int a,int b,int n)
{int t,temp;
  int i,j;
  memset(vis,0,sizeof(vis));
  vis[a]=1;
  for(i=0;i<n;i++)
         dis[i]=(i==a?0:map[a][i]);
   for(i=0;i<n;i++)
   {temp=INF;
     t=a;
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
    if(dis[b]==INF)
                   printf("-1\n");
    else
                   printf("%d\n",dis[b]);
}
int main()
{int i,j,n,x;
  int m;
  int  ok;
  int u1,v1;
  while(scanf("%d",&n)==1)
  {if(n==-1)
             break;
    for(i=0;i<152;i++)
             memset(a[i],0,sizeof(a[i]));
    scanf("%s%s",a[0],a[1]);
    for(i=0;i<151;i++)
              for(j=0;j<151;j++)
                    map[i][j]=INF;
     m=2;
     memset(u,0,sizeof(u));
     memset(v,0,sizeof(v));
     for(i=0;i<n;i++)
              {scanf("%s%s%d",u,v,&x);
                ok=0;
                for(j=0;j<m;j++)
                     if(strcmp(a[j],u)==0)
                       {ok=1;
                         u1=j;
                         break;
                         }
                 if(!ok)
                        {strcpy(a[m],u);
                          u1=m;
                          m++;
                          }
                 ok=0;
                  for(j=0;j<m;j++)
                     if(strcmp(a[j],v)==0)
                       {ok=1;
                         v1=j;
                         break;
                         }
                 if(!ok)
                        {strcpy(a[m],v);
                          v1=m;
                           m++;
                          }
                  if(map[u1][v1]>x)
                        {map[u1][v1]=x;
                          map[v1][u1]=x;
                          }
                    memset(u,0,sizeof(u));
                    memset(v,0,sizeof(v));
                    }
      if(strcmp(a[0],a[1])==0)
                   printf("0\n");
       else
                    dijkstra(0,1,m);
    }
    return 0;
}

