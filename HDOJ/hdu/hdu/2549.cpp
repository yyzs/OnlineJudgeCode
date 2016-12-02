#include "stdio.h"
#include "string.h"
char a[1000];
int main()
{int t,i;
 int n;
 int len;
 scanf("%d",&t);
 while(t--)
 {memset(a,0,sizeof(a));
  scanf("%s%d",a,&n);
  len=strlen(a);
  for(i=0;i<len;i++)
        if(a[i]=='.')
           break;
  printf("%c\n",i+n>=len?'0':a[i+n]);
  }
  return 0;
}

