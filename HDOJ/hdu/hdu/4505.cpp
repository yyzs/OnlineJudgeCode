#include "stdio.h"
#include "string.h"
int main()
{int c,n,a[16];
 int i,sum,j;
 scanf("%d",&c);
 sum=0;
 while(c--)
 {scanf("%d",&n);
  memset(a,0,sizeof(a));
  for(i=0;i<n;i++)
      scanf("%d",&a[i]);
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
      {
          if(a[j]<a[i])
            a[j]^=a[i]^=a[j]^=a[i];
      }
  sum=0;
  for(i=0;i<n;i++)
  {if(i==0)
      sum=a[0]*6+6;
   else
     {if(a[i]==a[i-1])
        sum+=1;
      else
        sum+=((a[i]-a[i-1])*6+6);
      }
   }
   printf("%d\n",sum+a[n-1]*4);
   }
    return 0;
  }
