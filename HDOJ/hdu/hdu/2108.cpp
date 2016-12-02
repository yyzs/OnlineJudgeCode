#include "stdio.h"
#include "string.h"
struct point
{int x,y;
}point0,point1,point2,r,p;
int det(int x1,int y1,int x2,int y2)
{
   return x1*y2-x2*y1;
}
int cross(struct point p0,struct point p1,struct point p2){
    return det(p1.x-p0.x,p1.y-p0.y, p2.x-p1.x,p2.y-p1.y);
}
int main()
{int judge;
 int n,i,j;
 while(scanf("%d",&n)==1&&n)
 {if(n<3)
    {for(i=0;i<n;i++)
                scanf("%*d%*d");
      printf("convex\n");
      }
    scanf("%d%d%d%d",&point0.x,&point0.y,&point1.x,&point1.y);
    r=point0;
    p=point1;
    judge=1;
    for(i=2;i<n;i++)
    {scanf("%d%d",&point2.x,&point2.y);
     if(cross(r,p,point2)<0)
                 judge=0;
      r=p;
      p=point2;
      }
      if(cross(r,p,point0)<0)
                 judge=0;
       if(cross(p,point0,point1)<0)
                 judge=0;
       if(judge==1)
                  printf("convex\n");
        else
                  printf("concave\n");
    }
    return 0;
    }



