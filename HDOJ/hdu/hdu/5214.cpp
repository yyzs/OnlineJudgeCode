#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 10000010
#define MOD 4294967296
using namespace std;
unsigned int  L[MAX],R[MAX];
int main()
{
    unsigned int a,b,c,d;
    unsigned int  n,ok;
    int  i,j;
    unsigned  l,r;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%u%u%u%u%u%u",&n,&L[1],&R[1],&a,&b,&c,&d);
        l=min(L[1],R[1]);
        r=max(L[1],R[1]);
        for(i=2; i<=n; i++)
        {
            L[i]=(L[i-1]*a+b)%MOD;
            R[i]=(R[i-1]*c+d)%MOD;
        }
        for(i=1;i<=n;i++)
        {
            if(L[i]>R[i])
                swap(L[i],R[i]);
            if(L[i]>l)
                l=L[i];
            if(R[i]<r)
                r=R[i];
        }
        ok=0;
        for(i=1; i<=n; i++)
        {
            if(L[i]>r&&R[i]<l)
            {
                ok=1;
                break;
            }
        }
        if(ok)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}

