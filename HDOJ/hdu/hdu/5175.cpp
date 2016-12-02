#include "stdio.h"
#include "math.h"
#include "algorithm"
#define MAX 10000000
using namespace std;
long long ans[MAX];
long long gcd(long long a,long long b)
{
   if(a%b==0)
       return b;
   return gcd(b,a%b);
}
int main()
{
    int cas=0,len;
    long long i,n;
    while(scanf("%I64d",&n)==1)
    {
        len=0;
        for(i=1;i*i<=n;i++)
        {
            if(n%i!=0)
                 continue;
            long long m=(n^i);
            if(m>0&&m<=n&&gcd(n,m)==(n^m))
                  ans[len++]=m;
            m=(n^(n/i));
            if(m>0&&m<=n&&gcd(n,m)==(n^m))
                  ans[len++]=m;
        }
        cas++;
        printf("Case #%d:\n",cas);
        printf("%d\n",len);
        sort(ans,ans+len);
        for(i=0;i<len;i++)
        {
            if(i)
                printf(" %I64d",ans[i]);
            else
                printf("%I64d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}

