#include "stdio.h"
#include "string.h"
#define MAX 22
int w[MAX],v[MAX];
int n,k;
int max;
int W;
void dfs(int num,int cur,int tempv,int tempw)
{
    int i;
    if(tempv>W)
        return;
    if(num>k)
        return;
    if(num==k)
    {
        if(tempw>max)
            max=tempw;
        return;
    }
    for(i=cur+1;i<n;i++)
    {
        if(num+1<=k&&tempv+v[i]<=W)
           dfs(num+1,i,tempv+v[i],tempw+w[i]);
    }
}
int main()
{
    int t;
    int i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d%d",&w[i],&v[i]);
        scanf("%d",&W);
        max=0;
        dfs(0,-1,0,0);
        printf("%d\n",max);
    }
    return 0;
}

