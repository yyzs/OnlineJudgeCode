#include "stdio.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"
    int a[100010];
int main()
{
    int t;
    int ok,i,n;
    int cas=0;
    scanf("%d",&t);
    while(t--)
    {
        cas++;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
              scanf("%d",&a[i]);
        ok=1;
        for(i=1;i<=n;i++)
        {
            if(i==1)
               { if(a[i]>3)
                      ok=0;
                  continue;
               }
            else
                if(abs(a[i]-a[i-1])>3||(a[i]==a[i-1]&&a[i]!=1))
                    ok=0;
        }
        int ans=0;
        if(!ok)
            {
                printf("Case #%d: %d\n",cas,ans);
                continue;
            }
        ans=1;
        for(i=1;i<=n;i++)
            {
                if(a[i]==1&&a[i-1]==2)
                       ans++;
                if(a[i]==2&&a[i-1]==1)
                       ans++;
            }
        if(a[n]>0)
             ans*=2;
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}

