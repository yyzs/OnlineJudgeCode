#include "stdio.h"
#include "math.h"
int main()
{long long i;
 long long x,s;
 int t;
 scanf("%d",&t);
 while(t--)
 {scanf("%I64d",&x);
  s=0;
  for(i=1;;i++)
     {s+=i;
      if(s*s>=x)
          {printf("%I64d\n",i);
           break;
           }
      }
   }
   return 0;
}

