#include "stdio.h"
#include "string.h"
#define MAX  100
char a[MAX][20],b[MAX][20];
int g[MAX][MAX];
int linker[MAX],used[MAX];
int k;
int dfs(int u)
{
   int v;
   for(v=0;v<k;v++)
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
   int u,i,ans=0;
   memset(linker,-1,sizeof(linker));
   for(u=0;u<k;u++)
         {
           memset(used,0,sizeof(used));
           if(dfs(u))
               ans++;
          }
    return ans;
}
int main()
{int t,i,j;
 scanf("%d",&t);
 while(t--)
 {
    scanf("%d",&k);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(i=0;i<k;i++)
          {scanf("%s",a[i]);
          if(a[i][0]=='A')
                   a[i][0]='E';
           else
                   if(a[i][0]=='K')
                      a[i][0]='D';
           else
                   if(a[i][0]=='Q')
                      a[i][0]='C';
           else
                   if(a[i][0]=='J')
                      a[i][0]='B';
           else
                   if(a[i][0]=='T')
                      a[i][0]='A';
            if(a[i][1]=='H')
                   a[i][1]='Z';
            }
    for(i=0;i<k;i++)
          {scanf("%s",b[i]);
           if(b[i][0]=='A')
                   b[i][0]='E';
           else
                   if(b[i][0]=='K')
                      b[i][0]='D';
           else
                   if(b[i][0]=='Q')
                      b[i][0]='C';
           else
                   if(b[i][0]=='J')
                      b[i][0]='B';
           else
                   if(b[i][0]=='T')
                      b[i][0]='A';
           if(b[i][1]=='H')
                   b[i][1]='Z';
          }
    memset(g,0,sizeof(g));
    for(i=0;i<k;i++)
          for(j=0;j<k;j++)
              if(strcmp(a[i],b[j])<0)
                     {
                      g[j][i]=1;
                      }
    printf("%d\n",hungary());
  }
  return 0;
}

