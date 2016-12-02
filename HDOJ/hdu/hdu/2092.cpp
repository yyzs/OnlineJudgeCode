#include "stdio.h"
#include "math.h"
int main()
{int m,n;
 int i;
 int ok=1,ans=0;
 while(1)
 {scanf("%d%d",&n,&m);
  if(n==0&&m==0)
     break;
  ok=0;
  ans=(m>=0?m:-m);
  for(i=-sqrt((double)ans);i<=sqrt((double)ans);i++)
    {if((n-i) *i==m)
       {ok=1;
        break;}
    }
  if(ok==1)
     printf("Yes\n");
  else
     printf("No\n");
  }
  return 0;
  }

