#include "stdio.h"
int main()
{int n,s,i;
 while(scanf("%d\n",&n)==1)
 {s=0;
  for(i=0;i<=n;i++)
   s+=i;
  printf("%d\n\n",s);
 }
 return 0;
}
