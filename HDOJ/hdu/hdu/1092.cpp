#include "stdio.h"
main()
{int n,sum,a,i,j=0;
 while(1)
  {if(!j) {scanf("%d",&n);j=1;}
   else scanf("\n\n%d",&n);
   if(n==0) break;
   sum=0;
   for(i=1;i<=n;i++)
    {scanf(" %d",&a);
     sum+=a;
     }
   printf("%d\n",sum);
   }
   return 0;
 }
