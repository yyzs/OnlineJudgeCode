#include "stdio.h"
int main()
{
    int t,n,i;
    double a,max;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        max=0;
        for(i=0;i<n;i++)
        {
          scanf("%lf",&a);
          if(a>max)
            max=a;              
        }
        printf("%.2lf\n",max);
    }
    return 0;
}
