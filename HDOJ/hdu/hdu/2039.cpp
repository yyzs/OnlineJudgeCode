#include "stdio.h"
#include "math.h"
int main()
{int ok,m,i;
 double a,b,c;
 while(scanf("%d",&m)!=EOF)
  {for(i=0;i<m;i++)
   {scanf("%lf%lf%lf\n",&a,&b,&c);
    ok=0;
    if(a+b>c&&a+c>b&&b+c>a&&abs(a-c)<b&&abs(a-b)<c&&abs(b-c)<a)
      ok=1;
    if(ok)
     printf("YES\n");
    else
     printf("NO\n");
    }
   }
    return 0;
 }
