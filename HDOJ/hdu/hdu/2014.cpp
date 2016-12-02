#include "stdio.h"
main()
{double max,min,a,sum;
 int n,i;
 while(scanf("%d",&n)!=EOF)
  {
      max=0;
      min=100;
      sum=0;
      for(i=1;i<=n;i++)
       {
           scanf("%lf",&a);
           sum+=a;
           if(a>=max) max=a;
           if(a<=min) min=a;
       }
       printf("%.2lf\n",(sum-max-min)/(n-2));
   }
   return 0;
}

