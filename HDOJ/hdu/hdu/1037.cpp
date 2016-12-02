#include "stdio.h"
int main()
{int a,ok=1,ans=0;
 while(scanf("%d",&a)==1)
 {if(ok==0)
     continue;
  if(a<=168)
     {ans=a;
      ok=0;
      }
  }
  if(ok)
     printf("NO CRASH\n");
  else
     printf("CRASH %d\n",ans);
  return 0;
  }
