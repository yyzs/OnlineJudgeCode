#include "stdio.h"
#include "string.h"
#define MAX 105
#define INF 100000000
int g[MAX][MAX];
int po[MAX];
int dp[1000000],dis[MAX],vis[MAX];
int n,m;
void dijkstra()
{
   int i,j,t,temp;
   for(i=1;i<=n;i++)
          dis[i]=g[0][i];
   dis[0]=0;
   memset(vis,0,sizeof(vis));
   vis[0]=1;
   for(i=0;i<=n;i++)
         {t=0;
          temp=INF;
          for(j=0;j<=n;j++)
                  if(!vis[j]&&dis[j]<temp)
                     {temp=dis[j];
                      t=j;
                      }
          if(t==0)
                break;
          vis[t]=1;
          for(j=0;j<=n;j++)
                 if(!vis[j]&&dis[j]>dis[t]+g[t][j])
                         dis[j]=dis[t]+g[t][j];
          }
}
int max(int a,int b)
{
   return a>b?a:b;
}
int main()
{
  int i,j;
  int s,t,end,x;
  int v,w;
  int ok;
  scanf("%d",&t);
  while(t--)
  {scanf("%d%d",&n,&m);
   for(i=0;i<=n;i++)
          for(j=0;j<=n;j++)
              {if(i==j)
                    g[i][j]=0;
               else
                    g[i][j]=INF;
              }
   while(m--)
        {scanf("%d%d%d",&s,&end,&x);
         if(g[s][end]>x)
               g[end][s]=g[s][end]=x;
        }
   v=0;
   memset(po,0,sizeof(po));
   memset(dp,0,sizeof(dp));
   for(i=1;i<=n;i++)
         {scanf("%d",&po[i]);
          v+=po[i];
          }
   v=v/2+1;
   dijkstra();
   w=0;
   for(i=1;i<=n;i++)
          if(dis[i]!=INF)
              w+=dis[i];
   ok=0;
   for(i=1;i<=n;i++)
       {if(dis[i]!=INF)
            {for(j=w;j>=dis[i];j--)
                dp[j]=max(dp[j],dp[j-dis[i]]+po[i]);
            }
       }
   for(i=0;i<=w;i++)
        {if(dp[i]>=v)
            {ok=1;
             break;
            }
        }
   if(ok)
        printf("%d\n",i);
   else
        printf("impossible\n");
   }
   return 0;
}

