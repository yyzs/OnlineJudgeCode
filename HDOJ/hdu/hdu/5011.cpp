#include "stdio.h"
#include "string.h"
#define MAX 100010
long long a[MAX];
int main()
{
    int n,i;
    long long sum;
    while(scanf("%d",&n)==1)
    {
        sum=0;
        for(i=0;i<n;i++)
            scanf("%I64d",&a[i]);
        for(i=0;i<n;i++)
            sum=(sum^a[i]);
        if(sum!=0)
            puts("Win");
        else
            puts("Lose");
    }
    return 0;
}

