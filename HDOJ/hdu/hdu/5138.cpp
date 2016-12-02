#include "stdio.h"
#include "string.h"
int main()
{
    int flag;
    int n,i;
    int a[5];
    while(scanf("%d",&n)==1)
    {
        a[0]=n-1;
        a[1]=n-2;
        a[2]=n-4;
        a[3]=n-7;
        a[4]=n-15;
        flag=0;
        for(i=4;i>=0;i--)
        {
            if(a[i]<=0)
                continue;
            if(flag)
                printf(" %d",a[i]);
            else
                printf("%d",a[i]);
            flag=1;
        }
        puts("");
    }
    return 0;
}

