#include "stdio.h"
#include "string.h"
int main()
{
    int t,n,k,i,j,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        if(k>n)
        {
            printf("0\n");
            continue;
        }
        r=n%k;
        if(r<=k/2)
        {
            printf("%d\n",n*n-r*r);
            continue;
        }
        printf("%d\n",n*n-(k-r)*(k-r));
    }
    return 0;
}

