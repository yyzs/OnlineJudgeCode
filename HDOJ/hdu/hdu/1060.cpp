#include "stdio.h"
#include "math.h"
int main()
{
   long long n,t;
   double a,x;
   scanf("%I64d",&t);
   while(t--)
   {
       scanf("%I64d",&n);
       x=n*log10((double)n);
       x=x-(long long)x;
       a=pow(10.0,x);
       printf("%I64d\n",(long long)a);
   }
   return 0;
}

