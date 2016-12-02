#include "stdio.h"
int main()
{int n,i;
 double c,sum;
 while(1)
 {scanf("%lf",&c);
  if(c==0.0)
    break;
  sum=0;
  for(i=2;;i++)
    {sum+=1.0/i;
     if(sum>=c)
        break;
     }
  printf("%d card(s)\n",i-1);
  }
  return 0;
  }

