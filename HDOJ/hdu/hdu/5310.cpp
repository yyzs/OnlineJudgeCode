#include "stdio.h"
#include "algorithm"
#define INF 1e-10
#include "math.h"
using namespace std;
int main()
{
     int n,m,p,q;
     int ans;
     int t;
     scanf("%d",&t);
     while(t--)
     {
          scanf("%d%d%d%d",&n,&m,&p,&q);
          ans=0;
          double x=(double)q/(double)m;
          if(x>(double)p||fabs(x-(double)p)<INF)
          {
              printf("%d\n",p*n);
              continue;
          }
          int a=n/m;
          int b=n%m;
          ans=a*q+min(q,b*p);
          printf("%d\n",ans);
     }
     return 0;
}

