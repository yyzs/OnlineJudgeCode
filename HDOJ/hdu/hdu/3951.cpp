#include "stdio.h"
int main()
{
    int n,k;
    int t,i;
    scanf("%d",&t);
     for(i=1;i<=t;i++)
    {
        scanf("%d%d",&n,&k);
        printf("Case %d: ",i);
        if(n<=k)
        {
            printf("first\n");
            continue;
        }
        if(k==1)
        {
            if(n%2==0)
                  printf("second\n");
            else
                  printf("first\n");
        }
        else
             printf("second\n");
    }
    return 0;
}


