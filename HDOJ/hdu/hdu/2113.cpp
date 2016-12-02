#include "stdio.h"
#include "string.h"
char a[10];
int main()
{int i,len,sum,flag=0;
 while(scanf("%s",a)==1)
 {len=strlen(a);
  sum=0;
  for(i=0;i<len;i++)
    if((a[i]-48)%2==0)
       sum+=a[i]-48;
   if(flag==1)
      printf("\n");
    flag=1;
   printf("%d\n",sum);
   }
   return 0;
   }

