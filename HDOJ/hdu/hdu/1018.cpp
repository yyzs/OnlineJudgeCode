#include "stdio.h"
#include "math.h"
int main()
{int n,i;
 int t;
 double sum;
 scanf("%d",&t);
 while(t--)
 {scanf("%d",&n);
  sum=0;
  for(i=1;i<=n;i++)
    sum+=log10((double)i);
  printf("%d\n",(int)sum+1);
  }
  return 0;
  }

