#include "stdio.h"
#include "string.h"
#define MAX 5555
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

char s[20];
int sum[MAX<<2];
int x[MAX];

int min(int a,int b)
{
    return a<b?a:b;
}

void pushplus(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void build(int l,int r,int rt)
{
    sum[rt]=0;
    if(l==r)
        return;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushplus(rt);
}
void updata(int p,int add,int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]+=add;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m)
          updata(p,add,lson);
    else
          updata(p,add,rson);
    pushplus(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    int ans=0;
    if(L<=l&&r<=R)
            return sum[rt];
    int m=(l+r)>>1;
    if(L<=m)
           ans=ans+query(L,R,lson);
    if(R>m)
           ans=query(L,R,rson)+ans;
    return ans;
}
int main()
{
    int i,j;
    int n;
    int ret,sum;
    while(scanf("%d",&n)==1)
    {
        sum=0;
        build(0,n-1,1);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            sum+=query(x[i],n-1,0,n-1,1);
            updata(x[i],1,0,n-1,1);
        }
        ret=sum;
        for(i=0;i<n;i++)
        {
            sum+=n-x[i]-x[i]-1;
            ret=min(ret,sum);
        }
        printf("%d\n",ret);
    }
    return 0;
}

