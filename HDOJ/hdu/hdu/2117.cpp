#include "stdio.h"
#include "string.h"
int main()
{int n,m;
  int i,temp;
  int sum;
  while(scanf("%d%d",&n,&m)==2)
  {sum=1;
    temp=0;
    for(i=1;i<=m;i++)
    {sum*=10;
      temp=sum/n;
      sum%=n;
      }
      printf("%d\n",temp%10);
      }
      return 0;
    }

