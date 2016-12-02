#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 100010

long long  A[MAX];
long long  c[MAX];
long long d[MAX];

int Lowbit(int t)
{
    return t&(-t);
}

__int64 getSum(int n)
{
    __int64 sum=0;
    while(n>0)
    {
        sum+=c[n];
        n-=Lowbit(n);
    }
    return sum;
}

long long  getSumD(int n)
{
    __int64 sum=0;
    while(n>0)
    {
        sum+=d[n];
        n-=Lowbit(n);
    }
    return sum;
}

void Change(int i,int v,int n)
{
    while(i<=n)
    {
        c[i]+=1;
        d[i]+=v;
        i+=Lowbit(i);
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        long long ans=0;
        long long  sum=0;
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&A[i]);
            Change(A[i],A[i],n);
            sum+=A[i];
            ans+=((i-getSum(A[i]))*A[i]);
            ans+=(sum-getSumD(A[i]));
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
