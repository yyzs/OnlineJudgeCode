#include "stdio.h"
#include "string.h"
#define MAX 100010
int b[MAX],a[MAX];
int main()
{
    int d1,d2,n;
    long long ans=0;
    while(scanf("%d%d%d",&n,&d1,&d2)==3)
    {
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=0;i<=n+2;i++)
            b[i]=10000;
        for(int i=1; i<n; i++)
            b[i]=a[i]-a[i-1];
        ans=n;
        int ok=0;
        int pos=0;
        int temp=10000;
        for(int i=1; i<=n; i++)
        {
            if(i==1)
            {
                if(b[i]==d1||b[i]==d2)
                {
                    ok=1;
                    pos=1;
                    temp=b[i];
                }
                continue;
            }
            if(ok&&b[i]==d1&&temp==d1)
                continue;
            if(ok&&b[i]==d2&&temp==d1)
            {
                temp=d2;
                continue;
            }
            if(ok&&b[i]==d2&&temp==d2)
                continue;
            if(ok&&((b[i]==d1&&temp==d2)))
            {
                ans=ans+(long long)(i-1-pos+1+1)*(long long)(i-1-pos+1)/2;
                pos=i;
                temp=b[i];
                continue;
            }
              if(ok&&((b[i]!=d1&&b[i]!=d2)))
            {
                ans=ans+(long long)(i-1-pos+1+1)*(long long)(i-1-pos+1)/2;
                ok=0;
                temp=10000;
                continue;
            }
            if(!ok&&(b[i]==d1||b[i]==d2))
            {
                ok=1;
                pos=i;
                temp=b[i];
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

