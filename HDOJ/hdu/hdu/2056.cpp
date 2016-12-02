#include "stdio.h"
#include "math.h"
int main()
{
  double s=0,x[4],y[4],a,b,c,d,e,f,g,h;
  int i,j;
  while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f,&g,&h)==8)
   {x[0]=a;x[1]=c;x[2]=e;x[3]=g;
   y[0]=b;y[1]=d;y[2]=f;y[3]=h;
   for(i=0;i<3;i++)
     for(j=i+1;j<4;j++)
        {
            if(x[j]>x[i])
             {
                 s=x[j];
                 x[j]=x[i];
                 x[i]=s;
                 }
              if(y[j]>y[i])
              {
                  s=y[j];
                  y[j]=y[i];
                  y[i]=s;
              }
        }
    if((fabs(x[0]-x[3])>=(fabs(a-c)+fabs(e-g)))||(fabs(y[0]-y[3])>=(fabs(d-b)+fabs(h-f))))
        printf("0.00\n");
    else
        printf("%.2lf\n",(x[2]-x[1])*(y[2]-y[1]));
   }
    return 0;
  }

