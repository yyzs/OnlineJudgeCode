#include "stdio.h"
int a[50][5];
double b[50];
double c[5];
int main()
{int n,m,count,ok;
 int i,j;
 while(scanf("%d%d",&n,&m)==2)
  {
   count=0;
   for(i=0;i<n;i++)
    {
     b[i]=0;
     for(j=0;j<m;j++)
       {scanf("%d",&a[i][j]);
        b[i]+=a[i][j];
        }
      b[i]/=m;
     }
     for(j=0;j<m;j++)
      {
       c[j]=0;
       for(i=0;i<n;i++)
         c[j]+=a[i][j];
        c[j]/=n;
       }
      for(i=0;i<n;i++)
        {ok=1;
         for(j=0;j<m;j++)
           {if(a[i][j]<c[j])
             {ok=0;
              break;
              }
            }
          if(ok)
            count++;
        }
       for(i=0;i<n-1;i++)
         printf("%.2lf ",b[i]);
       printf("%.2lf\n",b[n-1]);
       for(j=0;j<m-1;j++)
          printf("%.2lf ",c[j]);
        printf("%.2lf\n",c[m-1]);
        printf("%d\n\n",count);
     }
     return 0;
    }



