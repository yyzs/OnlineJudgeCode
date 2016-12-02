#include "stdio.h"
#include "string.h"
char a[80];
int main()
{int len,j,i;
 int t;
 scanf("%d",&t);
 getchar();
 while(t--)
 {memset(a,0,sizeof(a));
  gets(a);
  len=strlen(a);
  for(i=len-1;i>=0;i--)
         if(a[i]!='\n')
               printf("%c",a[i]);
  printf("\n");
  }
  return 0;
  }

