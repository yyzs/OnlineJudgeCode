#include "stdio.h"
#include "string.h"
#include "stdlib.h"
char a[30],b[20];
int main()
{int len,i,j,m;
  int c,d;
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  while(gets(a))
  {len=strlen(a);
    m=0;
    for(i=0;i<len;i++)
    {if(a[i]==' ')
           {c=atoi(b);
             memset(b,0,sizeof(b));
             m=0;
           }
      if(a[i]!=',')
              b[m++]=a[i];
       }
      d=atoi(b);
      memset(b,0,sizeof(b));
      printf("%d\n",c+d);
      }
      return 0;
}

