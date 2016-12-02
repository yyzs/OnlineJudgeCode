#include "stdio.h"
#include "math.h"
int main()
{double sum;
  int n,i;
  int temp;
  while(scanf("%d",&n)&&n)
  {sum=0;
    temp=1;
    for(i=n;i>=1;i--)
    {if(i!=1)
            sum=sum+(double)temp*((double)(1/(double)i))*2;
      else
            sum=sum+(double)temp*((double)(1/(double)i));
      temp++;
     }
     printf("%.2lf\n",sum);
     }
     return 0;
    }

