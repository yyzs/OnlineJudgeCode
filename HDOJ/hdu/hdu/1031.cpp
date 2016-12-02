#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
double a[1000][1000];
int ans[300];
struct point
{double sum;
 int pos;
}p[300],p1[300];
int cmp1(struct point a,struct point b)
{if(a.sum==b.sum)
       return a.pos<b.pos;
 return a.sum>b.sum;
}
int cmp2(struct point a,struct point b)
{
    return a.pos>b.pos;
}
int main()
{int i,j,n,m,k;
 int ans;
 double sum;
 while(scanf("%d%d%d",&n,&m,&k)==3)
 {for(i=0;i<n;i++)
      for(j=0;j<m;j++)
            scanf("%lf",&a[i][j]);
  for(j=0;j<m;j++)
  {sum=0;
      for(i=0;i<n;i++)
          sum+=a[i][j];
   p[j].pos=j;
   p[j].sum=sum;
   }
   sort(p,p+m,cmp1);
   for(i=0;i<k;i++)
          p1[i].pos=p[i].pos;
   sort(p1,p1+k,cmp2);
   for(i=0;i<k;i++)
          {if(i==0)
              printf("%d",p1[i].pos+1);
           else
              printf(" %d",p1[i].pos+1);
          }
    printf("\n");
  }
  return 0;
}


