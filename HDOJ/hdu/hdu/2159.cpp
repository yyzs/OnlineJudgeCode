#include "stdio.h"
#include "string.h"
int dp[110][110];
int exper[110],tol[110];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{int n,m,s,i,j,t,K;
 int a,b;
 int ans;
 while(scanf("%d%d%d%d",&n,&m,&K,&s)==4)
 {memset(dp,0,sizeof(dp));
  memset(exper,0,sizeof(exper));
  memset(tol,0,sizeof(tol));
  for(i=0;i<K;i++)
          {scanf("%d%d",&a,&b);
           exper[i]=a;
           tol[i]=b;
           }
  ans=-1;
  for(i=0;i<K;i++)//kind
          for(j=tol[i];j<=m;j++)//忍耐
             for(t=1;t<=s;t++)//杀怪个数
                 {dp[j][t]=max(dp[j][t],dp[j-tol[i]][t-1]+exper[i]);
                  if(dp[j][t]>=n)
                       ans=max(m-j,ans);
                  }
  printf("%d\n",ans);
  }
  return 0;
  }

