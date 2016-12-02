#include "stdio.h"
#include "math.h"
int a[100],b[100],c[100];
int main()
{int i,j,s;
 int n;
  while(scanf("%d",&n)!=EOF)
 {if(n==0)
    break;
   for(i=0;i<n;i++)
     {scanf("%d",&a[i]);
      b[i]=abs(a[i]);
      if(a[i]>=0)
        c[i]=1;
       else
         c[i]=-1;
       }
     for(i=0;i<n;i++)
       for(j=i+1;j<n;j++)
         if(b[j]>b[i])
            {
              s=b[i];
              b[i]=b[j];
              b[j]=s;
              s=c[i];
              c[i]=c[j];
              c[j]=s;
              }
       for(i=0;i<n;i++)
         {if(i==0)
             printf("%d",b[i]*c[i]);
          else
             printf(" %d",b[i]*c[i]);
         }
       printf("\n");
     }
    return 0;
}

