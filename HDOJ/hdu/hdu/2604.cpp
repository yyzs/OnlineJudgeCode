#include "stdio.h"
#include "string.h"
char a[1000002][32];
int main()
{int i,j;
 int n,m;
 memset(a,0,sizeof(a));
 for(i=1;i<=30;i++)
    {a[1][i]=2%i;
     a[2][i]=4%i;
     a[3][i]=6%i;
     a[4][i]=9%i;
     for(j=5;j<=1000000;j++)
          a[j][i]=(a[j-1][i]+a[j-3][i]+a[j-4][i])%i;
    }
 while(scanf("%d%d",&n,&m)==2)
     printf("%d\n",a[n][m]);
 return 0;
}

