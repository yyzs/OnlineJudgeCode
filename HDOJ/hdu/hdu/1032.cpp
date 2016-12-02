#include "stdio.h"
long long dic(long long x)
{
 long long ans=1;
 while(x!=1)
 {if(x%2==0)
      {x/=2;ans++;}
  else
      {x=3*x+1;ans++;}
 }
 return ans;
 }
int main()
{long long a,b;
 long long i,c,d,max;
 while(scanf("%I64d%I64d",&a,&b)==2)
 {c=a>b?a:b;
  d=a<b?a:b;
  max=dic(d);
  for(i=d;i<=c;i++)
     if(dic(i)>max)
        max=dic(i);
  printf("%I64d %I64d %I64d\n",a,b,max);
  }
  return 0;
  }

