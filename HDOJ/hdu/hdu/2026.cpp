#include "stdio.h"
#include "string.h"
#include "ctype.h"
int main()
{char a[100];
 int len,i;
 memset(a,0,sizeof(a));
 while(gets(a))
 {
  len=strlen(a);
  for(i=0;i<len;i++)
   {if(i==0)
     a[i]=toupper(a[i]);
    if(a[i]==' ')
     a[i+1]=toupper(a[i+1]);
    printf("%c",a[i]);
    }
  printf("\n");
 }
 return 0;
}

