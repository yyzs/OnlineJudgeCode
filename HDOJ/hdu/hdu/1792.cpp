#include "stdio.h"
#include "string.h"
int main()
{int n,a,b;
 while(scanf("%d%d",&a,&b)==2)
 {n=a*b-a-b;
  printf("%d %d\n",n,(a-1)*(b-1)/2);
  }
  return 0;
}

