#include "stdio.h"
int a[100010][15]={0};
int max(int a,int b,int c)
{
    if(b>a)
       a=b;
    if(c>a)
       a=c;
    return a;
    }
int ma(int a,int b)
{
     return a>=b?a:b;
}
int main()
{int n,i,j;
 int x,t,time,m=-1;
 while(1)
 {m=-1;
  scanf("%d",&n);
  if(n==0)
     break;
  for(i=0;i<100000;i++)
    for(j=0;j<11;j++)
       a[i][j]=0;
  for(i=0;i<n;i++)
     {scanf("%d%d",&x,&t);
      a[t][x]+=1;
      if(t>m)
        m=t;
     }
  /*for(i=0;i<=m;i++)
      {for(j=0;j<11;j++)
         printf("%d",a[i][j]);
       printf("\n");
      }*/
  for(i=m;i>0;i--)
     {  for(j=0;j<11;j++)
             if(j!=0&&j!=10)
                  a[i-1][j]=max(a[i][j]+a[i-1][j],a[i][j-1]+a[i-1][j],a[i][j+1]+a[i-1][j]);
              else
                 if(j==0)
                  a[i-1][j]=ma(a[i-1][j]+a[i][j],a[i-1][j]+a[i][j+1]);
             else
                  if(j==10)
                  a[i-1][j]=ma(a[i-1][j]+a[i][j-1],a[i-1][j]+a[i][j]);
     }
   printf("%d\n",a[0][5]);
 }
 return 0;
}

