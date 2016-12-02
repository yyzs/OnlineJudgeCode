#include "stdio.h"
#include "string.h"
#include "map"
#define MOD 1000000007
using namespace std;
map<int,int> mp;
int phi(int n)
{
    int i,mul,nn;
    if(n==1)   return 1;
    if(mp.find(n)!=mp.end())
             return mp[n];
    for(i=2;i*i<=n;i++)
            if(n%i==0)
        {
            nn=n;
            nn/=i;
            mul=(i-1);
            while(nn%i==0)
            {
                nn/=i;
                mul*=i;
            }
           mp[n]=phi(nn)*mul;
           return phi(nn)*mul;
        }
    mp[n]=n-1;
    return n-1;
}
int main()
{
    int n,k;
    long long ans;
    int i;
    mp.clear();
    while(scanf("%d%d",&n,&k)==2)
    {
        if(n==1){
            printf("1\n");
            continue;
        }
        if(k>2){
            printf("0\n");
            continue;
        }
        if(k==2){
            printf("1\n");
            continue;
        }
        ans=0;
        for(i=1;i*i<=n;i++){
             if(n%i==0)
             {
                int  temp=n/i;
                ans+=(long long)phi(i)*phi(temp)%MOD;
                ans%=MOD;
                if(temp!=i)
                {
                    ans+=(long long)phi(i)*phi(temp)%MOD;
                    ans%=MOD;
                }
             }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

