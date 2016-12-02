#include "stdio.h"
#include "string.h"
int vis[1000];
int mon[1000];
char b[1000];
int main()
{int t;
 int n,sum;
 int cas,i;
 scanf("%d",&t);
 while(t--)
 {scanf("%d%s",&n,&b);
  cas=0;
  memset(vis,0,sizeof(vis));
  for(i=0;i<n;i++)
        {if(b[i]=='1')
             {vis[i]=1;
               cas++;
             }
         }
   sum=0;
   for(i=0;i<n;i++)
         {scanf("%d",&mon[i]);
          if(vis[i]==1)
               sum=sum+mon[i];
          }
   sum/=10;
   if(sum==0)
          sum=0;
   else
          if(sum>0&&sum<2)
               sum=3;
   else
         if(sum>=2&&sum<3)
               sum=5;
   else
         if(sum>=3&&sum<9)
              sum=(sum-1)*5;
   else
            sum=40;
   printf("Samuel was accused with %d case(s),and he will stay in the prison for %d year(s).\n",cas,sum);
   }
   return 0;
}

