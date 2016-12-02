#include "stdio.h"
#include "string.h"
#define MAX 200010
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int h,w,n;
int s[MAX<<2];
int max(int a,int b)
{
    return a>=b?a:b;
}
void pushup(int rt)
{
      s[rt]=max(s[rt<<1],s[rt<<1|1]);
}
void build(int l,int r,int rt)
{
       s[rt]=w;
       if(l==r)
             return;
       int m=(l+r)>>1;
       build(lson);
       build(rson);
       pushup(rt);
}
int query(int x,int l,int r,int rt)
{
    if(l==r)
    {
        s[rt]-=x;
        return l;
    }
    int m=(l+r)>>1;
    int ret = (s[rt<<1] >= x) ? query(x , lson) : query(x , rson);
    pushup(rt);
    return ret;
}
int main()
{
    int i,x;
    while(scanf("%d%d%d",&h,&w,&n)==3)
    {
        build(1,n,1);
        if(h>n)
               h=n;
        while(n--)
        {
               scanf("%d",&x);
               if(s[1]<x)
                         printf("-1\n");
               else
               {
                        printf("%d\n",query(x,1,h,1));
               }
        }
    }
    return 0;
}

