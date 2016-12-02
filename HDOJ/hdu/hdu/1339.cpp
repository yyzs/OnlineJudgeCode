#include "stdio.h"
#include "string.h"
#include "math.h"
int main()
{long long ans,i,n,t,a,p,j,ok;
 scanf("%I64d",&t);
 while(t--)
 {scanf("%I64d",&n);
  ok=0;
  for(i=1;i<=n;i+=2)
  {if(n%i==0)
      {for(j=0;;j++)
       {ans=i*(long long)pow(2.0,(double)j);
       if(ans>n)
            break;
       if(ans==n)
            {ok=1;
             break;
             }
       }
      }
    if(ok)
       {printf("%I64d %I64d\n",i,j);
        break;
        }
    }
  }
  return 0;
}

