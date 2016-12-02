#include "stdio.h"
#include "math.h"
int prime(int a)
{int i,ok=1;
 if(a==2)
    return 1;
 for(i=2;i<=sqrt((double)a);i++)
     if(a%i==0)
        {ok=0;
         break;
         }
  return ok;
  }
int main()
{int n,a,i;
 int ans;
 while(scanf("%d",&n)==1)
 {ans=0;
  for(i=0;i<n;i++)
     {scanf("%d",&a);
      if(prime(a))
           ans++;
     }
  printf("%d\n",ans);
  }
  return 0;
  }
