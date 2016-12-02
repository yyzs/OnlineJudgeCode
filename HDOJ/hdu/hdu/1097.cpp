#include "stdio.h"
int mod(int a,int b,int c)
{
   a%=c;
   int ans=1;
   while(b)
   {
       if(b%2)
       {
           ans=(ans*a)%c;
       }
       b/=2;
       a=a*a%c;
   }
    return ans;
}
int main()
{
    int a,b,c;
    while(scanf("%d%d",&a,&b)==2)
    {
        c=mod(a,b,10);
        printf("%d\n",c);
    }
    return 0;
}

