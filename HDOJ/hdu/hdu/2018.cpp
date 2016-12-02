#include "stdio.h"
int res(int n)
{if(n==1) return 1;
 else if(n==2) return 2;
 else if(n==3) return 3;
 else return res(n-1)+res(n-3);
 }
int main()
{int n;
 while(scanf("%d",&n)!=EOF)
  {if(n==0)
    break;
   printf("%d\n",res(n));
   }
  return 0;
}
