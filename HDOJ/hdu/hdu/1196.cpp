#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
char a[1000];
int main()
{int n,i;
  int len;
  int ans;
  while(scanf("%d",&n)==1&&n)
  {memset(a,0,sizeof(a));
    itoa(n,a,2);
    len=strlen(a);
    for(i=len-1;i>=0;i--)
          if(a[i]=='1')
               break;
    ans=(int)pow(2.0,(double)(len-i-1));
    printf("%d\n",ans);
    }
    return 0;
}

