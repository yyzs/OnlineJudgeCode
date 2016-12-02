#include "stdio.h"
#include "string.h"
long long a[1100]={0};
int main()
{long long ans[1100]={0};
 int n;
 long long i,j,max=0;
 while(scanf("%d",&n)!=EOF&&n)
 {
  for(i=0;i<n;i++)
     scanf("%I64d",&a[i]);
  for(i=0;i<n;i++)
   {if(i==0)
       ans[0]=a[0];
    else
    {max=a[i];
    for(j=0;j<i;j++)
       if(a[j]<a[i]&&ans[j]+a[i]>max)
          max=ans[j]+a[i];
     ans[i]=max;
    }
    }
  max=a[0];
  for(i=1;i<n;i++)
    if(ans[i]>max)
       max=ans[i];
  printf("%I64d\n",max);
  }
  return 0;
  }

