#include "stdio.h"
int main()
{int a1,b1,c1,a2,b2,c2,n,a,b,c,k,m;
 scanf("%d",&n);
 while(scanf("%d %d %d %d %d %d",&a1,&b1,&c1,&a2,&b2,&c2)!=EOF)
  {k=(c1+c2)/60;
   c=(c1+c2)%60;
   m=(b1+b2+k)/60;
   b=(b1+b2+k)%60;
   a=a1+a2+m;
   printf("%d %d %d\n",a,b,c);
   }
   return 0;
}
