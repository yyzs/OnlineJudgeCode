#include "stdio.h"
#include "algorithm"
#define MAX 1010
#define INF 1e9
using namespace std;
struct node
{
    int l,r;
    long long ans;
}node[MAX];
long long a[MAX];
long long gcd(long long a,long long b)
{
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    int g=gcd(a,b);
    return  a*b/g;
}
int main()
{
    int t,n,i,j,q;
    int ok;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(i=1; i<=1000; i++)
            a[i]=1;
        ok=1;
        for(i=0;i<q;i++)
        {
            scanf("%d%d%I64d",&node[i].l,&node[i].r,&node[i].ans);
            for(j=node[i].l; j<=node[i].r; j++)
            {
                a[j]=lcm(a[j],node[i].ans);
                if(a[j]>INF)
                    ok=0;
            }
        }
        for(i=0;i<q;i++)
        {
            long long temp=a[node[i].l];
            for(j=node[i].l+1; j<=node[i].r; j++)
                temp=gcd(temp,a[j]);
            if(temp!=node[i].ans)
                ok=0;
        }
        if(!ok)
            puts("Stupid BrotherK!");
        else
        {
            for(i=1; i<=n; i++)
            {
                if(i==1)
                    printf("%I64d",a[i]);
                else
                    printf(" %I64d",a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

