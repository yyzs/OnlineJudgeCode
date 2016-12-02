#include "stdio.h"
int main()
{
    int n,m;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&n);
        printf("%d\n",2*n*n-n+1);
    }
    return 0;
}
    
