#include "stdio.h"
#include "string.h"
#include "math.h"
#define Max 1000000007
long long  a[10010],b[10010];
int main()
{long long T,t,n,k,i,j,sum=1,len;
 scanf("%I64d",&T);
 while(T--)
 {scanf("%I64d%I64d%I64d",&n,&t,&k);
  for(i=0;i<n;i++)
       scanf("%I64d",&a[i]);
  sum=1;
  len=t;
  while(t>0)
     {if(t%2==0)
          {t/=2;
           k=k%Max*k%Max;
           }
      else
          {t--;
           sum=sum*k%Max;
          }
       }
    sum%=Max;
    for(i=0;i<n;i++)
       a[i]=a[i]*sum%Max;
    len=len%n;
    for(i=0;i<n;i++)
       b[(i+len)%n]=a[i];
    for(i=0;i<n;i++)
      {if(i==0)
         printf("%I64d",b[i]);
       else
         printf(" %I64d",b[i]);
       }
    printf("\n");
    }
    return 0;
}



