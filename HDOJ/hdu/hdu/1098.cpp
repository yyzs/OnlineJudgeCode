#include "stdio.h"
#include "string.h"
int main()
{
    int n,a;
    int i,j;
    while(scanf("%d",&n)==1)
    {
        for(a=1;a<=65;a++)
            if((a*n+13)%5==0&&(a*n+5)%13==0)
                break;
        if(a>65)
           { puts("no");
              continue;
           }
        printf("%d\n",a);
    }
    return 0;
}

