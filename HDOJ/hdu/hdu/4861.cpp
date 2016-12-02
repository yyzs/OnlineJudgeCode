#include "stdio.h"
#include "string.h"
int main()
{
    int k,p;
    while(scanf("%d%d",&k,&p)==2)
    {
        if(k/(p-1)%2)
            puts("YES");
        else
           puts("NO");
    }
    return 0;
}

