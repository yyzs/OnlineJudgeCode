#include "stdio.h"
int main()
{int n;
 while(scanf("%d",&n)==1)
  {if((n+1)%8==3||(n+1)%8==7) 
       printf("yes\n");
   else
       printf("no\n");
   }
  return 0;
}
