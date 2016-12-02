#include "stdio.h"
#define MAX 10010
int a[MAX],p[MAX];
int main()
{
    int ans=0;
    int n,i,j;
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=10000;i++)
            p[i]=MAX;
        ans=0;
        for(i=n;i>=1;i--)
        {
            int temp=MAX;
            for(j=a[i];j<=10000;j+=a[i])
                if(p[j]<temp)
                   temp=p[j];
            if(temp!=MAX)
                ans+=temp;
            p[a[i]]=i;
        }
        printf("%d\n",ans);
    }
    return 0;
}

