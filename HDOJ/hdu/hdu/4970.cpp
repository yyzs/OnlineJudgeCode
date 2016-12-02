#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 100010
using namespace std;
long long ata[MAX],sum[MAX],a[MAX];
int main()
{
    int m,n;
    int i,j;
    int l,r,d;
    int ans;
    int k;
    long long h;
    int x;
    while(scanf("%d",&n)==1&&n)
    {
        memset(ata,0,sizeof(ata));
        memset(sum,0,sizeof(sum));
        memset(a,0,sizeof(a));
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d",&l,&r,&d);
            ata[l]+=d;
            ata[r+1]-=d;
        }
        for(i=1;i<=n;i++)
            a[i]=a[i-1]+ata[i];
        for(i=n;i>=1;i--)
            sum[i]=sum[i+1]+a[i];
        ans=0;
        scanf("%d",&k);
        while(k--)
        {
            scanf("%I64d%d",&h,&x);
            if(h>sum[x])
                  ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

