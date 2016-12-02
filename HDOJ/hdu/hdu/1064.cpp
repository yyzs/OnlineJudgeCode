#include "stdio.h"
int main()
{double a,i,s;
 for(i=0;i<12;i++)
 {scanf("%lf",&a);
  s+=a;
  }
  printf("$%.2lf\n",s/12);
  return 0;
  }

