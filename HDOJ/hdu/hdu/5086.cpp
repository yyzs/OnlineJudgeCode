#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MOD 1000000007
using namespace std;
long long a[10000000];
int main()
{
    int t,n,i;
    long long ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        for(i=1;i<=n;i++)
           ans=(ans+(a[i]*i)%MOD*(n-i+1))%MOD;
        printf("%I64d\n",ans);
    }
    return 0;
}

