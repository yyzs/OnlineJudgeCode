#include "stdio.h"
long long f[35],g[35];
long long n;
int main()
{long long i,j;
  f[0]=1;
  g[0]=0;
  f[1]=3;
  g[1]=1;
  for(i=2;i<=33;i++)
      {
         f[i]=3*f[i-1]+2*g[i-1];
         g[i]=f[i-1]+g[i-1];
         }
  while(scanf("%I64d",&n)==1)
          {if(n==-1)
                   break;
            printf("%I64d, %I64d\n",f[n],g[n]);
            }
    return 0;
}

