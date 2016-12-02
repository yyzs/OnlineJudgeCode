#include "stdio.h"
long long a[31];
int main()
{
    int i;
    int m,n;
    a[1]=1;
    a[2]=3;
    a[3]=5;
    for(i=4;i<=30;i++)
      a[i]=a[i-1]+a[i-2]*2;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        printf("%I64d\n",a[m]);
    }
    return 0;
}
