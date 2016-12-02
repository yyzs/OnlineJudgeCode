#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
int a[20010];
int main()
{int n,m,i,j;
  while(scanf("%d%d",&n,&m)==2)
  {for(i=0;i<n;i++)
             scanf("%d",&a[i]);
    for(i=n;i<n+m;i++)
             scanf("%d",&a[i]);
    sort(a,a+n+m);
    for(i=0;i<n+m;i++)
              {if(i==0)
                         {printf("%d",a[i]);
                           continue;
                           }
                if(a[i]!=a[i-1])
                            printf(" %d",a[i]);
                }
      printf("\n");
    }
    return 0;
}

