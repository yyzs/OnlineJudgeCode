#include "stdio.h"
#include "string.h"
int lef[100],rig[100],sum[100];
int up[100];
int main()
{int i,j,n;
  int t;
  memset(lef,0,sizeof(lef));
  memset(rig,0,sizeof(rig));
  memset(sum,0,sizeof(sum));
  memset(up,0,sizeof(up));
  lef[1]=1;
  rig[1]=1;
  up[1]=1;
  sum[1]=3;
  for(i=2;i<=20;i++)
  {lef[i]=lef[i-1]+up[i-1];
    rig[i]=rig[i-1]+up[i-1];
    up[i]=sum[i-1];
    sum[i]=lef[i]+rig[i]+up[i];
    }
    scanf("%d",&t);
    while(t--)
    {scanf("%d",&n);
      printf("%d\n",sum[n]);
      }
      return 0;
    }

