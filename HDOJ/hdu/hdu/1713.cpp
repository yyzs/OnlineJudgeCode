#include "stdio.h"
long long gcd(long long a,long long b)
{
  if(a%b==0)
         return b;
  return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
     return a*b/gcd(a,b);
}
int main()
{long long a,b,c,d;
  int t;
  long long g,m,n;
  scanf("%d",&t);
  while(t--)
  {scanf("%I64d/%I64d%I64d/%I64d",&a,&b,&c,&d);
    g=gcd(a,b);
    a=a/g;
    b=b/g;
    g=gcd(c,d);
    c=c/g;
    d=d/g;

    m=lcm(a,c);
    n=gcd(b,d);

    g=gcd(m,n);
    m=m/g;
    n=n/g;
    if(m%n==0)
             printf("%I64d\n",m/n);
    else
            printf("%I64d/%I64d\n",m,n);
    }
    return 0;
}

