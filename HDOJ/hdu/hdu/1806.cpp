#include "stdio.h"
#include "algorithm"
using namespace std;
const int MAX=200005;
int d[MAX][40],a[MAX],b[MAX],c[MAX],n;
int RMQ_init()
{
    for(int i=1; i<=n; i++)  d[i][0]=a[i];
    for(int j=1; (1<<j)<=n; j++)
        for(int i=1; i+j-1<=n; i++)
            d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
int RMQ(int L,int R)
{
    int k=0;
    while(1<<(k+1)<=R-L+1) k++;
    return max(d[L][k],d[R-(1<<k)+1][k]);
}
int main()
{
    int q,i,j;
    int sam,tot,len=0;
    while(scanf("%d%d",&n,&q)==2,n)
    {
        sam=0,tot=0,len=1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            if(i==1)
            {
                sam=1;
                tot=0;
                continue;
            }
            if(b[i]==b[i-1])
            {
                sam++;
            }
            else
            {
                a[len]=sam;
                tot+=sam;
                c[len]=tot;
                len++;
                sam=1;
            }
        }
        if(i==1)
        {a[len]=1;
         c[len]=1;
        }
        RMQ_init();
        while(q--)
        {
            scanf("%d%d",&i,&j);
            int l=lower_bound(c+1,c+len,i)-c;
            int r=lower_bound(c+1,c+len,j)-c;
            //printf("l:%d r:%d\n",l,r);
            if(l==r)
            {
                printf("%d\n",j-i+1);
                continue;
            }
            int ans=0;
            if(r-1!=l)
                ans=RMQ(l+1,r-1);
            ans=max(ans,c[l]-i+1);
            ans=max(ans,j-c[r-1]);
            printf("%d\n",ans);
        }
    }
    return 0;
}

