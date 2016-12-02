#define PI 3.1415927
#include "stdio.h"
int main()
{double r,v;
 while(scanf("%lf",&r)!=EOF)
  {v=PI*r*r*r*4/3;
   printf("%.3lf\n",v);
   }
  return 0;
 }
