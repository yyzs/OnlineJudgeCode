#include "stdio.h"
long long a[101][101];
int main()
{
 int i,j,n,m,t;
 long long ans=0;
 for(i=0;i<101;i++)
    {a[i][0]=1;
     a[i][i]=1;
    }
  for(i=2;i<101;i++)
    for(j=1;j<i;j++)
       a[i][j]=a[i-1][j-1]+a[i-1][j];
   scanf("%d",&t);
   while(t--)
   {
        scanf("%d%d",&n,&m);
        ans=a[n+1][2]*a[m+1][2];
     printf("%I64d\n",ans); 
   }
   return 0;
}
