#include "stdio.h"
int main()
{int i,j;
 long long a[26][26];
 long long b[13];
 int n,m;
 long long ans;
  for(i=0;i<25;i++)
    {a[i][0]=1;
     a[i][i]=1;
     }
  for(i=0;i<26;i++)
    for(j=1;j<i;j++)
       a[i][j]=a[i-1][j-1]+a[i-1][j];
   b[1]=0;
   b[2]=1;
   for(j=3;j<13;j++)
       b[j]=(j-1)*(b[j-1]+b[j-2]);
  while(1)
  {scanf("%d",&n);
   if(n==0)  break;
   ans=1;
   for(i=n/2;i>=2;i--)
      ans+=a[n][i]*b[i];
   printf("%I64d\n",ans);
   }
   return 0;
   }


