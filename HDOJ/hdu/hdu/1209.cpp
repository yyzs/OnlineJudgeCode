#include "stdio.h"
#include "string.h"
#include "math.h"
#include <algorithm>
#define MIN 10e-6
using namespace std;
struct time
{int h,m;
 double angle;
}a[5];
int cmp(struct time a,struct time b)
{
     if(fabs(a.angle-b.angle)<MIN)
            return a.h<b.h;
     return a.angle<b.angle;
}
int main()
{int t;
 int n,i;
 double angle1,angle2;
 scanf("%d",&t);
 while(t--)
 {for(i=0;i<5;i++)
          {scanf("%d:%d",&a[i].h,&a[i].m);
           angle1=(a[i].h%12)*30;
           angle2=a[i].m*6;
           if((angle1+angle2/12)>360)
                    angle1=angle1+angle2/12-360;
           else
                    angle1=angle1+angle2/12;
           a[i].angle=fabs(angle1-angle2);
           if(a[i].angle>180)
               a[i].angle=360-a[i].angle;
           }
   sort(a,a+5,cmp);
   printf("%02d:%02d\n",a[2].h,a[2].m);
   }
   return 0;
}



