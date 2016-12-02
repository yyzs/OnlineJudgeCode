#include "stdio.h"
#include "string.h"
char a[1010];
int main()
{int i,j;
  int num;
  int len;
  memset(a,0,sizeof(a));
  while(gets(a))
  {len=strlen(a);
    j=0;
    num=0;
    for(i=0;i<len;i++)
    {if(a[i]=='B')
               break;
      if(a[i]==')')
               j++;
      num++;
    }
    printf("%d\n",num-j*2);
    memset(a,0,sizeof(a));
  }
  return 0;
}

