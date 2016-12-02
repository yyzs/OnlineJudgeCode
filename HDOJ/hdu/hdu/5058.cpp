#include "stdio.h"
#include "string.h"
long long a[110],b[110];
int main()
{
  int i;
  int j,n;
  while(scanf("%d",&n)==1)
{
   for(i=0;i<n;i++)
      scanf("%I64d",&a[i]);
   for(i=0;i<n;i++)
      scanf("%I64d",&b[i]);
   int ok=1;
   for(i=0;i<n;i++)
   {
       int temp=0;
       for(j=0;j<n;j++)
          {if(a[i]==b[j])
             {temp=1; break;}
          }
       if(!temp)
       {
           ok=0;
           break;
       }
   }
   for(i=0;i<n;i++)
   {
       int temp=0;
       for(j=0;j<n;j++)
          {if(b[i]==a[j])
             {temp=1; break;}
          }
       if(!temp)
       {
           ok=0;
           break;
       }
   }
   if(ok)
       puts("YES");
   else
       puts("NO");
}
   return 0;
}

