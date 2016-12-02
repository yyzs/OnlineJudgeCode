#include "stdio.h"
int main()
{
    int n;
    int s,N;
    int ans=0;
    while(scanf("%d",&n)==1)
    {
        N=1;
        ans=0;
        while(1)
        {
            if(N<=n)
               N*=2;
            else
              N=(N-n)*2-1;
            if(N==1)
               break;
            ans++;
        }
        ans++;
        printf("%d\n",ans);
    }
}

