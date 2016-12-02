#include "stdio.h"
int dic(int n,int d)
{
  int ans=0;
  while(n!=0)
  {ans=ans+n%d;
   n/=d;
   }
   return ans;
}
int main()
{int n,ans=0,a,b,c;
 while(scanf("%d",&n)!=EOF&&n)
 {ans=n/1000+n%1000/100+n%100/10+n%100%10;
  if(dic(n,12)==ans&&dic(n,16)==ans)
                printf("%d is a Sky Number.\n",n);
  else
                printf("%d is not a Sky Number.\n",n);
  }
  return 0;
  }

