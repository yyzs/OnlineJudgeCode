#include "stdio.h"
#include "math.h"
#include "stdlib.h"
int main()
{
    int m,n,min,sum;
    int a[501]={0};
    int i,j;
    scanf("%d",&m);
    while(m--)
    {   sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
           scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
              sum+=abs(a[i]-a[j]);
            if(i==0)
              min=sum;
            if(sum<min)
              min=sum;  
        }
        printf("%d\n",min);
    }
    return 0;
}
