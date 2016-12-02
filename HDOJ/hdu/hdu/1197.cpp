#include "stdio.h"
#include "string.h"
int turn(int n,int k)
{int sum=0;
 while(n!=0)
     {sum=sum+n%k;
      n/=k;
     }
 return sum;
}
int main()
{int sum1,sum2,sum3;
 int n,i;
 for(i=2992;i<=9999;i++)
      {sum1=turn(i,10);
       sum2=turn(i,12);
       sum3=turn(i,16);
       if(sum1==sum2&&sum2==sum3)
                      printf("%d\n",i);
      }
  return 0;
}

