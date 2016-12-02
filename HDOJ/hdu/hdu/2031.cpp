#include "stdio.h"
int main()
{int n,r;
 int i,a[100];
 while(scanf("%d%d",&n,&r)!=EOF)
  {if(n<0)
    {printf("-");
     n=-n;
    }
    i=0;
   while(n!=0)
    {a[i++]=n%r;
     n/=r;
     }
    for(i=i-1;i>=0;i--)
       {
           if(a[i]<10)
             printf("%d",a[i]);
            else
             printf("%c",a[i]+55);
       }
    printf("\n");
   }
   return 0;
   }

