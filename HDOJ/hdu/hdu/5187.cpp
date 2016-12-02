#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
long long multi(long long a,long long b,long long c)
{
    long long res=0;
    while(b)
    {
        if(b&1)
            {res+=a;
             res%=c;
            }
        a+=a;
        a%=c;
        b/=2;
    }
    return res;
}
long long solve(long long a,long long b,long long c)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
            ans=multi(ans,a,c);
        a=multi(a,a,c);
        b/=2;
    }
    return ans;
}
int main()
{
    int i,j;
    long long n,p;
    while(scanf("%I64d%I64d",&n,&p)==2)
    {
        if(n==1)
        {
            printf("%I64d\n",1%p);
            continue;
        }
        long long res=(solve(2,n,p)-2)%p;
        while(res<0)
            res+=p;
        printf("%I64d\n",res);
    }
    return 0;
}

