#include "stdio.h"
int a[100];
main()
{int n,i,s=0,min;
 while(scanf("%d ",&n)!=EOF)
  {if(n==0)
     break;
   min=0;
   for(i=0;i<n;i++)
    {scanf("%d",&a[i]);
     if(a[i]<a[min])
       min=i;
     }
    printf("%d",a[min]);
    for(i=0;i<n;i++)
    {if(i==min&&min!=0)
                printf(" %d",a[0]);
     if(i!=min&&i!=0)
                printf(" %d",a[i]);
    }
    printf("\n");
   }
   return 0;
}

