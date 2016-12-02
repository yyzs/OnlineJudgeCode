#include "stdio.h"
int main()
{double a,b;
 double sum=0;
 char c[100];
 while(scanf("%s",c)!=EOF)
  {scanf("%lf%lf",&a,&b);
   sum+=a*b;
   }
  printf("%.1lf\n",sum);
  return 0;
  }

