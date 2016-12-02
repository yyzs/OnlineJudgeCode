#include "stdio.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"
int prime(long long  n)
{
    long long  i;
    if(n==1)
        return 0;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
           return 0;
    }
    return 1;
}
int main()
{
    int ok;
    long long  i,j;
    long long n,max=0;
    while(scanf("%I64d",&n)==1)
    {
        ok=0;
        max=0;
        for(i=1;i*i<=n;i++)
        {
           // printf("%I64d\n",n/i);
            if(prime(n/i)&&(n%i==0))
                {ok=1;break;}
            if(prime(i)&&n%i==0)
                max=i;
        }
        if(ok)
            printf("%I64d\n",i);
        else
          if(max!=0)
            printf("%I64d\n",n/max);
        else
            puts("0");
    }
    return 0;
}

