#include "stdio.h"
#include "string.h"
#include <algorithm>
int bin[1010];
int rank[1010];
using namespace std;
struct segement
{double x1,y1,x2,y2;
}p[1010];
double max(double a,double b)
{
      return a>b?a:b;
}
double min(double a,double b)
{
      return a<b?a:b;
}
int find(int x)
{int r;
  r=x;
  while(r!=bin[r])
          r=bin[r];
   return r;
}
int merge(int x,int y)
{
     int fx,fy;
     fx=find(x);
     fy=find(y);
     if(fx!=fy)
             {rank[fy]+=rank[fx];
               bin[fx]=fy;
             }
}
int xiangjiao(struct segement a,struct segement b)
{
        if(min(a.x1,a.x2) <= max(b.x1,b.x2) && min(b.x1,b.x2) <= max(a.x1,a.x2) && min(a.y1,a.y2) <= max(b.y1,b.y2) && min(b.y1,b.y2) <= max(a.y1,a.y2))
    {
        double temp1 = (a.x2-a.x1)*(b.y1-a.y1)-(b.x1-a.x1)*(a.y2-a.y1);
        double temp2 = (a.x2-a.x1)*(b.y2-a.y1)-(b.x2-a.x1)*(a.y2-a.y1);
        double temp3 = (b.x2-b.x1)*(a.y2-b.y1)-(a.x2-b.x1)*(b.y2-b.y1);
        double temp4 = (b.x2-b.x1)*(a.y1-b.y1)-(a.x1-b.x1)*(b.y2-b.y1);
        if(temp1*temp2 <= 0 && temp3*temp4 <= 0)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{int n;
  int i,j;
  int sum;
  char c[8];
  int t;
  int num;
  scanf("%d",&t);
  while(t--)
  {sum=0;
   scanf("%d",&n);
   for(i=1;i<=n;i++)
         {bin[i]=i;
           rank[i]=1;
         }
   for(i=0;i<n;i++)
   {scanf("%s",&c);
     if(c[0]=='P')
        {sum++;
          scanf("%lf%lf%lf%lf",&p[sum].x1,&p[sum].y1,&p[sum].x2,&p[sum].y2);
          for(j=1;j<sum;j++)
          {if(xiangjiao(p[sum],p[j]))
                   merge(j,sum);
          }
        }
      else
      {scanf("%d",&num);
        printf("%d",rank[find(num)]);
        printf("\n");
      }
   }
   if(t!=0)
         printf("\n");
  }
  return 0;
}

