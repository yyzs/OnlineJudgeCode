#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 1000010
using namespace std;
struct node
{
       long long w;
       int id;
}nodea[MAX],nodeb[MAX];
int cmp(struct node a,struct node b)
{
        if(a.w==b.w)
                return a.id<b.id;
        return a.w>b.w;
}
int main()
{
        int t,n;
        int cas=0;
        long long a,b;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d%I64d%I64d",&n,&a,&b);
                for(int i=0;i<n;i++)
                {
                        long long x;
                        scanf("%I64d",&x);
                        nodea[i].id=i;
                        nodea[i].w=a*x*x;
                        nodeb[i].id=i;
                        nodeb[i].w=b*x;
                }
                sort(nodea,nodea+n,cmp);
                sort(nodeb,nodeb+n,cmp);
                long long ans;
                if(nodea[0].id==nodeb[0].id)
                        ans=max(nodea[0].w+nodeb[1].w,nodea[1].w+nodeb[0].w);
                else
                        ans=nodea[0].w+nodeb[0].w;
                cas++;
                printf("Case #%d: %I64d\n",cas,ans);
        }
        return 0;
}

