#include "stdio.h"
#include "string.h"
char a[1005];
int main()
{int i,len;
 memset(a,0,sizeof(a));
  while(gets(a))
  {len=strlen(a);
   for(i=0;i<len;i++)
       if(a[i]>=65&&a[i]<=90)
            a[i]+=32;
    puts(a);
    memset(a,0,sizeof(a));
  }
  return 0;
}

