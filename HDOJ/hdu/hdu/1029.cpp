#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[999999];
int main()
{
    int n,ans,i;
    while(scanf("%d",&n)==1)
    {
        ans=(n+1)/2;
        for(i=0;i<n;i++)
           scanf("%d",&a[i]);
        sort(a,a+n);
        printf("%d\n",a[ans-1]);
    }
    return 0;
}
