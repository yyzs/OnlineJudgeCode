#include "stdio.h"
#include "math.h"
int main()
{long long n;
 int t;
 scanf("%d",&t);
 while(t--)
 {scanf("%I64d",&n);
  printf("%I64d\n",(int)pow(2.0,(double)n)-1);
  }
  return 0;
}

