#include "stdio.h"
int prime(long long p)
{
    long long i;
    int ok=1;
    if(p==2)
                 return 1;
   for(i=2;i*i<=p;i++)
                if(p%i==0)
                {
                    ok=0;
                    break;
                }
    return ok;
}
long long  mod(long long a,long long b,long long c)
{
    long long ans=1;
    a%=c;
    while(b)
    {
        if(b%2==1)
              ans=ans*a%c;
       b/=2;
       a=a*a%c;
    }
    return ans;
}
int main()
{
    long long a,p,d;
    while(scanf("%I64d%I64d",&p,&a)==2)
    {
        if(a==0&&p==0)
                break;
        d=a;
        if(mod(a,p,p)==d&&!prime(p))
                            printf("yes\n");
        else
                            printf("no\n");
    }
    return 0;
}

