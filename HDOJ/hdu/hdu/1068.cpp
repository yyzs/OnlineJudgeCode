#include "stdio.h"
#include "string.h"
#define MAX 500
int g[MAX][MAX],linker[MAX],used[MAX];
int num;
int dfs(int u)
{int v;
 for(v=0;v<num;v++)
 {
     if(g[u][v]&&!used[v])
     {used[v]=1;
      if(linker[v]==-1 || dfs(linker[v]))
             {
                 linker[v]=u;
                 return 1;
             }
      }
   }
   return 0;
}
int hungary()
{int res=0;
 int u;
 memset(linker,-1,sizeof(linker));
 for(u=0;u<num;u++)
 {memset(used,0,sizeof(used));
  if(dfs(u))
      res++;
  }
 return res;
 }
int main()
{int a,b,c,cas,n;
 int m;
 int t,i;
 while(scanf("%d",&t)==1)
 {  num=t;
    memset(g,0,sizeof(g));
    while(t--)
    {scanf("%d: (%d)",&a,&b);
     for(i=0;i<b;i++)
          {scanf("%d",&c);
           g[a][c]=1;
          }
    }
     printf("%d\n",num-hungary()/2);
   }
   return 0;
}


