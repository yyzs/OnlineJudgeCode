#include "stdio.h"
long long a[51];
int main()
{int n,i;
 a[0]=0;
 a[1]=1;
 for(i=2;i<50;i++)
   a[i]=a[i-1]+a[i-2];
 while(1)
 {
  scanf("%d",&n);
  if(n==-1)
    break;
  if(n==50)
     printf("12586269025\n");
  else
     printf("%I64d\n",a[n]);
  }
  return 0;
}
