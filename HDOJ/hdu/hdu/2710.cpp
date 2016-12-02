#include "stdio.h"
#include "string.h"
int a[20005];
int main()
{int i,j;
 int n,num,max,rel=0;
 memset(a,0,sizeof(a));
 for(i=4;i<=20005;i+=2)
    a[i]=1;
 for(i=3;i<=20005;i++)
    if(a[i]==0)
      {for(j=i*i;j<=20005;j+=i)
         a[j]=1;
      }
 while(scanf("%d",&n)==1)
 { rel=0;
   max=0;
    while(n--)
   {scanf("%d",&num);
    for(i=num;i>=2;i--)
      if(a[i]==0&&(num%i==0))
         break;
    if(i>max)
      {max=i;
       rel=num;
       }
    }
  printf("%d\n",rel);
  }
  return 0;
  }

