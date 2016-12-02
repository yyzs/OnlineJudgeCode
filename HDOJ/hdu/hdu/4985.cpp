#include "stdio.h"
#include "string.h"
#define MAX 100001
int a[MAX],fa[MAX];
int vis[MAX];
int main()
{
    int  n,ans;
    int i,j;
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&fa[i]);
        }
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
        {
            if(vis[i])
                continue;
            if(fa[i]==i)
            {
                printf("(%d)",i);
                continue;
            }
            int flag=0;
            printf("(%d",i);
            j=i;
            while(fa[j]!=i)
            {
                printf(" %d",fa[j]);
                flag=1;
                vis[j]=1;
                vis[fa[j]]=1;
                j=fa[j];
            }
            printf(")");
        }
        printf("\n");
    }
    return 0;
}

