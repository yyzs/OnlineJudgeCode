#include "stdio.h"
#include "string.h"
int a[30010],dp[30010];
int main()
{
    int n,i,j,max;
    int m=0;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
               scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            if(i==0)
                dp[i]=1;
            else
               {
                   m=0;
                   for(j=0;j<i;j++)
                       if(a[j]<a[i]&&dp[j]>m)
                             m=dp[j];
                   dp[i]=m+1;
               }
        }
        max=0;
        for(i=0;i<n;i++)
              if(dp[i]>max)
                    max=dp[i];
        printf("%d\n",max);
    }
    return 0;
}

