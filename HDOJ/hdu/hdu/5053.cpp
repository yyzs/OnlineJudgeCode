#include "stdio.h"
#include "string.h"
int main()
{
    int l,r;
    int i,t,cas=0;
    long long ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&r);
        ans=0;
        for(i=l;i<=r;i++)
            ans=ans+(long long)i*(long long)i*(long long)i;
        cas++;
        printf("Case #%d: %I64d\n",cas,ans);
    }
    return 0;
}

