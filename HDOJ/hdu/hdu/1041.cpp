#include "stdio.h"
#include "string.h"
#define MAXN 1002
int  a[MAXN][MAXN];

int  add(int c[1000],int b[1000])
{int i,j;
  int temp=0;
  for(i=1000;i>=0;i--)
  {temp=c[i]+b[i]+temp;
    c[i]=temp%10;
    temp/=10;
    }
}
int main()
{int i,j,n;
 for(i=0;i<=1000;i++)
            memset(a[i],0,sizeof(a[i]));
  a[1][1000]=0;
  a[2][1000]=1;
  a[3][1000]=1;
  a[4][1000]=3;
  for(i=5;i<=1000;i++)
   {add(a[i],a[i-1]);
     add(a[i],a[i-2]);
     add(a[i],a[i-2]);
     }
    while(scanf("%d",&n)==1)
    {for(i=0;i<1000&&a[n][i]==0;i++);
      for(;i<=1000;i++)
                 printf("%d",a[n][i]);
      printf("\n");
      }
     return 0;
    }

