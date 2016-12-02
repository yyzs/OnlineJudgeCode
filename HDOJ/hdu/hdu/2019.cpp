#include "stdio.h"
int main()
{int n,m,a;
 int i,flag;
 while(scanf("%d%d",&n,&m)==2)
 {if(n==0&&m==0)
     break;
  flag=0;
  for(i=0;i<n;i++)
   {scanf("%d",&a);
    if(m<a&&!flag)
      {flag=1;
       printf("%d ",m);
      }
    if(i!=n-1)
       printf("%d ",a);
    else
       printf("%d",a);
     }
    printf("\n");
   }
   return 0;
 }

