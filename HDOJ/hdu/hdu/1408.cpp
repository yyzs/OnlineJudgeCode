#include "stdio.h"
#include "math.h"
int main()
{int i,j;
 int t;
 double d,v,ans;
 while(scanf("%lf%lf",&v,&d)==2)
 {
   ans=0;
   t=0;
   for(i=1;;i++)
   {
     if(v-ans<=i*d)
         {
            for(j=1;j<=i;j++)
                { t+=1;
                  if(ans+d>=v)
                  {
                     printf("%d\n",t);
                     break;
                  }
                  else
                     ans=ans+d;
                }
            break;
         }
      else
         {
             ans+=(i*d);
             t=t+i+1;
         }
    }
  }
  return 0;
  }

