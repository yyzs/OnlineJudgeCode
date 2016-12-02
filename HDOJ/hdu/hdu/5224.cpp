#include "stdio.h"
#include "math.h"
int main()
{
    long long ans;
    int t,s,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&s);
        ans=10000000000000;
        for(i=1;i<=sqrt((double)s);i++)
        {
            if(s%i==0)
            {
                if(2*(i+s/i)<ans)
                    ans=2*(i+s/i);
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

