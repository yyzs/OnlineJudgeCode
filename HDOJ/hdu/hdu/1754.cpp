#include "stdio.h"
#include "string.h"
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define MAX 200010
int max[MAX<<2];
int big(int a,int b)
{
    return a>b?a:b;
}
void pushup(int rt)
{
    max[rt]=big(max[rt<<1],max[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&max[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int a,int x,int l,int r,int rt)
{
    if(l==r)
    {
        max[rt]=x;
        return;
    }
    int m=(l+r)>>1;
    if(a<=m)
        update(a,x,lson);
    else
        update(a,x,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(l>=L&&r<=R)
    {
        return max[rt];
    }
    int ans=0;
    int m=(l+r)>>1;
    if(L<=m)
        ans=big(ans,query(L,R,lson));
    if(R>m)
        ans=big(ans,query(L,R,rson));
    return ans;
}
int main()
{
    int n,i,j,m;
    int a,b;
    char s[10];
    while(scanf("%d%d",&n,&m)==2)
    {
        build(1,n,1);
        while(m--)
        {
            scanf("%s",s);
            scanf("%d%d",&a,&b);
            if(s[0]=='U')
                update(a,b,1,n,1);
            else
                printf("%d\n",query(a,b,1,n,1));
        }
    }
    return 0;
}

