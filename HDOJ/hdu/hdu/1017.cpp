#include "stdio.h"
int main()
{int n,m;
 int i,j,k,count=0,t,x;
 scanf("%d",&t);
   for(k=0;k<t;k++)
  { x=1;
    while(1)
   {scanf("%d%d",&n,&m);
    if(n==0&&m==0)
            break;
     count=0;
     for(i=1;i<n-1;i++)
      for(j=i+1;j<n;j++)
         if((i*i+j*j+m)%(i*j)==0)
            count++;
     printf("Case %d: %d\n",x++,count);
     }
     if(k!=t-1)
        printf("\n");
  }
   return 0;
   }

