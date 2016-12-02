#include "stdio.h"
main()
{int n,a,b,i=0;
 scanf("%d\n",&n);
 while(++i<=n)
 {scanf("%d %d\n",&a,&b);
  printf("%d\n",a+b);
 }
return 0;
}
