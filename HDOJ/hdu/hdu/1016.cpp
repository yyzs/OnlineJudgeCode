#include "stdio.h"
#include "string.h"
int a[100];
int vis[100];
int n;
int prime(int x)
{
  int i;
  if(x==2)
       return 1;
  for(i=2;i*i<=x;i++)
       if(x%i==0)
           return 0;
  return 1;
}
void dfs(int x,int k)
{
   int i;
   if(k==n)
        {if(prime(x+1))
                  {
                      for(i=1;i<=n;i++)
                           {if(i==1)
                                 printf("%d",a[i]);
                            else
                                  printf(" %d",a[i]);
                            }
                      printf("\n");
                    }
            }
    else
       for(i=2;i<=n;i++)
            {if(vis[i]==0&&prime(x+i))
                   { a[k+1]=i;
                     vis[i]=1;
                     dfs(i,k+1);
                     vis[i]=0;
                   }
            }
}
int main()
{int i,j;
 int cas=0;
 while(scanf("%d",&n)==1)
 {a[1]=1;
  memset(vis,0,sizeof(vis));
  vis[1]=1;
  cas++;
  printf("Case %d:\n",cas);
  dfs(1,1);
  printf("\n");
  }
  return 0;
}

