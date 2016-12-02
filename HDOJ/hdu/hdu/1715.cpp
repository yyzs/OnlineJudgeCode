#include "stdio.h"
#include "string.h"
#define Max 1001
int a[1005][1005];
int add(int a[],int b[],int c[])
{int i,d=0;
 for(i=Max-1;i>=0;i--)
  {d=a[i]+b[i]+d;
   c[i]=d%10;
   d/=10;
   }
}
int main()
{int i,j;
 int n,p;
 memset(a[1],0,sizeof(a[1]));
 memset(a[2],0,sizeof(a[2]));
 a[1][Max-1]=1;
 a[2][Max-1]=1;
 for(i=3;i<=1000;i++)
     add(a[i-2],a[i-1],a[i]);
 scanf("%d",&n);
 while(n--)
 {scanf("%d",&p);
  for(i=0;i<Max&&a[p][i]==0;i++)
      ;
  for(;i<Max;i++)
    printf("%d",a[p][i]);
  printf("\n");
  }
  return 0;
  }

