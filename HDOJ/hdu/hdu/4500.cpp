#include "stdio.h"
#include "string.h"
#include "math.h"
int main()
{int a[23][23],b[23][23];
 int i,j;
 int max=0,r,l;
 int n,m;
 while(scanf("%d%d",&n,&m)==2)
 {if(n==0&&m==0)
        break;
  for(i=0;i<23;i++)
      for(j=0;j<23;j++)
        {
            a[i][j]=0;
            b[i][j]=0;
        }
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
     {if(a[i-1][j]*a[i][j]<0)
            b[i][j]+=(a[i-1][j]>0?a[i-1][j]:-a[i-1][j]);
      else
            b[i][j]+=(a[i-1][j]<0?a[i-1][j]:-a[i-1][j]);
      if(a[i][j-1]*a[i][j]<0)
            b[i][j]+=(a[i][j-1]>0?a[i][j-1]:-a[i][j-1]);
      else
            b[i][j]+=(a[i][j-1]<0?a[i][j-1]:-a[i][j-1]);
      if(a[i][j+1]*a[i][j]<0)
            b[i][j]+=(a[i][j+1]>0?a[i][j+1]:-a[i][j+1]);
      else
            b[i][j]+=(a[i][j+1]<0?a[i][j+1]:-a[i][j+1]);

      if(a[i+1][j]*a[i][j]<0)
            b[i][j]+=(a[i+1][j]>0?a[i+1][j]:-a[i+1][j]);
      else
            b[i][j]+=(a[i+1][j]<0?a[i+1][j]:-a[i+1][j]);
        }
      max=b[n][m];
      r=n;
      l=m;
      for(i=n;i>0;i--)
        {for(j=m;j>0;j--)
           if(b[i][j]>=max)
            {r=i;
             l=j;
             max=b[i][j];
             }
        }
       printf("%d %d %d\n",r,l,max);
     }
     return 0;
}

