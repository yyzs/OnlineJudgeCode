#include <algorithm>
#include <cstring>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <time.h>
#define maxn 1005
#define maxm 40005
#define LL long long
#define mod 1000000007
#define INF 999999999
#define lowbit(x) (x&(-x))
#define mp mark_pair
#define ls o<<1

LL phi(LL n)
{
    LL ans = n;
    for(int i = 2; i * i <= n; i++)
        if(n%i == 0) {
            ans -= ans / i;
            while(n%i == 0) n/=i;
        }
    if(n > 1) ans -= ans / n;
    return ans;
}
int main(void)
{
    LL ans, n;
    while(scanf("%I64d", &n), n ) {
        ans = (n-1) * n / 2;
        ans -= phi(n) * n /2;
        printf("%I64d\n", ans%mod);
    }
    return 0;
}

