#include "stdio.h"
#include "math.h"
int main()
{double x1,y1,x2,y2;
 int t;
 scanf("%d",&t);
 while(t--)
 {
      scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
      printf("%.1f\n",sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
}
 return 0;
}

