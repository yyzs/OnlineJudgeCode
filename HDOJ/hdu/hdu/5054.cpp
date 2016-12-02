#include "stdio.h"
#include "string.h"
int main()
{
    int n,m,x,y;
    while(scanf("%d%d%d%d",&n,&m,&x,&y)==4)
    {
        if(x*2==n&&y*2==m)
               puts("YES");
        else
               puts("NO");
    }
    return 0;
}

