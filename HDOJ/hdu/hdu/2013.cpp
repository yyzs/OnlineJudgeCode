#include "stdio.h"
main()
{int n,i,s;
 while(scanf("%d\n",&n)!=EOF)
  {s=1;
   for(i=2;i<=n;i++)
    s=((s+1)*2);
   printf("%d\n",s);
    }
  return 0;
  }

