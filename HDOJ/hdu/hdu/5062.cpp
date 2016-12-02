#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int c[]={1,9,18,54,90,174,258};
int main()
{
    int t;
    int i,j,n;
    int len,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",c[n]);
    }
    return 0;
}

