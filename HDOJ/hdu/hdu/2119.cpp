#include "stdio.h"
#include "string.h"
int g[110][110];
int used[110],linker[110];
int n,m;
int  dfs(int u)
{
    int v;
    for(v=0;v<m;v++)
    {
       if(g[u][v]&&!used[v])
             {
                 used[v]=1;
                 if(linker[v]==-1||dfs(linker[v]))
                       {linker[v]=u;
                         return 1;
                        }
                }
      }
     return 0;
}
int hungary()
{
     int res=0;
     int u,i;
     memset(linker,-1,sizeof(linker));
     for(u=0;u<n;u++)
          {memset(used,0,sizeof(used));
             if(dfs(u))
                 res++;
            }
     return res;
}
int main()
{
   int i,j;
   while(scanf("%d%d",&n,&m)==2&&n)
   {
       memset(g,0,sizeof(g));
       for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                 scanf("%d",&g[i][j]);
       printf("%d\n",hungary());
    }
    return 0;
}

