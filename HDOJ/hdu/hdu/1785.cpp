#include "stdio.h"
#include "math.h"
#include "string.h"
#include <algorithm>
using namespace std;
struct point
{double x,y;
  double yu;
  }p[110];
  int cmp(struct point a,struct point b)
  {
          return a.yu>b.yu;
    }
  int main()
  {int n;
    int i,j;
    double z;
    while(scanf("%d",&n)&&n>0)
    {for(i=0;i<n;i++)
                  {scanf("%lf%lf",&p[i].x,&p[i].y);
                    z=sqrt(p[i].x*p[i].x+p[i].y*p[i].y);
                    p[i].yu=p[i].x/z;
                    }
      sort(p,p+n,cmp);
      for(i=0;i<n;i++)
      {if(i!=0)
              printf(" ");
        printf("%.1lf %.1lf",p[i].x,p[i].y);
        }
       printf("\n");
       }
       return 0;
    }

