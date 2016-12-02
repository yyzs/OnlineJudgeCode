#include "stdio.h"
#include "math.h"
int main()
{int a,b,k,i;
  int temp;
  while(scanf("%d%d%d",&a,&b,&k)==3)
  {if(a==0&&b==0)
              break;
    temp=1;
    for(i=1;i<=k;i++)
              temp*=10;
    if(a%temp==b%temp)
              {printf("-1\n");
                continue;
                }
    printf("%d\n",a+b);
    }
    return 0;
}

