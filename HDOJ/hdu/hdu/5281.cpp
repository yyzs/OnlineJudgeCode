#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 100010
using namespace std;
int a[MAX],b[MAX];
int main()
{
    int n,m,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
           scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
           scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+m);
        long long ans=0;
        int j=n-1;
        for(int i=0;i<m;i++)
        {
             if(a[j]>=b[i])
                ans+=a[j]-b[i];
             else
                break;
             j--;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

