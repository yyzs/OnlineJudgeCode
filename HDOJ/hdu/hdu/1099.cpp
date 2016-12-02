#include "stdio.h"
#include "string.h"
long long gcd(long long  a,long long  b)
{
    if(a%b==0)
         return b;
    return gcd(b,a%b);
}
int len(long long n)
{
    int ans=0;
    while(n)
    {
        ans++;
        n/=10;
    }
    return ans;
}
int main()
{
    long long  n,d;
    long long  i,m,s,temp;
    int l1,l2,l;
    while(scanf("%I64d",&n)==1)
    {
        m=1;
        s=1;
        for(i=2;i<=n;i++)
        {
            temp=m;
            m=m/gcd(m,i)*i;
            s=s*(m/temp)+m/i;
            temp=gcd(s,m);
            s/=temp;
            m/=temp;
        }
        s*=n;
        temp=gcd(s,m);
        s/=temp;
        m/=temp;
        if(s%m==0)
        {
            printf("%I64d\n",s/m);
            continue;
        }
        d=s/m;
        s=s%m;
        l1=len(s);
        l2=len(m);
        l=l1>l2?l1:l2;
        l1=len(d);
        for(i=0;i<=l1;i++)
            printf(" ");
        printf("%I64d\n",s);
        printf("%I64d ",d);
        for(i=1;i<=l;i++)
            printf("-");
        printf("\n");
         for(i=0;i<=l1;i++)
            printf(" ");
        printf("%I64d\n",m);
    }
    return 0;
}

