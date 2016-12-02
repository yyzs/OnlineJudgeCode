#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
int a[10010];
int main()
{int i,n,j,m,lef,now;
  int ans;
  while(scanf("%d%d",&n,&m)==2)
  {for(i=0;i<n;i++)
          scanf("%d",&a[i]);
    sort(a,a+n);
    ans=0;
    lef=m;
    for(i=0;i<n;i++)
            {if(lef-a[i]<0)
                        break;
              while(lef>=a[i])
              {lef-=a[i];
                ans++;
                }
             }
    printf("%d\n",ans);
    }
    return 0;
}

