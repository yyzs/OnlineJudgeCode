#include "stdio.h"
int max(int m,int b)
{
    return m>=b?m:b;
}
int main()
{int a[100][100];
 int t,n,i,j;;
 scanf("%d",&t);
 while(t--)
  {scanf("%d",&n);
   for(i=0;i<n;i++)
     for(j=0;j<=i;j++)
        scanf("%d",&a[i][j]);
   for(i=n-1;i>0;i--)
   {   for(j=0;j<=i;j++)
          a[i-1][j]=max(a[i][j]+a[i-1][j],a[i][j+1]+a[i-1][j]);
   }
   printf("%d\n",a[0][0]);
  }
  return 0;
}


