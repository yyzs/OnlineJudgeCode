#include  <cstdio>
#include <cstring>
#define MAX 100010
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#include <algorithm>
using namespace std;
char s[20];
long long  sum[MAX<<2];
long long  x[MAX];
struct node
{
    long long  w,id;
}node[MAX];
long long  max(long long  a,long long  b)
{
    return a>b?a:b;
}

void pushplus(long long  rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void build(long long  l,long long  r,long long  rt)
{
    sum[rt]=0;
    if(l==r)
        return;
    long long  m=(l+r)>>1;
    build(lson);
    build(rson);
    pushplus(rt);
}
void updata(long long  p,long long  add,long long  l,long long  r,long long  rt)
{
    if(l==r)
    {
        sum[rt]+=add;
        return;
    }
    long long  m=(l+r)>>1;
    if(p<=m)
          updata(p,add,lson);
    else
          updata(p,add,rson);
    pushplus(rt);
}
long long  query(long long  L,long long  R,long long  l,long long  r,long long  rt)
{
    long long  ans=0;
    if(L<=l&&r<=R)
            return sum[rt];
    long long  m=(l+r)>>1;
    if(L<=m)
           ans=ans+query(L,R,lson);
    if(R>m)
           ans=query(L,R,rson)+ans;
    return ans;
}
long long  cmp1(struct node a,struct node b)
{
    return a.w<b.w;
}
long long  cmp2(struct node a,struct node b)
{
    return a.id<b.id;
}
long long  ma(long long  a,long long  b)
{
    return  a>b?a:b;
}
int   main()
{
    long long  i,j;
    long long  n,k;
    long long  temp,now;
    long long  sum;
    while(scanf("%I64d%I64d",&n,&k)==2)
    {
        sum=0;
        build(1,n,1);
        for(i=1;i<=n;i++)
        {
            scanf("%I64d",&node[i].w);
            node[i].id=i;
        }
        sort(node+1,node+n+1,cmp1);
        temp=0;now=0;
        for(i=1;i<=n;i++)
        {
            if(i==1)
            {
                temp=node[i].w;
                node[i].w=1;
                continue;
            }
            now=node[i].w;
            if(node[i].w==temp)
                   node[i].w=node[i-1].w;
            else
                   node[i].w=node[i-1].w+1;
            temp=now;
        }
        sort(node+1,node+n+1,cmp2);
        for(i=1;i<=n;i++)
        {
            if(node[i].w+1<=n)
                  sum+=query(node[i].w+1,n,1,n,1);
            updata(node[i].w,1,1,n,1);
        }
        sum = ma(sum-k,0);
        printf("%I64d\n",sum);
    }
    return 0;
}


