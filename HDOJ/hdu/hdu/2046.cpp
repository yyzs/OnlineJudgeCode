#include "stdio.h"
int main()
{
    int n,i;
    long long a[51];
    while(scanf("%d",&n)==1)
    {
        a[1]=1;
        a[2]=2;
        for(i=3;i<=51;i++)
          a[i]=a[i-2]+a[i-1];
        printf("%I64d\n",a[n]);
     }
     return 0; 
}
