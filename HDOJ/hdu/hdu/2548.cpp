#include "stdio.h"
#include "string.h"
int main()
{double u,v,w,l,t;
 int d;
 scanf("%d",&d);
 while(d--)
 {scanf("%lf%lf%lf%lf",&u,&v,&w,&l);
  t=l/(u+v);
  printf("%.3f\n",t*w);
  }
  return 0;
}

