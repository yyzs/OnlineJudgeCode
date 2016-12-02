#include "stdio.h"
#include "string.h"
int main()
{
    int n;
    while(scanf("%d",&n)==1,n)
    {
        int ans=n;
        for(int i=2;i<=n;i++)
            ans=ans*n%9;
        if(ans==0)
            ans=9;
        printf("%d\n",ans);
    }
    return 0;
}

