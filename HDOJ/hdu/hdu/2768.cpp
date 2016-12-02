#include "stdio.h"
#include "string.h"
#define MAX 520
int g[MAX][MAX];
int linker[MAX],used[MAX];
int c,d,v;
struct child
{
  char a[5];
  char b[5];
}s[520];
int dfs(int u)
{
   int v1,i;
   for(v1=0;v1<v;v1++)
   {
      if(g[u][v1]&&!used[v1])
         {
            used[v1]=1;
            if(linker[v1]==-1||dfs(linker[v1]))
              {
                 linker[v1]=u;
                 return 1;
              }
           }
    }
    return 0;
}
int hungary()
{
   int res=0,i,u;
   memset(linker,-1,sizeof(linker));
   for(u=0;u<v;u++)
   {
       memset(used,0,sizeof(used));
       if(dfs(u))
           res++;
   }
   return res;
}
int main()
{
  int t;
  int i,j;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d%d",&c,&d,&v);
    for(i=0;i<v;i++)
         scanf("%s%s",s[i].a,s[i].b);
    memset(g,0,sizeof(g));
    for(i=0;i<v;i++)
         for(j=i+1;j<v;j++)
              if((strcmp(s[j].a,s[i].b)==0||strcmp(s[j].b,s[i].a)==0)&&i!=j)
                   {
                     g[i][j]=1;
                     g[j][i]=1;
                     }
    printf("%d\n",v-hungary()/2);
  }
  return 0;
}

