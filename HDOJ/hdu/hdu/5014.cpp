#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#define MAX 100010
int vis[MAX];
char c[500],d[500],e[500];
int a[MAX],b[MAX];
int main()
{
    int i,n,j;
    int temp,len;
    long long t;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<=n;i++)
            scanf("%d",&a[i]);
        memset(vis,0,sizeof(vis));
        for(i=n;i>=1;i--)
        {
            if(vis[i])
                continue;
            itoa(i,c,2);
            len=strlen(c);
            for(j=0;j<len;j++)
                  d[j]='1';
            for(j=0;j<len;j++)
                  e[j]=((d[j]-'0')^(c[j]-'0'))+'0';
            temp=0;
            for(j=0;j<len;j++)
                  temp=temp+((int)pow(2.0,(double)(len-j-1)))*(e[j]-'0');
            vis[temp]=i;
            vis[i]=temp;
        }
        t=0;
        for(i=0;i<=n;i++)
            t+=(i^vis[i]);
        printf("%I64d\n",t);
        for(i=0;i<=n;i++)
            printf("%d ",vis[a[i]]);
        puts("");
    }
    return 0;
}

