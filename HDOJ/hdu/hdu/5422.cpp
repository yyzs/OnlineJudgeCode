#include "stdio.h"
#include "string.h"
int main()
{
        int n,m;
        while(scanf("%d%d",&n,&m)==2)
        {
                int u,v;
                int ok=0;
                while(m--)
                {
                        scanf("%d%d",&u,&v);
                        if((u==1&&v==n)||(u==n&&v==1))
                                ok=1;
                }
                int ans=1;
                if(ok)
                        printf("%d %d\n",ans,n*(n-1)/2);
                else
                        printf("%d %d\n",ans,1);
        }
        return 0;
}

