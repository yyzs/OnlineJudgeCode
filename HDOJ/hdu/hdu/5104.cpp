#include "stdio.h"
#include "string.h"
#define MAX 10010
int vis[MAX];
int prime[MAX];
int temp=0;
void make()
{
    int i,j;
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    vis[1]=1;
    for(i=2; i<=MAX-10; i++)
    {
        if(vis[i])
            continue;
        prime[temp++]=i;
        for(j=i+i; j<=MAX-10; j+=i)
            vis[j]=1;
    }
}
int main()
{
    int i,j,k;
    int n;
    long long ans=0,total;
    make();
    while(scanf("%d",&n)==1)
    {
        ans=0;
        for(i=0; prime[i]<=n&&i<temp; i++)
        {
            for(j=i; prime[j]<=n-prime[i]&&j<temp; j++)
            {
              if(!vis[n-prime[i]-prime[j]]&&n-prime[i]-prime[j]>=prime[i]&&n-prime[i]-prime[j]>=prime[j])
                     ans++;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

