#include "stdio.h"
#include "math.h"
int main()
{
    int m,i;
    double n,sum;
    while(scanf("%lf %d\n",&n,&m)!=EOF)
    {sum=n;
     for(i=2;i<=m;i++)
      {
          n=sqrt(n);
          sum+=n;
         }
      printf("%.2f\n",sum);
        }
     return 0;
}
