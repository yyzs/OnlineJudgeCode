#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#define M 1e-6
double pie[10010];
int test(double x,int n,int f)
{
  int   i,count=0;
  for(i=1;i<=n;i++)
       count+=(int)(pie[i]/x);
  if(count>=f)
          return 1;
  else
         return 0;
}
int  main()
{int n,f;
int t,i;
double P=acos ( -1.0 );
 double ra,l,r,mid,sum;
 scanf("%d",&t);
 while(t--)
 {scanf("%d%d",&n,&f);
  sum=0;
  for(i=1;i<=n;i++)
         {scanf("%lf",&ra);
          pie[i]=P*ra*ra;
         sum+=pie[i];
         }
   r=sum/(double)(f+1);
   l=0.0;
   f=f+1;
   while(r-l>M)
   {
      mid=(l+r)/2;
      if(test(mid,n,f)==1)
             l=mid;
      else
            r=mid;
   }
   printf("%.4lf\n",mid);
 }
 return 0;
 }

