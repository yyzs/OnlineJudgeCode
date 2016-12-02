#include "stdio.h"
#include "string.h"
long long a[32][32];
int main()
{int i,j;
 int m,n,t;
 scanf("%d",&t);
 for(i=0;i<=30;i++)
   {a[i][0]=1;
    a[i][i]=1;
    }
 for(i=2;i<=30;i++)
  for(j=1;j<=i;j++)
    a[i][j]=a[i-1][j]+a[i-1][j-1];
 while(t--)
 {scanf("%d%d",&n,&m);
  printf("%I64d\n",a[n][m]);
  }
  return 0;
  }

