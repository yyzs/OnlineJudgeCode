#include "stdio.h"
#include "math.h"
#define M 1e-7
double f(double x)
{
    return 42*pow(x,6.0) + 48*pow(x,5.0) + 21*pow(x,2.0) + 10*x ;
}
int main()
{
    double l,r,mid,y,d;
     int t;
     scanf("%d",&t);
     while(t--)
     {
         l=0;
         r=100;
         mid=(l+r)/2;
         scanf("%lf",&y);
        if( f(0) > y|| y> f(100) )
                   {printf("No solution!\n");
                    continue;
                   }
         while(r-l>1e-7)
         {
             if(f(mid)>y)
                    {
                        r=mid-M;
                        mid=(l+r)/2;
                    }
              else
                {
                      l=mid+M;
                      mid=(l+r)/2;
                }
         }
         d=(l+r)/2;
         printf("%.4lf\n",6 * pow(d,7.0)+8*pow(d,6.0)+7*pow(d,3.0)+5*pow(d,2.0)-y*d);
     }
     return 0;
}

