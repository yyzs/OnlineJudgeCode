#include "stdio.h"
#include "string.h"
int a[100];
int main()
{int n,i,max;
 while(1)
 {scanf("%d",&n);
  if(n==0)
     break;
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  max=a[0];
  for(i=0;i<n;i++)
    if(a[i]>max)
      max=a[i];
  printf("%d\n",max);
  }
  return 0;
  }

