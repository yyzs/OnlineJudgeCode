#include "stdio.h"
#include "string.h"
#define MAX  1000
int g[MAX][MAX];
int main()
{
    long long ans;
    int n,i,j;
    while(scanf("%d",&n)==1)
    {
        ans=n*2;
        for(i=0;i<n;i++)
           for(j=0;j<n;j++)
              scanf("%d",&g[i][j]);
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
              if(g[i][j])
                ans+=2;
        printf("%I64d\n",ans);
    }
    return 0;
}

