#include "stdio.h"
#include "string.h"
#define MAX 320
int g[MAX][MAX];
int used[MAX],linker[MAX];
int n,m,i,j;
int dfs(int u)
{
    int v;
    for(v=1;v<=m;v++)
    {
          if(g[u][v]&&!used[v])
               {
                 used[v]=1;
                 if(linker[v]==-1||dfs(linker[v]))
                       {
                           linker[v]=u;
                           return 1;
                        }
                }
        }
    return 0;
}
int hungary()
{
     int u,i;
     int res=0;
     memset(linker,-1,sizeof(linker));
     for(u=1;u<=n;u++)
        {
           memset(used,0,sizeof(used));
           if(dfs(u))
                    res++;
            }
    return res;
}
int main()
{
   int num;
   int x;
   int t;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d%d",&m,&n);
       memset(g,0,sizeof(g));
       for(i=0;i<m;i++)
           {
               scanf("%d",&num);
               while(num--)
                   {
                      scanf("%d",&x);
                      g[x][i+1]=1;
                     }
            }
        if(hungary()==m)
                printf("YES\n");
        else
                printf("NO\n");
    }
    return 0;
}

