#include "stdio.h"
#include "string.h"
#define MAX 9973
int n;
int a[20][20],temp[20][20],res[20][20];
void mutiply1()
{
    int i,j,k;
    memset(temp,0,sizeof(temp));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
           for(k=0;k<n;k++)
               temp[i][j]=(temp[i][j]+res[i][k]*a[k][j])%MAX;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
           res[i][j]=temp[i][j];
}
void mutiply2()
{
     int i,j,k;
     memset(temp,0,sizeof(temp));
     for(i=0;i<n;i++)
           for(j=0;j<n;j++)
              for(k=0;k<n;k++)
                  temp[i][j]=(temp[i][j]+a[i][k]*a[k][j])%MAX;
      for(i=0;i<n;i++)
           for(j=0;j<n;j++)
              a[i][j]=temp[i][j];
}
void slove(int k)
{
   int i,j;
   for(i=0;i<n;i++)
        for(j=0;j<n;j++)
           {if(i==j)
              res[i][j]=1;
            else
               res[i][j]=0;
            }
   for(i=k;i;i/=2)
          {if(i&1)
               mutiply1();
           mutiply2();
           }
}
int main()
{int k;
 long long ans;
 int i,j;
 int t;
 scanf("%d",&t);
 while(t--)
 { scanf("%d%d",&n,&k);
    memset(a,0,sizeof(a));
   for(i=0;i<n;i++)
        for(j=0;j<n;j++)
              scanf("%d",&a[i][j]);
    slove(k);
    ans=0;
    for(i=0;i<n;i++)
               ans=(ans+res[i][i])%MAX;
    printf("%I64d\n",ans);
  }
  return 0;
}

