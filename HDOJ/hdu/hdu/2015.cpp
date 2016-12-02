#include "stdio.h"
int main()
{int a[100],i,j;
 int n,m;
 int sum;  
 for(i=0;i<100;i++)
    a[i]=(i+1)*2;
 while(scanf("%d%d",&n,&m)==2)
   {
    sum=0;
    for(i=0;i<n;i=i+m)
      {if(i+m-1<=n-1)
         {
          for(j=i;j<=i+m-1;j++)
            sum+=a[j];
          if(i==0)
              printf("%d",sum/m);
          else
              printf(" %d",sum/m);
            sum=0;
          }
          else
           {for(j=i;j<n;j++)
              sum+=a[j];
            printf(" %d",sum/(n-i));
           }
        }
       printf("\n");
     }
     return 0;
    }

