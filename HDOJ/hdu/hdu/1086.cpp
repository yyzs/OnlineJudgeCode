#include "stdio.h"
#include "string.h"
#include "math.h"
struct point
{double x,y;
};
struct point m1[100],m2[100];
int onsegemant(struct point pi,struct point pj,struct point pk)
{if(pk.x<=max(pi.x,pj.x)&&pk.x>=min(pi.x,pj.x)&&pk.y<=max(pi.y,pj.y)&&pk.y>=min(pi.y,pj.y))
      return 1;
  else
      return 0;
}
int  max(double x,double y)
{
       double m=x>y?x:y;
       return m;
}
int  min(double x,double y)
{
       double m=x<y?x:y;
       return m;
}
double direction(struct point i,struct point j,struct point k)
{
       return (k.x-i.x)*(j.y-i.y)-(j.x-i.x)*(k.y-i.y);
}
int segement(struct point p1,struct point p2,struct point p3,struct point p4)
{double d1=direction(p3,p4,p1);
 double d2=direction(p3,p4,p2);
 double d3=direction(p1,p2,p3);
 double d4=direction(p1,p2,p4);
 if(d1*d2<0&&d3*d4<0)
      return 1;
 else
   if(d1==0&&onsegemant(p3,p4,p1))
       return 1;
 else
   if(d2==0&&onsegemant(p3,p4,p2))
       return 1;
 else
   if(d3==0&&onsegemant(p1,p2,p3))
       return 1;
 else
   if(d4==0&&onsegemant(p1,p2,p4))
       return 1;
 return 0;
}
int main()
{int n,i,j;
 int sum;
 while(scanf("%d",&n)==1&&n)
  {sum=0;
   for(i=0;i<n;i++)
       scanf("%lf%lf%lf%lf",&m1[i].x,&m1[i].y,&m2[i].x,&m2[i].y);
   for(i=0;i<n;i++)
       for(j=i+1;j<n;j++)
        {if(segement(m1[i],m2[i],m1[j],m2[j]))
             sum++;
        }
    printf("%d\n",sum);
    }
  return 0;
  }

