#include "stdio.h"
#include "string.h"
#include "algorithm"
#define ll long long
using namespace std;
/*
void exgcd(ll a,ll b,ll &d,ll &x,ll &y){
    if (!b) d=a,x=1,y=0;
    else{
        exgcd(b,a%b,d,y,x);
        y-=a/b*x;
    }
}                    //找出一对整数(x,y)使得ax+by=gcd(a,b)，参数d为gcd(a,b)
bool LinePro(ll a,ll b,ll c，ll& x0,ll& y0,ll& a0,ll & b0){
    ll d;
    exgcd(a,b,d,x0,y0);
    if (c%d) return false;
    a0=a/d; b0=b/d; x0*=c/d; y0*=c/d;
    return true;
}*/
ll mod(ll a,ll b,ll c)
{
        ll ans=1;
        while(b)
        {
                if(b&1)
                        ans=ans*a%c;
                a=a*a%c;
                b/=2;
        }
        return ans;
}
int main()
{
        int cas=0;
        ll C,k1,b1,k2;
        ll A;
        ll a,b;
        while(scanf("%I64d%I64d%I64d%I64d",&C,&k1,&b1,&k2)==4)
        {
                cas++;
                printf("Case #%d:\n",cas);
                int temp=0;
                for(a=1;a<C;a++)
                {
                        A=mod(a,k1+b1,C);
                        b=C-A;
                        if(b>=1&&b<C&&(mod(a,k1*2+b1,C)+mod(b,k2*2-k2+1,C))%C==0)
                                {temp=1;printf("%I64d %I64d\n",a,b);}
                }
                if(!temp)
                        puts("-1");
        }
        return 0;
}

