#include "stdio.h"
#include "string.h"
int m,k,sum;
int a[10][10];
int ans[10][10];
void mutiply1()
{int i,j,k;
  int temp[10][10];
  for(i=0;i<10;i++)
        for(j=0;j<10;j++)
        {temp[i][j]=0;
          for(k=0;k<10;k++)
                temp[i][j]=(temp[i][j]+ans[i][k]*a[k][j])%m;
         }
 for(i=0;i<10;i++)
        for(j=0;j<10;j++)
               ans[i][j]=temp[i][j];
}
void mutiply2()
{int i,j,k;
  int temp[10][10];
  for(i=0;i<10;i++)
        for(j=0;j<10;j++)
        {temp[i][j]=0;
          for(k=0;k<10;k++)
                temp[i][j]=(temp[i][j]+a[i][k]*a[k][j])%m;
         }
 for(i=0;i<10;i++)
        for(j=0;j<10;j++)
               a[i][j]=temp[i][j];
}
void slove1(int k)
{int i,j;
  for(i=0;i<10;i++)
       for(j=0;j<10;j++)
             {if(i==j)
                       ans[i][j]=1;
              else
                       ans[i][j]=0;
             }
  for(i=k;i;i/=2)
       {if(i&1)
                mutiply1();
         mutiply2();
        }
}
int main()
{int i,j;
  while(scanf("%d%d",&k,&m)==2)
  {
            for(i=0;i<10;i++)
                         scanf("%d",&a[0][i]);
            for(i=1;i<10;i++)
                        for(j=0;j<10;j++)
                             {if(i-1==j)
                                         a[i][j]=1;
                               else
                                         a[i][j]=0;
                              }
           sum=0;
           slove1(k-9);
           if(k<10)
                         printf("%d\n",k%m);
            else
                         {  for(i=0;i<10;i++)
                                      sum+=(ans[0][i]*(9-i))%m;
                             printf("%d\n",sum%m);
                             }
       }
       return 0;
}

