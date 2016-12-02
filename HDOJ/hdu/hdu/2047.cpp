#include "stdio.h"
int main()
{
    int n,i;
    long long a[51];
    while(scanf("%d",&n)==1)
    {
        a[1]=3;
        a[2]=8;
        a[3]=22;
        for(i=4;i<=40;i++)
          a[i]=3*a[i-1]-2*a[i-3];
        printf("%I64d\n",a[n]);
     }
     return 0; 
}
