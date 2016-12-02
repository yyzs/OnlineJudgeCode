#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
long long gcd(long long a,long long b)
{
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
int main()
{
    int n,i,m,t,x,cas=0;
    long long ans,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ans=1;
        for(i=0;;i++)
        {
            if(ans>=n)
                break;
            ans*=m;
        }
        x=i;
        a=1;
        b=(long long)n;
        for(i=1;i<=x;i++)
            a*=m;
        a*=x;
        long long temp=gcd(a,b);
        a/=temp;
        b/=temp;
        cas++;
        printf("Case %d: %I64d/%I64d\n",cas,a,b);
    }
    return 0;
}

