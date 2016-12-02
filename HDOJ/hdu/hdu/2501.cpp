#include "stdio.h"
long long a[31];
int main()
{
    int t,i,m;
    scanf("%d",&t);
    a[1]=1;
    a[2]=3;
    for(i=3;i<=30;i++)
       a[i]=a[i-1]+a[i-2]*2;
    while(t--)
    {
        scanf("%d",&m);
        printf("%d\n",a[m]);
    }
    return 0;
}
