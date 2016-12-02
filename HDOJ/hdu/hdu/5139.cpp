#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 10000005
#define MOD 1000000007
using namespace std;
long long fac;
struct node
{
    int n,id;
    long long ans;
}node[MAX];
int cmp1(struct node a,struct node b)
{
    return a.n<b.n;
}
int cmp2(struct node a,struct node b)
{
    return a.id<b.id;
}
int main()
{
    long long ans=1;
    int temp,i,j,len=0,n;
    while(scanf("%d",&n)==1)
    {
        node[len].n=n;
        node[len].id=len;
        len++;
    }
    sort(node,node+len,cmp1);
    temp=0;
    fac=1;
    for(i=1;i<=node[len-1].n;i++)
    {
        fac=(fac%MOD*((long long)i%MOD))%MOD;
        ans=(ans*fac)%MOD;
        while(node[temp].n==i)
                 {node[temp].ans=ans;
                  temp++;
                 }
    }
    sort(node,node+len,cmp2);
    for(i=0;i<len;i++)
        printf("%I64d\n",node[i].ans);
    return 0;
}

