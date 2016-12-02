#include "stdio.h"
#include "string.h"
int main()
{char a[1000],b[]="(max)";
 int len,i,max;
 while(scanf("%s",a)!=EOF)
  {
   len=strlen(a);
   max=0;
   for(i=1;i<len;i++)
     if(a[i]>a[max])
        max=i;
   for(i=0;i<len;i++)
     {printf("%c",a[i]);
      if(a[max]==a[i])
        printf("%s",b);
      }
    printf("\n");
  }
  return 0;
}


