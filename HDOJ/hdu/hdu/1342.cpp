#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
int a[15],n;
int vis[15];
void dfs(int s,int temp)
{
    int i;
    if(temp==6)
    {
        int flag=0;
        for(i=0;i<n;i++)
            if(vis[i])
        {
            if(flag)
                printf(" %d",a[i]);
            else
                printf("%d",a[i]);
            flag=1;
        }
        printf("\n");
        return;
    }
    for(i=s+1;i<n;i++)
    {
        vis[i]=1;
        dfs(i,temp+1);
        vis[i]=0;
    }
}
int main()
{
    int i;
    int flag=0;
    while(scanf("%d",&n)==1&&n)
    {
        if(flag)
            printf("\n");
        flag=1;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        memset(vis,0,sizeof(vis));
        for(i=0;i<n-6+1;i++)
            {vis[i]=1;
             dfs(i,1);
             vis[i]=0;
            }
    }
    return 0;
}

