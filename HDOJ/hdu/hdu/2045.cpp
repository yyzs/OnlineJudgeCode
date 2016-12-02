#include "stdio.h"
int main()
{int n,i;
 long long a[51];
 while(scanf("%d",&n)==1)
  {
      a[1]=3;
      a[2]=6;
      a[3]=6;
      for(i=4;i<=51;i++)
        a[i]=2*a[i-2]+a[i-1];
    printf("%I64d\n",a[n]);
  }
  return 0;
}
