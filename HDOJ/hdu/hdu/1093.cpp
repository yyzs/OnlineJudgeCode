#include "stdio.h"
main()
{int n,m,a,sum;
 int i,j;
 scanf("%d",&n);
 for(i=1;i<=n;i++)
    {
         scanf("%d ",&m);
         sum=0;
         for(j=1;j<=m;j++)
          {
              scanf(" %d",&a);
              sum+=a;
          }
         printf("%d\n",sum);
    }
}
