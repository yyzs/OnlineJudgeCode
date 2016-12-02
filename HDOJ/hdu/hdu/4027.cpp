#include "stdio.h"
#include "string.h"
#include "math.h"
#include "algorithm"
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define MAX 100010
using namespace std;
long long sum[MAX<<2];
void push_up(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%I64d",&sum[rt]);
        return;
    }
    int m=(l+r)/2;
    build(lson);
    build(rson);
    push_up(rt);
}
long long query(int L,int R,int l,int r,int rt)
{
    if(l>=L&&r<=R)
    {
        return sum[rt];
    }
    int m=(l+r)/2;
    long long ans=0;
    if(L<=m)
        ans+=query(L,R,lson);
    if(R>m)
        ans+=query(L,R,rson);
    return ans;
}
void update(int L,int R,int l,int r,int rt)
{
    if(sum[rt]==r-l+1)
        return;
    if(l==r)
    {
        sum[rt]=(long long)sqrt(double(sum[rt]));
        return;
    }
    int m=(l+r)/2;
    if(L<=m)
        update(L,R,lson);
    if(R>m)
        update(L,R,rson);
    push_up(rt);
}
int main()
{
    int n,m,t,x,y;
    int cas=0;
    while(scanf("%d",&n)==1)
    {
        cas++;
        printf("Case #%d:\n",cas);
        build(1,n,1);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d",&t,&x,&y);
            if(x>y)
                swap(x,y);
            if(t==1)
                printf("%I64d\n",query(x,y,1,n,1));
            else
            {
                        update(x,y,1,n,1);
            }
        }
        printf("\n");
    }
    return 0;
}

