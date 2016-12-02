#include "stdio.h"
#include "string.h"
int vis[10010];
int main()
{int n,m;
 int i,j;
 int x;
 int max,ans;
 int flag;
 while(scanf("%d%d",&n,&m)==2)
 {if(n==0&&m==0)
      break;
  memset(vis,0,sizeof(vis));
  for(i=0;i<n;i++)
      for(j=0;j<m;j++)
          {scanf("%d",&x);
           vis[x]++;
           }
   max=vis[1];
   for(i=1;i<=10000;i++)
          if(vis[i]>max)
              max=vis[i];
   ans=-1000000;
   for(i=1;i<=10000;i++)
          if(vis[i]>ans&&vis[i]<max)
              ans=vis[i];
   flag=0;
   for(i=1;i<=10000;i++)
          {if(vis[i]==ans)
              {if(!flag)
                    {printf("%d",i);
                     flag=1;
                     }
                else
                    printf(" %d",i);
                }
            }
    printf("\n");
  }
  return 0;
}

