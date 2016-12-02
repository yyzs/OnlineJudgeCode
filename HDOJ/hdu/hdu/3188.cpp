#include "stdio.h"
int main()
{int a,b,c;
 int t;
 scanf("%d",&t);
 while(t--)
 {scanf("%d%d%d",&a,&b,&c);
  if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
    printf("good\n");
  else
   if(a==b||b==c||c==a)
     printf("perfect\n");
  else
     printf("just a triangle\n");
  }
  return 0;
  }

