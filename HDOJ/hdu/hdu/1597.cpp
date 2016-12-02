#include "stdio.h"
#include "string.h"
#include "math.h"
int main()
{long long  n,i,j;
 long long sum;
 int t;
 scanf("%d",&t);
 while(t--)
 {scanf("%I64d",&n);
  for(i=sqrt(2*(double)n)-1;;i++)
      {
          sum=i*(i+1)/2;
          if(sum>=n)
             break;
      }
    i-=1;
    sum=(1+i)*i/2;
    if(n>sum)
           n-=sum;
    while(n>=10)
           n-=9;
    printf("%I64d\n",n);

   }
   return 0;
}

