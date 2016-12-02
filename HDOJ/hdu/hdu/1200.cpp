#include "stdio.h"
#include "string.h"
char a[110][20];
char b[220];
int main()
{int len,i,j;
 int row,coloumn;
 int n;
 int m;
 while(scanf("%d",&n)==1&&n)
 {memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  scanf("%s",b);
  len=strlen(b);
  coloumn=n;
  row=len/coloumn;
  m=0;
  for(i=0;i<row;i++)
      {if(i%2==0)
         for(j=0;j<coloumn;j++)
             a[i][j]=b[m++];
       else
         for(j=coloumn-1;j>=0;j--)
             a[i][j]=b[m++];
      }
  for(j=0;j<coloumn;j++)
      for(i=0;i<row;i++)
          printf("%c",a[i][j]);
  printf("\n");
  }
  return 0;
}


