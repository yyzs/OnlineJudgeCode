#include "stdio.h"
long long sum[100010];
int main()
{long long i,j;
 int n;
 for(j=0;j<=100000;j++)
          sum[j]=0;
 sum[1]=1;
 for(i=2;i<=100000;i++)
      {if(i%3==0)
          sum[i]=sum[i-1]+i*i*i;
       else
          sum[i]=sum[i-1]+i;
      }
  while(scanf("%d",&n)==1)
       {if(n<0)
            break;
        printf("%I64d\n",sum[n]);
       }
  return 0;
  }

