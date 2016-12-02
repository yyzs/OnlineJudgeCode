#include "stdio.h"
#include "string.h"
#include "stdlib.h"
char a[110];
int main()
{int n,i,j;
 int len;
 int beg;
 int end;
 char c;
 int t;
 scanf("%d",&t);
 while(t--)
 {scanf("%d",&n);
  memset(a,0,sizeof(a));
  itoa(n,a,10);
  len=strlen(a);
  if(len==1)
          {printf("%d\n",n);
           continue;
           }
  if(a[0]=='-')
        beg=1;
  else
        beg=0;
  for(i=len-1;i>=0;i--)
        if(a[i]!='0')
          {end=i;
           break;
           }
  for(i=0;i<beg;i++)
         printf("%c",a[i]);
  for(i=end;i>=beg;i--)
          printf("%c",a[i]);
  for(i=end+1;i<len;i++)
          printf("%c",a[i]);
   printf("\n");
    }
    return 0;
 }

