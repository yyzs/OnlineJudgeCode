#include "stdio.h"
int gcd(int a,int b)
{if(a%b==0)
          return b;
 else
         return gcd(b,a%b);
}
int main()
{int a,b;
 while(scanf("%d%d",&a,&b)==2)
 {
        printf("%d\n",a*b/gcd(a,b));
 }
 return 0;
}

