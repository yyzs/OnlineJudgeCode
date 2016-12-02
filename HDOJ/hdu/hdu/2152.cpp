#include "stdio.h"
#define N 100001
int a1[N],a2[N];
int arr[N][2];
int main()
{
 int n,m,i,j,k;
 while(scanf("%d%d",&n,&m)==2)
 {
   for(i=0;i<N;i++)
         {a1[i]=0;a2[i]=0;}
    for(i=0;i<n;i++)
         scanf("%d%d",&arr[i][0],&arr[i][1]);
    for(i=arr[0][0];i<=arr[0][1];i++)
         a1[i]=1;
    for(i=1;i<n;i++)
         {for(j=0;j<N;j++)
                for(k=arr[i][0];k<=arr[i][1]&&k+j<=m;k++)
                       a2[j+k]+=a1[j];
          for(j=0;j<N;j++)
              {a1[j]=a2[j];a2[j]=0;}
         }
    printf("%d\n",a1[m]);
 }
  return 0;
}

