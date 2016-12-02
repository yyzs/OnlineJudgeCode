#include "stdio.h"
#include "string.h"
#define MAX 10000000
#include "algorithm"
int a[MAX];
using namespace std;
int main()
{
    int i;
    int x;
    int n;
    int ans=0;
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=0;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=n-1; i>0; i--)
            if(a[i]<a[i-1])
            {
                a[i]^=a[i-1]^=a[i]^=a[i-1];
                ans++;
            }
        cas++;
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}


