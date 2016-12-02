#include "stdio.h"
int main()
{
 int a[100],b[100],n;
 int i,now,num,j;
 while(scanf("%d",&n)==1)
 {
  if(n==0)
      break;
  for(i=0;i<n;i++)
      scanf("%d%d",&a[i],&b[i]);
  for(i=0;i<n-1;i++)
     for(j=i+1;j<n;j++)
       if(b[j]<b[i])
         {
          b[j]^=b[i]^=b[j]^=b[i];
          a[j]^=a[i]^=a[j]^=a[i];
          }
   now=b[0];
   num=1;
   for(i=0;i<n;i++)
     {if(now<=a[i])
        {now=b[i];
         num++;
         }
      }
    printf("%d\n",num);
   }
   return 0;
 }
