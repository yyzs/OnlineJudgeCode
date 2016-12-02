#include "stdio.h"
int dic(int x)
{int x1;
  x1=x/10;
  if(x%10!=0)
       return x1+1;
  return x1;
  }
int  main()
{int t,a,b,c;
  int a1,b1,c1;
  int n;
  scanf("%d",&t);
  while(t--)
  {scanf("%d",&n);
    a=n/2;
    b=(n-a)*2/3;
    c=n-a-b;
    a1=dic(a);
    b1=dic(b);
    c1=dic(c);
    printf("%d\n",a1+b1+c1);
    }
    return 0;
}

