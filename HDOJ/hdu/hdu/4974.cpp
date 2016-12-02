#include "stdio.h"
#include "string.h"
#define MAX 100010
int a[MAX];
int main()
{
    long long sum,max;
    int t,n,cas=0,i;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        max=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
             {scanf("%d",&a[i]);
               if(a[i]>max)
                    max=a[i];
               sum+=a[i];
             }
        cas++;
        if((sum+1)/2>max)
               printf("Case #%d: %I64d\n",cas,(sum+1)/2);
        else
               printf("Case #%d: %I64d\n",cas,max);
    }
    return 0;
}

