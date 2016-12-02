#include "stdio.h"
#include "string.h"
#include "algorithm"
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define MAXN 2222
using namespace std;
struct line
{
    double s,e,h,type;
}L[MAXN];
double tree[MAXN<<2];
int cnt[MAXN<<2];
double X[MAXN<<2];
bool cmp(line a,line b)
{
    return a.h<b.h;
}
void pushup(int num,int l,int r)
{
    if(cnt[num])  tree[num]=X[r+1]-X[l];
    else tree[num]=tree[num<<1]+tree[num<<1|1];
}
int bin(double tag,int top)
{
    int bo=0;
    int to=top-1;
    int mid;
    while(bo<=to)
    {
        mid=(bo+to)>>1;
        if(X[mid]==tag)  return mid;
        else if(X[mid]>tag) to=mid-1;
        else bo=mid+1;
    }
    return -1;
}
void update(int num,int s,int e,int l,int r,int val)
{
    if(l<=s && r>=e)
    {
        cnt[num]+=val;
        pushup(num,s,e);
        return;
    }
    int mid=(s+e)>>1;
    if(l<=mid) update(num<<1,s,mid,l,r,val);
    if(r>mid)  update(num<<1|1,mid+1,e,l,r,val);

    pushup(num,s,e);
}
int main()
{
    int n,cas=1;
    while(scanf("%d",&n)==1,n)
    {
        int m=0;
        while(n--)
        {
            double a,b,c,d;
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);//离散化
            X[m]=a;
            L[m].s=a;L[m].e=c;L[m].h=b;L[m++].type=1;
            X[m]=c;
            L[m].s=a;L[m].e=c;L[m].h=d;L[m++].type=-1;
        }
        sort(L,L+m,cmp);
        sort(X,X+m);

        int k=1;
        for(int i=1;i<m;i++)
             if(X[i]!=X[i-1])
                   X[k++]=X[i];
        memset(tree,0,sizeof(tree));
        memset(cnt,0,sizeof(cnt));
        double ans=0;
        for(int i=0;i<m-1;i++)
        {
            int lef=bin(L[i].s,k);
            int rig=bin(L[i].e,k)-1;

            if(lef<=rig) update(1,0,k,lef,rig,L[i].type);
            ans+=tree[1]*(L[i+1].h-L[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",cas++,ans);
    }
    return 0;
}

