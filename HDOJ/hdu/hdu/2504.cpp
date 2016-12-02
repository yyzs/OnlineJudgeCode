#include "stdio.h"
int gcd(int a,int b)
{if(a%b==0)
   return b;
 else
   return gcd(b,a%b);
}
int main()
{int a,b,c;
 int n;
 int i;
 scanf("%d",&n);
 while(n--)
 {scanf("%d%d",&a,&b);
  for(i=2;;i++)
  {c=b*i;
   if(gcd(a,c)==b)
     break;
  }
  printf("%d\n",c);
  }
  return 0;
  }

