#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 100010
using namespace std;
double dp[MAX];
int fly[MAX];
int main()
{
     int a,b;
     int n,m;
     while(scanf("%d%d",&n,&m)==2,n+m)
     {
          memset(fly,-1,sizeof(fly));
          while(m--)
          {
                scanf("%d%d",&a,&b);
                if(a<b)
                     fly[a]=b;
                else
                     fly[b]=a;
          }
          for(int i=0;i<=MAX-10;i++)
                dp[i]=0;
          for(int i=n-1;i>=0;i--)
          {
                 if(fly[i]!=-1)
                 {
                       dp[i]=dp[fly[i]];
                 }
                 else
                 {
                      dp[i]=1.0/6*(dp[i+1]+dp[i+2]+dp[i+3]+dp[i+4]+dp[i+5]+dp[i+6])+1.0;
                 }
          }
          printf("%.4f\n",dp[0]);
     }
     return 0;
}

