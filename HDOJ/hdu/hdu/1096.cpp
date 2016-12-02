#include "stdio.h"
int main()
{int n,m;
 int i,j,sum,a;
 while(scanf("%d",&n)==1)
  {for(i=0;i<n;i++)
    {scanf("%d",&m);
     sum=0;
     for(j=0;j<m;j++)
      {
       scanf(" %d",&a);
       sum+=a;
       }
      printf("%d\n",sum);
      if(i!=n-1)
        printf("\n");
     }
  }
  return 0;
 }

