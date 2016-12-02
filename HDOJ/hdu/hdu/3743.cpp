#include "stdio.h"
#include "string.h"
#include <algorithm>
#define MAX 1000010
using  namespace std;
struct Node
{
    int num,id;
}node[MAX];
int n;
int a[MAX];
int sum[MAX];
int cmp(struct Node a,struct Node b)
{
     return a.num<b.num;
}
int lowbit(int x)
{
    return x&(-x);
}
void add(int p,int del)
{
    while(p<=n)
    {sum[p]+=del;
     p+=lowbit(p);
    }
}
long long s(int p)
{
    long long ans=0;
    while(p)
    {
        ans+=sum[p];
        p-=lowbit(p);
    }
    return ans;
}
int main()
{
    int i,j,id;
    long long ans=0;
    while(scanf("%d",&n)==1)
    {
        ans=0;
        memset(sum,0,sizeof(sum));
        for(i=0;i<n;i++)
        {
            scanf("%d",&node[i].num);
            node[i].id=i+1;
        }
        sort(node,node+n,cmp);
        id=1;
        a[node[0].id]=1;
        for(i=1;i<n;i++)
        {
            if(node[i].num==node[i-1].num)
                     a[node[i].id]=id;
            else
                     a[node[i].id]=++id;
        }
        for(i=1;i<=n;i++)
        {
            add(a[i],1);
            ans=ans+i-s(a[i]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

