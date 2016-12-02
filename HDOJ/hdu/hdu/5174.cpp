#include "stdio.h"
#include "string.h"
#define INT_MAX 2147483647
#define MAX 110
#include "map"
#include "algorithm"
using namespace std;
long long val[MAX];
int has[MAX];
map<long long,int> MP;
int check(long long a,long long b,long long c)
{
    if((a+b)%INT_MAX==c)
        return 1;
    return 0;
}
int main()
{
    int n,ans;
    int i,j,k,len;
    int cas=0;
    while(scanf("%d",&n)==1)
    {
        MP.clear();
        for(i=0; i<n; i++)
            {scanf("%I64d",&val[i]);
             MP[val[i]]++;
            }
        cas++;
        ans=0;
        sort(val,val+n);
        len=unique(val,val+n)-val;
        val[len]=val[0];
        for(i=0;i<len;i++)
        {
            if(i==0)
            {
                ans=ans+check(val[len-1],val[i],val[i+1])*MP[val[i]];
            }
            else
            {
                ans=ans+check(val[i-1],val[i],val[i+1])*MP[val[i]];
            }
        }
        printf("Case #%d: %d\n",cas,len==1?-1:ans);
    }
    return 0;
}

