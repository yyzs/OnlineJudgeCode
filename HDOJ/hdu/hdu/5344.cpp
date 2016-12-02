#include "stdio.h"
#include "string.h"
int main()
{
        int t;
        int n,m,z,l;
        long long temp,ans;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d%d%d%d",&n,&m,&z,&l);
                temp=0;
                ans=0;
                for(int i=2;i<=n;i++)
                {
                        temp=(temp*m%l+z%l)%l;
                        ans=(ans^(temp*2));
                }
                printf("%I64d\n",ans);
        }
        return 0;
}

