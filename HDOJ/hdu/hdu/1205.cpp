#include "stdio.h"
#include "stdlib.h"
int main()
{int t;
 long long n,sum,max,a,j;
 scanf("%d",&t);
 while(t--)
     {
       scanf("%I64d",&n);
       sum=0;
       max=0;
       for(j=0;j<n;j++)
         {scanf("%I64d",&a);
          sum+=a;
          if(a>max)
             max=a;
          }
       if(max>sum-max+1)
         printf("No\n");
       else
         printf("Yes\n");
       }
    return 0;
}
