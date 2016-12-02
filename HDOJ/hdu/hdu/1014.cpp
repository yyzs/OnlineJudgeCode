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
    printf("%10d%10d    %s\n\n",a,b,gcd(a,b)==1? "Good Choice":"Bad Choice");
 return 0;
 }

