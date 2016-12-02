#include "stdio.h"
#include "string.h"
#define MAX 100010
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int sum[MAX<<2],col[MAX<<2];
int n,m;
void pushup(int rt)
{
       sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
      sum[rt]=1;
      col[rt]=0;
      if(l==r)
              return;
      int m=(l+r)>>1;
      build(lson);
      build(rson);
      pushup(rt);
}
void pushdown(int rt,int m)
{
     if(col[rt])
     {
         col[rt<<1]=col[rt<<1|1]=col[rt];
         sum[rt<<1]=(m-(m>>1))*col[rt];
         sum[rt<<1|1]=(m>>1)*col[rt];
         col[rt]=0;
     }
}
void update(int L,int R,int x,int l,int r,int rt)
{
    if(l>=L&&r<=R)
            {col[rt]=x;
              sum[rt]=(r-l+1)*x;
              return ;
            }
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m)
          update(L,R,x,lson);
    if(R>m)
          update(L,R,x,rson);
    pushup(rt);
}
int main()
{
    int i;
    int t;
    int x,y,z;
    int cas=0;
    scanf("%d",&t);
    while(t--)
    {
        cas++;
        scanf("%d",&n);
        build(1,n,1);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&z);
            update(x,y,z,1,n,1);
              // printf("%d\n",sum[1]);
        }
         printf("Case %d: The total value of the hook is %d.\n",cas , sum[1]);
    }
    return 0;
}

