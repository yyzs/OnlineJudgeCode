#include "stdio.h"
#include "string.h"
#define MAX 100010
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
int sum[MAX<<2];
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&sum[rt]);
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(l>=L&&r<=R)
    {
        sum[rt]+=c;
        return;
    }
    int mid=(l+r)>>1;
    if(L<=mid)
         update(L,R,c,lson);
    if(R>mid)
         update(L,R,c,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(l>=L&&r<=R)
        return sum[rt];
    int ans=0;
    int mid=(l+r)>>1;
    if(L<=mid)
        ans+=query(L,R,lson);
    if(R>mid)
        ans+=query(L,R,rson);
    return ans;
}
int main()
{
    int t,n,i,j;
    int a,b;
    int cas=0;
    scanf("%d",&t);
    while(t--)
    {
        cas++;
        printf("Case %d:\n",cas);
        scanf("%d",&n);
        build(1,n,1);
        char s[10];
        while(scanf("%s",s))
        {
            if(strcmp(s,"End")==0)
                   break;
            if(s[0]=='A')
            {
                   scanf("%d%d",&a,&b);
                   update(a,a,b,1,n,1);
            }
            else
              if(s[0]=='S')
            {
                scanf("%d%d",&a,&b);
                update(a,a,-b,1,n,1);
            }
            else
            {
                scanf("%d%d",&a,&b);
                printf("%d\n",query(a,b,1,n,1));
            }
        }
    }
    return 0;
}

