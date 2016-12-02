#include "stdio.h"
int main()
{int t,n;
 int i,j;
 scanf("%d",&t);
 while(t--)
 {scanf("%d",&n);
  for(i=0;i<n;i++)
  {for(j=0;j<n;j++)
      {if(j==0)
          printf("%d",(i+1)*(j+1));
       else
          printf(" %d",(i+1)*(j+1));
      }
   printf("\n");
   }
  }
  return 0;
  }

