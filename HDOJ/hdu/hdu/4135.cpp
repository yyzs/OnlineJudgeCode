#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "vector"
using namespace std;
long long solve (long long n, long long r)
{
    vector<int> p;
    for (long long i=2; i*i<=n; ++i)
        if (n % i == 0)
        {
            p.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        p.push_back (n);
    long long sum = 0;
    for (long long msk=1; msk<(1<<p.size()); ++msk)
    {
        long long mult = 1,
            bits = 0;
        for (long long i=0; i<(int)p.size(); ++i)
            if (msk & (1<<i))
            {
                ++bits;
                mult *= p[i];
            }
        long long cur = r / mult;
        if (bits % 2 == 1)
            sum += cur;
        else
            sum -= cur;
    }
    return r - sum;
}
int main()
{
    long long n,a,b;
    long long t,cas=0;
    long long ans1,ans2;
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d",&a,&b,&n);
        ans1=solve(n,a-1);
        ans2=solve(n,b);
        cas++;
        printf("Case #%I64d: %I64d\n",cas,ans2-ans1);
    }
    return 0;
}

