#include  "stdio.h"
int main()
{long long a,b;
 while(scanf("%I64d%I64d",&a,&b)==2)
  {if((a%86+b%86)%86==0)
         printf("yes\n");
    else
        printf("no\n");
  }
  return 0;
}

