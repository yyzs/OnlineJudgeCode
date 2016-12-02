#include "stdio.h"
#include "string.h"
#define MAX 1010
int vis[MAX];
void make()
{
    int i,j;
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    vis[1]=0;
    for(i=2;i<=MAX-10;i++)
    {
        if(!vis[i])
        {
            for(j=i+i;j<=MAX-10;j+=i)
                 vis[j]=1;
        }
    }
}
int main()
{
    int n,i,j;
    int sum;
    make();
    while(scanf("%d",&n)==1)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            if(j<0)
                continue;
            if(!vis[j])
                sum+=j;
        }
        printf("%d\n",sum);
    }
    return 0;
}

