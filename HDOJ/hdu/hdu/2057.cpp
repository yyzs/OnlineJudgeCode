#include "stdio.h"
#include "string.h"
int main()
{
    long long a,b;
    while(scanf("%I64X%I64X",&a,&b)==2)
    {
     printf(a+b>=0?"%I64X\n":"-%I64X\n",a+b>=0?a+b:-(a+b));    
    }
    return 0;
}
