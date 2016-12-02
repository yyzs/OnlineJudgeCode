#include "stdio.h"
int main()
{long long a,b,c;
 int ok;
 while(scanf("%I64d%I64d%I64d",&a,&b,&c)!=EOF)
  {ok=0;
   if(a+b==c||a+c==b||b+c==a)
       ok=1;
   if(a*b==c||a*c==b||b*c==a)
       ok=1;
   if(a&&(b%a==c||c%a==b))
       ok=1;
   if(b&&(a%b==c||c%b==a))
       ok=1;
   if(c&&(a%c==b||b%c==a))
       ok=1;
   if(ok)
       printf("oh,lucky!\n");
   else
       printf("what a pity!\n");
  }
  return 0;
  }

