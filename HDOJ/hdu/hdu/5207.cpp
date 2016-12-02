#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 100010
using namespace std;
int cnt[MAX],a[MAX];
int main()
{
    int ans=1,t,cas=0,i,j,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<n;i++)
            {scanf("%d",&a[i]);
             for(j=1;j*j<=a[i];j++)
             {
                 if(a[i]%j!=0)
                    continue;
                 cnt[j]++;
                 if(j*j!=i)
                    cnt[a[i]/j]++;
             }
            }
       ans=1;
       for(i=2;i<=MAX-10;i++)
            if(cnt[i]>=2)
                ans=i;
       cas++;
       printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}

