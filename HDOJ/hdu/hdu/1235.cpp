#include "stdio.h"
#include "string.h"
int a[1010];
int main()
{int x,i,j,ans,n;
  while(scanf("%d",&n)==1&&n)
  {for(i=0;i<n;i++)
           scanf("%d",&a[i]);
    scanf("%d",&x);
    ans=0;
    for(i=0;i<n;i++)
            if(x==a[i])
                 ans++;
    printf("%d\n",ans);
    }
    return 0;
}

