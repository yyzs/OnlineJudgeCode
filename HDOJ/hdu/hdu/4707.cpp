#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 100010
using namespace std;
int pre[MAX];
int find(int x)
{
    while(x!=pre[x])
        x=pre[x];
    return x;
}
int dep(int x)
{
    int r=x,num=0;
    while(r!=pre[r])
    {
        r=pre[r];
        num++;
    }
    return num;
}
int main()
{
    int t;
    int n,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&d);
        int ans=0;
        for(int i=0;i<n;i++)
            pre[i]=i;
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            pre[y]=x;
        }
        for(int i=0;i<n;i++)
        {
            if(find(i)==0)
                if(dep(i)>d)
                    ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

