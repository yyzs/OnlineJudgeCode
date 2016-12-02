#include "stdio.h"
#include "string.h"
int main()
{int n;
 long long a[36];
 int t=0,i,j;
 memset(a,0,sizeof(a));
 a[0]=1;
 a[1]=1;
 for(i=2;i<36;i++)
    for(j=0;j<i;j++)
       a[i]+=a[j]*a[i-j-1];
 while(scanf("%d",&n)==1&&n!=-1)
    {t++;
     printf("%d %d %I64d\n",t,n,2*a[n]);
     }
  return 0;
  }

