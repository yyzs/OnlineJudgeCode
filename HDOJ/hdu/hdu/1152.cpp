#include "stdio.h"
#include "string.h"
struct point
{int x,y;
}p[200010];
int main()
{int n,i,j;
 int sum1,sum2;
 int textx,texty;
 while(scanf("%d",&n)==1&&n)
 {for(i=0;i<n;i++)
                 scanf("%d%d",&p[i].x,&p[i].y);
  textx=p[n/2].x;
  texty=p[n/2].y;
  sum1=0;
  sum2=0;
  for(i=0;i<n;i++)
                {if(p[i].x==textx||p[i].y==texty)
                            continue;
                 if((p[i].x>textx&&p[i].y>texty)||(p[i].x<textx&&p[i].y<texty))
                            sum1++;
                 else
                            sum2++;
                 }
   printf("%d %d\n",sum1,sum2);
   }
   return 0;
}

