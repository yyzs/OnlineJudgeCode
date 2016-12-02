#include "stdio.h"
int gcd(int a,int b)
{if(a%b==0)
  return b;
 else
  return gcd(b,a%b);
}
int main()
{long a,lcm;
 int n,i;
 while(scanf("%d",&n)==1)
  {lcm=1;
   for(i=0;i<n;i++)
     {scanf("%ld",&a);
      lcm=a/gcd(lcm,a)*lcm;
      }
    printf("%d\n",lcm);
    }
    return 0;
 }

