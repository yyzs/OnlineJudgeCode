#include "stdio.h"
main()
{double a;
 while(scanf("%lf\n",&a)!=EOF)
  if(a<0) printf("%.2lf\n",-a);
   else   printf("%.2lf\n",a);
  return 0;
}  
