#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
int main()
{
    int n,k,m;
    int i;
    while(scanf("%d%d",&n,&m)==2,n+m)
    {
        for(k=sqrt(2*m);k>=1;k--)
        {
            if((2*m)%k==0&&(2*m/k+1-k)%2==0)
            {
                i=(2*m/k+1-k)/2;
                printf("[%d,%d]\n",i,i+k-1);
            }
        }
        puts("");
    }
    return 0;
}

