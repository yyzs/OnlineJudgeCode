#include "stdio.h"
#include "string.h"
#include "math.h"
int main()
{int i,j,n,t;
 int ok=0;
 scanf("%d",&t);
 while(t--)
 {scanf("%d",&n);
  ok=0;
  while(n!=1)
  {if(n%2==0)
         n/=2;
   else
         {if(!ok)
              {printf("%d",n);
               ok=1;
               }
          else
              printf(" %d",n);
          n=n*3+1;
          }
   }
   if(!ok)
          printf("No number can be output !\n");
    else
          printf("\n");
    }
    return 0;
}

