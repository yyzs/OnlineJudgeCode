#include "stdio.h"
#include "string.h"
int vis[10010];
int main()
{int k,m,i;
 int t;
 int flag;
 int r,c;
 int num;
 while(scanf("%d",&k)==1&&k)
 {scanf("%d",&m);
  memset(vis,0,sizeof(vis));
  for(i=0;i<k;i++)
           {scanf("%d",&t);
            vis[t]=1;
            }
  flag=1;
  while(m--)
  {scanf("%d%d",&c,&r);
   num=0;
   for(i=0;i<c;i++)
          {scanf("%d",&t);
           if(vis[t])
                num++;
           }
    if(num<r)
          flag=0;
    }
    if(flag==1)
           printf("yes\n");
    else
           printf("no\n");
    }
    return 0;
}

