#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
int dp[1010];
int c[1010],w[1010];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{int n,m,ans;
  int i,j;
  while(scanf("%d",&n)==1&&n)
  {memset(c,0,sizeof(c));
    memset(w,0,sizeof(w));
    memset(dp,0,sizeof(dp));
    for(i=0;i<n;i++)
            {scanf("%d",&c[i]);
              w[i]=c[i];
              }
    scanf("%d",&m);
    if(m<5)
              {printf("%d\n",m);
                continue;
              }
    sort(c,c+n);
    sort(w,w+n);
    for(i=0;i<n-1;i++)
            for(j=m-5;j>=w[i];j--)
                 dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
    printf("%d\n",m-dp[m-5]-w[n-1]);
    }
    return 0;
}

