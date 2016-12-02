#include "stdio.h"
long long gcd(long long a,long long b)
{
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
long long c(long long n,long long m)
{
    long long p=1,q=1,i;
    for(i=n-m+1;i<=n;i++)
    {
        p=p*i;
    }
    for(i=1;i<=m;i++)
    {
        q=q*i;
    }
    return p/q;
}
int main()
{
    long long temp,n,m,p,q,i;
    while(scanf("%I64d%I64d",&n,&m)==2)
    {
        q=c(n+m,n);
        p=c(n+m-1,n)*n;
        temp=gcd(p,q);
        p/=temp;
        q/=temp;
        printf("%I64d/%I64d\n",p,q);
    }
    return 0;
}

