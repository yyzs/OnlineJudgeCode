#include "stdio.h"
#include "string.h"
int main()
{int n,i,j;
 int a,b,c;
 int ok;
 scanf("%d",&n);
 while(n--)
 {scanf("%d%d%d",&a,&b,&c);
  ok=0;
  for(i=1000;i<=9999;i++)
        if(i%a==0&&(i+1)%b==0&&(i+2)%c==0)
            {ok=1;
             break;
             }
   if(ok)
        printf("%d\n",i);
   else
        printf("Impossible\n");
  }
  return 0;
  }

