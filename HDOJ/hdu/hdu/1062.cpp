#include "stdio.h"
#include "string.h"
char a[1010];
int main()
{int  n;
 int begin;
 int i,j;
 int len;
 scanf("%d",&n);
 getchar();
 while(n--)
 {memset(a,0,sizeof(a));
  gets(a);
  len=strlen(a);
  begin=0;
  for(i=0;i<len;i++)
     {if(a[i]==' ')
              {for(j=i-1;j>=begin;j--)
                       printf("%c",a[j]);
                printf("%c",a[i]);
                 begin=i+1;
              }
        if(i==len-1)
        {for(j=i;j>=begin;j--)
                printf("%c",a[j]);
        }
     }
  printf("\n");
  }
  return 0;
  }

