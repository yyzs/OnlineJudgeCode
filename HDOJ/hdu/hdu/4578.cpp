#include "stdio.h"
#include "algorithm"
#include "string.h"
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define MAX 100010
#define mod 10007
using namespace std;
int col[4][MAX<<2];
long long sum[4][MAX<<2];
void push_up(int rt)
{
    sum[1][rt]=(sum[1][rt<<1]%mod+sum[1][rt<<1|1]%mod)%mod;
    sum[2][rt]=(sum[2][rt<<1]%mod+sum[2][rt<<1|1]%mod)%mod;
    sum[3][rt]=(sum[3][rt<<1]%mod+sum[3][rt<<1|1]%mod)%mod;
}
void push_down(int rt, int L, int R)
{
    int mid=(R+L)>>1;
    if(col[3][rt])
    {
        sum[1][rt<<1]=(mid-L+1)*col[3][rt]%mod;
        sum[1][rt<<1 | 1]=(R-mid)*col[3][rt]%mod;
        sum[2][rt<<1]=(mid-L+1)*col[3][rt]%mod*col[3][rt]%mod;
        sum[2][rt<<1 | 1]=(R-mid)*col[3][rt]%mod*col[3][rt]%mod;
        sum[3][rt<<1]=(mid-L+1)*col[3][rt]%mod*col[3][rt]%mod*col[3][rt]%mod;
        sum[3][rt<<1 | 1]=(R-mid)*col[3][rt]%mod*col[3][rt]%mod*col[3][rt]%mod;
        col[3][rt<<1]=col[3][rt<<1 | 1]=col[3][rt];
        col[1][rt<<1]=col[1][rt<<1 | 1]=col[2][rt<<1]=col[2][rt<<1 | 1]=col[3][rt]=0;
    }
    if(col[2][rt])
    {
        sum[1][rt<<1]=sum[1][rt<<1]*col[2][rt]%mod;
        sum[1][rt<<1 | 1]=sum[1][rt<<1 | 1]*col[2][rt]%mod;
        sum[2][rt<<1]=sum[2][rt<<1]*col[2][rt]%mod*col[2][rt]%mod;
        sum[2][rt<<1 | 1]=sum[2][rt<<1 | 1]*col[2][rt]%mod*col[2][rt]%mod;
        sum[3][rt<<1]=sum[3][rt<<1]*col[2][rt]%mod*col[2][rt]%mod*col[2][rt]%mod;
        sum[3][rt<<1 | 1]=sum[3][rt<<1 | 1]*col[2][rt]%mod*col[2][rt]%mod*col[2][rt]%mod;
        col[1][rt<<1]=col[1][rt<<1]*col[2][rt]%mod;
        col[1][rt<<1 | 1]=col[1][rt<<1 | 1]*col[2][rt]%mod;
        if(col[2][rt<<1]) col[2][rt<<1]=col[2][rt<<1]*col[2][rt]%mod;
        else col[2][rt<<1]=col[2][rt];
        if(col[2][rt<<1 | 1]) col[2][rt<<1 | 1]=col[2][rt<<1 | 1]*col[2][rt]%mod;
        else col[2][rt<<1 | 1]=col[2][rt];
        col[2][rt]=0;
    }
    if(col[1][rt])
    {
        sum[3][rt<<1]=(sum[3][rt<<1]+3*sum[2][rt<<1]*col[1][rt]%mod+3*sum[1][rt<<1]*col[1][rt]%mod*col[1][rt]%mod+col[1][rt]*col[1][rt]%mod*col[1][rt]%mod*(mid-L+1)%mod)%mod;
        sum[3][rt<<1 | 1]=(sum[3][rt<<1 | 1]+3*sum[2][rt<<1 | 1]*col[1][rt]%mod+3*sum[1][rt<<1 | 1]*col[1][rt]%mod*col[1][rt]%mod+col[1][rt]*col[1][rt]%mod*col[1][rt]%mod*(R-mid)%mod)%mod;
        sum[2][rt<<1]=(sum[2][rt<<1]+2*col[1][rt]*sum[1][rt<<1]%mod+col[1][rt]*col[1][rt]%mod*(mid-L+1)%mod)%mod;
        sum[2][rt<<1 | 1]=(sum[2][rt<<1 | 1]+2*col[1][rt]*sum[1][rt<<1 | 1]%mod+col[1][rt]*col[1][rt]%mod*(R-mid)%mod)%mod;
        sum[1][rt<<1]=(sum[1][rt<<1]+(mid-L+1)*col[1][rt]%mod)%mod;
        sum[1][rt<<1 | 1]=(sum[1][rt<<1 | 1]+(R-mid)*col[1][rt]%mod)%mod;
        col[1][rt<<1]=(col[1][rt<<1]+col[1][rt])%mod;
        col[1][rt<<1 | 1]=(col[1][rt<<1 | 1]+col[1][rt])%mod;
        col[1][rt]=0;
    }
}
void update(int L,int R,int a,int c,int l,int r,int rt)
{
    if(l>=L&&r<=R)
    {
        if(a==3)
        {
            sum[1][rt]=(r-l+1)*c%mod;
            sum[2][rt]=(r-l+1)*c%mod*c%mod;
            sum[3][rt]=(r-l+1)*c%mod*c%mod*c%mod;
            col[1][rt]=col[2][rt]=0;
            col[3][rt]=c;
        }
        if(a==2)
        {
            sum[1][rt]=sum[1][rt]*c%mod;
            sum[2][rt]=sum[2][rt]*c%mod*c%mod;
            sum[3][rt]=sum[3][rt]*c%mod*c%mod*c%mod;
            col[1][rt]=col[1][rt]*c%mod;
            if(col[2][rt])  col[2][rt]=col[2][rt]*c%mod;
            else col[2][rt]=c;
        }
        if(a==1)
        {
            sum[3][rt]=(sum[3][rt]+3*sum[2][rt]%mod*c%mod+3*sum[1][rt]*c%mod*c%mod+c*c%mod*c%mod*(r-l+1)%mod)%mod;
            sum[2][rt]=(sum[2][rt]+2*sum[1][rt]*c%mod+c*c%mod*(r-l+1)%mod)%mod;
            sum[1][rt]=(sum[1][rt]+c*(r-l+1)%mod)%mod;
            col[1][rt]=(col[1][rt]+c)%mod;
        }
        return;
    }
    push_down(rt,l,r);
    int m=(l+r)/2;
    if(L<=m)
        update(L,R,a,c,lson);
    if(R>m)
        update(L,R,a,c,rson);
    push_up(rt);
}
long long query(int L,int R,int a,int l,int r,int rt)
{
        if(l>=L&&r<=R)
        {
                if(a==1)
                        return sum[1][rt];
                if(a==2)
                        return sum[2][rt];
                if(a==3)
                        return sum[3][rt];
        }
        long long ans=0;
        push_down(rt,l,r);
        int m=(l+r)/2;
        if(L<=m)
                ans=(ans%mod+query(L,R,a,lson)%mod)%mod;
        if(R>m)
                ans=(ans%mod+query(L,R,a,rson)%mod)%mod;
        return ans;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2,n+m)
    {
        memset(col,0,sizeof(col));
        memset(sum,0,sizeof(sum));
        while(m--)
        {
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(a!=4)
                update(b,c,a,d,1,n,1);
            else
                printf("%I64d\n",query(b,c,d,1,n,1));
        }
    }
    return 0;
}

