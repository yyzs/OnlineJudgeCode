#include "stdio.h"
double area(double x0,double y0,double x1,double y1,double x2,double y2)
{
  return (x0*y1+x2*y0+x1*y2-x2*y1-x0*y2-x1*y0)/2;
}
int main()
{double a[100][2];
 int n,i,j;
 double sum;
 while(scanf("%d",&n)!=EOF)
  {if(n==0)
    break;
   for(i=0;i<n;i++)
    scanf(" %lf %lf",&a[i][0],&a[i][1]);\
   sum=0;
   for(i=2;i<n;i++)
     sum+=area(a[0][0],a[0][1],a[i-1][0],a[i-1][1],a[i][0],a[i][1]);
    printf("%.1lf\n",sum);
    }
    return 0;
  }

