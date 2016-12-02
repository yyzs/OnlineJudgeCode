#include "stdio.h"
int main()
{
    int t,ans,temp;
    long long n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        ans=0;
        temp=0;
        while(n)
        {
            if(n%2==1&&temp==0)
            {
                ans++;
                temp=1;
            }
            temp=n%2;
            n/=2;
        }
        printf("%d\n",ans);
    }
    return 0;
}

