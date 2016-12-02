#include "stdio.h"
#include "string.h"
#define MAX 10010
double dp[MAX];
double pro[MAX];
int w[MAX];
double min(double a,double b)
{
    return a<b?a:b;
}
int main()
{
      int i,j;
      int n,m;
      while(scanf("%d%d",&n,&m)==2,n+m)
      {
           if(m==0)
           {printf("0.0%%\n");continue;}
           for(i=0;i<m;i++)
                 scanf("%d%lf",&w[i],&pro[i]);
           for(i=0;i<m;i++)
                for(j=0;j<=n;j++)
                     {
                         dp[j]=1;
                     }
           for(i=0;i<m;i++)
           {
                  for(j=n;j>=w[i];j--)
                  {       if(i==0)  {dp[j]=1-pro[i];continue;}
                           dp[j]=min(dp[j-w[i]]*(1-pro[i]),dp[j]);
                  }
           }
          /* for(i=0;i<m;i++)
           {
                 for(j=0;j<=n;j++)
                         printf("%lf ",dp[i][j]);
                 printf("\n");
           }*/
           printf("%.1f%%\n",(1-dp[n])*100);
      }
      return 0;
}

