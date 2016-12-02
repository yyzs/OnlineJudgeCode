#include "stdio.h"
long long a[22][22];
int main()
{int i,j,n,m;
 for(i=0;i<=20;i++)
     memset(a[i],0,sizeof(a[i]));
 for(i=0;i<=20;i++)
     a[i][0]=1;
 for(i=1;i<=20;i++)
   for(j=i;j<=20;j++)
       a[j][i]=a[j-1][i]+a[j][i-1];
 while(scanf("%d%d",&m,&n)==2)
    printf("%I64d\n",a[m][n]);
  return 0;
  }

