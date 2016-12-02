#include "stdio.h"
#include "math.h"
#define INF 1e-10
int main()
{
    int t,a,b,c,d;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)==4)
    {
        if(fabs((double)b*log((double)a)-(double)d*log((double)c))<INF)
        {
            puts("=");
            continue;
        }
        if((double)b*log((double)a)-(double)d*log((double)c)<0)
            puts("<");
        else
            puts(">");
    }
    return 0;
}

