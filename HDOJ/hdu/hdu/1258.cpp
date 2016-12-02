#include "stdio.h"
#include "string.h"
#define MAX 1010
int flag;
int hash[MAX],a[MAX],ans[MAX];
int n,t;
void dfs(int k,int m,int len)
{
    int i;
    if(m==t)
    {
        flag=1;
        for(i=0;i<=len;i++)
        {
            if(i)
                printf("+");
            printf("%d",ans[i]);
        }
        puts("");
    }
    if(m>t)
        return;
    for(i=k+1;i<n;i++)
    {
        ans[len+1]=a[i];
        dfs(i,m+a[i],len+1);
        while(a[i]==a[i+1])
            i++;
    }
}
int main()
{
    int i,j;
    while(scanf("%d%d",&t,&n)==2,n)
    {
        flag=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        memset(hash,0,sizeof(hash));
        memset(ans,0,sizeof(ans));
        printf("Sums of %d:\n",t);
        for(i=0;i<n;i++)
        {
            if(hash[a[i]])
                continue;
            hash[a[i]]=1;
            ans[0]=a[i];
            dfs(i,a[i],0);
        }
        if(!flag)
            puts("NONE");
    }
    return 0;
}

