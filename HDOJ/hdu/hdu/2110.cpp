#include "stdio.h"
#define N 10000
long long a1[10001],a2[10001];
long long b[101][2];
int main()
{long long sum,i,j,k,n;
 while(scanf("%I64d",&n)==1&&n)
 {sum=0;
  for(i=0;i<n;i++)
           {scanf("%I64d%I64d",&b[i][0],&b[i][1]);
            sum+=(b[i][0]*b[i][1]);
            }
  if(sum%3!=0)
           {printf("sorry\n");
            continue;
            }
  for(i=0;i<=sum;i++)
        {a1[i]=0;
         a2[i]=0;}
  for(i=0;i<=b[0][0]*b[0][1]&&i<=sum;i+=b[0][0])
         a1[i]=1;
  for(i=1;i<n;i++)
  {for(j=0;j<=sum;j++)
          for(k=0;k<=b[i][0]*b[i][1]&&k+j<=sum;k+=b[i][0])
                 {a2[k+j]=(a2[k+j]+a1[j]);
                  if(a2[k+j]%N!=0)
                     a2[k+j]%=N;
                 }
   for(j=0;j<=sum;j++)
          {a1[j]=a2[j];
           a2[j]=0;
           }
   }
   if(a1[sum/3])
           printf("%I64d\n",a1[sum/3]%N);
    else
           printf("sorry\n");
    }
    return 0;
    }

