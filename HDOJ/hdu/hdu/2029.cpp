#include "stdio.h"
#include "string.h"
int main()
{char a[100];
 int i,n,ok,j,len;
 scanf("%d",&n);
 for(j=0;j<n;j++)
  {scanf("%s",a);
   len=strlen(a);
   ok=1; 
   for(i=0;i<len;i++)
    if(a[len-1-i]!=a[i])
       {ok=0;
        break;
       }
    if(ok) 
      printf("yes\n");
    else
      printf("no\n");
   }
  return 0;
}
