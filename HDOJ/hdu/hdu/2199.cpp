#include "stdio.h"
#include "math.h"
#define M 1e-8
int judge(double a,double b)
{if((8*pow(a,4)+7*pow(a,3)+2*pow(a,2)+3*a+6-b)>=1e-20)
     return 1;
 else
     return 0;
}
int main()
{double i,j;
 double x,y;
 int t;
 scanf("%d",&t);
 while(t--)
  {scanf("%lf",&y);
  if(y<6||y>807020306)
    printf("No solution!\n");
  else
     {i=0;
      j=100;
      while(j-i>M)
        {
         x=(j+i)/2;
         if(judge(x,y))
            j=x;
         else
            i=x;
         }
      printf("%.4lf\n",x);
      }
  }
  return 0;
  }

