#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int a[1010];
int main()
{int i,j,k,ok=1,t;
 memset(a,0,sizeof(a));
 scanf("%d",&t);
 a[1]=1;
 for(i=2;i<=1000;i++)
  {for(j=1;j*j<=i;j++)
    {if(i%j==0&&j*j!=i)
      a[i]+=2;
    if(i%j==0&&j*j==i)
      a[i]+=1;}
  }
 while(t--)
 {scanf("%d",&k);
  ok=1;
  for(i=1;i<=1000;i++)
    if(a[i]==k)
     {
         ok=0;
         printf("%d\n",i);
         break;
     }
    if(ok==1)
      printf("-1\n");
  }
  return 0;
  }

