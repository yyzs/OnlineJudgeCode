#include "stdio.h"
#include "string.h"
int p[1010],h[1010];
int dp[1010];
int max(int a,int b)
{
   return a>b?a:b;
}
int main()
{int t,i,j,n,m;
 int p1,h1,c;
 int num;
 scanf("%d",&t);
 while(t--)
 {scanf("%d%d",&n,&m);
  num=0;
  for(i=0;i<m;i++)
       {scanf("%d%d%d",&p1,&h1,&c);
        for(j=0;j<c;j++)
        {p[num]=p1;
         h[num]=h1;
         num++;
         }
        }
  memset(dp,0,sizeof(dp));
  for(i=0;i<num;i++)
       for(j=n;j>=p[i];j--)
           dp[j]=max(dp[j],dp[j-p[i]]+h[i]);
  printf("%d\n",dp[n]);
  }
  return 0;
}

