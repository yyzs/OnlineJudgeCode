#include "stdio.h"
int main()
{long long m;
 while(scanf("%I64d",&m)==1)
      printf("%I64d\n",(m*m*m+5*m)/6+1);
 return 0;
 }

