#include "stdio.h"
#include "string.h"
int sum[501000];
int main()
{
    int t,n,i,j;
    for(i=1;i<=250000;i++)
        for(j=i+i;j<=500000;j+=i)
           sum[j]+=i;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d",&n);
      printf("%d\n",sum[n]);
    }
    return 0;
}
