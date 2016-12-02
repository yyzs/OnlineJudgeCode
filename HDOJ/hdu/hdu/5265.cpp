#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 1000000
using namespace std;
long long a[MAX];
long long max(long long a,long long b)
{
    return a>b?a:b;
}
int main()
{
     int n,p,i,j;
     long long ans;
     while(scanf("%d%d",&n,&p)==2)
     {
          for(i=0;i<n;i++)
               {
                   scanf("%I64d",&a[i]);
                   a[i]%=p;
               }
          sort(a,a+n);
          j=n-1;
          ans=(a[n-2]+a[n-1])%p;
          for(i=0;i<j;i++)
          {
             ans=max(ans,(a[i]+a[j])%p);
              while((a[i]+a[j])>=p)
              {
                   j--;
                   i--;
              }
          }
          printf("%I64d\n",ans);
     }
     return 0;
}

