#include "stdio.h"
#include "string.h"
#include "stdlib.h"
char a[10000];
int main()
{int n,i,j;
 int flag;
 int len;
 int t;
 scanf("%d",&t);
 while(t--)
 {scanf("%d",&n);
  memset(a,0,sizeof(a));
  itoa(n,a,2);
  flag=0;
  len=strlen(a);
  for(i=len-1;i>=0;i--)
      {
          if(a[i]=='1')
           {
               if(!flag)
                      {printf("%d",len-1-i);
                       flag=1;
                      }
               else
                      printf(" %d",len-1-i);
           }
      }
   printf("\n");
  }
  return 0;
}

