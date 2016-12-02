#include "stdio.h"
int f[1001][101];
int main()
{
    int n,k=100;
    int i,j;
    for(i=0;i<1001;i++)
      for(j=0;j<101;j++)
        f[i][j]=0;
    f[0][1]=1;
    f[1][1]=1;
    f[2][1]=2;
    f[3][1]=4;
    for(i=4;i<1001;i++)
       for(j=1;j<101;j++)
       {
           f[i][j]+=f[i-1][j]+f[i-2][j]+f[i-4][j];
           f[i][j+1]+=f[i][j]/10000;
           f[i][j]%=10000;
          }
   while(scanf("%d",&n)!=EOF)
    {
        k=100;
        while(!f[n][k--]);
        printf("%d",f[n][k+1]);
        for(;k>0;k--)
          printf("%04d",f[n][k]);
          printf("\n");
    }
    return 0;
}
