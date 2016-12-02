#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MOD  200907
using namespace std;
long long mod(long long a,long long b,long long c)
{
     long long ans=1;
     a%=c;
     while(b)
     {
         if(b&1)
              ans=(ans*a)%c;
         a=(a*a)%c;
         b/=2;
     }
     return ans;
}
int main()
{
    long long  a,b,c,k,q;
    int t;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&k);
       if(b-a==c-b)
       {
           long long d=b-a;
           printf("%I64d\n",(a%MOD+((k-1)%MOD)*(d%MOD))%MOD);
       }
       else
       {
           q=b/a;
           if(q==1)
                 printf("%I64d\n",((k%MOD)*(a%MOD))%MOD);
           else
           {
               long long ans=mod(q,k-1,MOD);
               printf("%I64d\n",((a%MOD)*ans)%MOD);
           }
       }
    }
    return 0;
}

