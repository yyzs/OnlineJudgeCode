#include "stdio.h"
int main()
{int s,d;
 int a,b;
 int t;
 scanf("%d",&t);
 while(t--)
 {scanf("%d%d",&s,&d);
  a=(s+d)/2;
  b=(s-d)/2;
  if(a<0||b<0||(s+d)%2!=0||(s-d)%2!=0)
         printf("impossible\n");
   else
         printf("%d %d\n",a,b);
  }
  return 0;
}

