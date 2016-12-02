#include "stdio.h"
int dp[2001][2001],a[2001];
int min(int a,int b)
{
 return a<b?a:b;
}
int main()
{int n,k;
 int i,j;
 while(scanf("%d%d",&n,&k)==2)
  {for(i=1;i<=n;i++)
     for(j=1;j<=k;j++)
         dp[i][j]=2147483646;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
   for(i=1;i<n;i++)
      for(j=i+1;j<=n;j++)
        if(a[j]<a[i])
          a[j]^=a[i]^=a[j]^=a[i];
    for(i=2;i<=n;i++)
       for(j=1;j*2<=i;j++)
         {
               dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]));
         }
    printf("%d\n",dp[n][k]);
  }
  return 0;
}

