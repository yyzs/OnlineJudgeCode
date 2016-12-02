#include "stdio.h"
int main()
{
 int a1[1000],a2[1000];
 int i,j,k;
 int n;
 while(scanf("%d",&n)==1&&n)
 {
   for(i=0;i<=n;i++)
                {a1[i]=0;a2[i]=0;}
    for(i=0;i<=n;i++)
                 a1[i]=1;
    for(i=2;i<=n;i++)
              {for(j=0;j<=n;j++)
                      for(k=0;k+j<=n;k+=i)
                      {
                         a2[j+k]+=a1[j];
                      }
                for(j=0;j<=n;j++)
                       {a1[j]=a2[j];a2[j]=0;}
              }
    printf("%d\n",a1[n]);
}
return 0;
}

