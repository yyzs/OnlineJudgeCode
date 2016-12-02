#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 100010
#define LL long long
using namespace std;
LL a[MAX],bin[63];
inline LL read()
{
    LL x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
int n,m,tot,zero;
void print()
{
        for(int i=1;i<=n;i++)
                printf("%lld\n",a[i]);
}
void gauss()
{
        tot=zero=0;
        for(LL i=bin[60];i;i/=2)
        {
                int j=tot+1;
                while(!(i&a[j])&&j<=n)
                        j++;
                if(j==n+1)
                        continue;
                tot++;
                swap(a[tot],a[j]);
                for(int k=1;k<=n;k++)
                {
                        if(k!=tot&&(a[k]&i))
                                a[k]^=a[tot];
                }
        }
        if(tot!=n)
                zero=1;
       // print();
}
LL query(LL x)
{
        LL ans=0;
        x-=zero;
        if(!x)
                return 0;
        if(x>=bin[tot])
                return -1;
        for(int i=1;i<=tot;i++)
                if((x&bin[tot-i]))
                        ans^=a[i];
        return ans;
}
int main()
{
    int t;
    int cas=0;
    LL k1;
    scanf("%d",&t);
    bin[0]=1;
    for(int i=1; i<=60; i++)
        bin[i]=(bin[i-1]<<1);
    while(t--)
    {
        cas++;
        printf("Case #%d:\n",cas);
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            a[i]=read();
        gauss();
        scanf("%d",&m);
        while(m--)
        {
                k1=read();
                printf("%lld\n",query(k1));
        }
    }
    return 0;
}

