#include "stdio.h"
int gcd(int a,int b)
{if(a%b==0)
   return b;
 else
   return gcd(b,a%b);
}
int  main()
{int a,b,c,d,rel,sub,sum;
 int n;
 scanf("%d",&n);
 while(n--)
 {scanf("%d%d%d%d",&a,&b,&c,&d);
  rel=b*d/gcd(b,d);
  a*=rel/b;
  c*=rel/d;
  sub=a+c;
  sum=rel;
  rel=gcd(sub,sum);
  sub/=rel;
  sum/=rel;
  printf("%d %d\n",sub,sum);
  }
  return 0;
  }

