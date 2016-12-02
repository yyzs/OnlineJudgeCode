#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "stdlib.h"
#define MAX 100010
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
struct node
{
    int beg,end,id;
    int h;
}que[MAX];
struct node2
{
    int w;
    int id;
}node2[MAX];
int n,m,num;
int ans[MAX<<2],sum[MAX<<2];

void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&sum[rt]);
        node2[num].w=sum[rt];
        node2[num].id=num;
        num++;
        sum[rt]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int x,int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]=0;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)
        update(x,lson);
    if(x>mid)
        update(x,rson);
    pushup(rt);
}

int query(int L,int R,int l,int r,int rt)
{
    if(l>=L&&r<=R)
          return sum[rt];
    int mid=(l+r)>>1;
    int res=0;
    if(L<=mid)
          res+=query(L,R,lson);
    if(R>mid)
          res+=query(L,R,rson);
    return res;
}

void slove()
{
    int i,temp=1;
    memset(ans,0,sizeof(ans));
    for(i=1;i<=n;i++)
    {
            while((que[temp].h>=node2[i].w)&&temp<=m)
            {
                ans[que[temp].id]=query(que[temp].beg+1,que[temp].end+1,1,n,1);
                temp++;
            }
            if(temp>m)
                break;
            if(node2[i].w>que[temp].h)
               update(node2[i].id,1,n,1);
    }
}

void print()
{
    int i;
    for(i=1;i<=m;i++)
        printf("%d\n",ans[i]);
}

int cmp2(struct node2 a,struct node2 b)
{
    return a.w>b.w;
}
int cmp1(struct node a,struct node b)
{
    return a.h>b.h;
}

int main()
{
    int t,cas=0,i;
    scanf("%d",&t);
    while(t--)
    {
        num=1;
        scanf("%d%d",&n,&m);
        build(1,n,1);
        sort(node2+1,node2+1+n,cmp2);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&que[i].beg,&que[i].end,&que[i].h);
            que[i].id=i;
        }
        sort(que+1,que+1+m,cmp1);
        slove();
        cas++;
        printf("Case %d:\n",cas);
        print();
    }
    return 0;
}

