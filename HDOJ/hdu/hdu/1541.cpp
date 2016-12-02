#include "stdio.h"
#include "string.h"
#define MAX 32001
int n;
int sum[MAX];
int a[MAX];
int level[20000];
int lowbit(int x)
{
    return x&(-x);
}
void add(int p,int del)
{
    while(p<=MAX)
    {sum[p]+=del;
     p+=lowbit(p);
    }
}
int s(int p)
{
    int ans=0;
    while(p)
    {
        ans+=sum[p];
        p-=lowbit(p);
    }
    return ans;
}
int main()
{
    int i,j;
    while(scanf("%d",&n)==1)
    {
        memset(level,0,sizeof(level));
        memset(sum,0,sizeof(sum));
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
            {scanf("%d%*d",&a[i]);
             a[i]++;
             level[s(a[i])]++;
             add(a[i],1);
            }
        for(i=0;i<n;i++)
            printf("%d\n",level[i]);
    }
    return 0;
}

