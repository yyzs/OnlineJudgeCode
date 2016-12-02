#include "stdio.h"
int a1[200],a2[200];
int prime(int x)
{
    int i,ok=1;
    for(i=2;i*i<=x;i++)
        if(x%i==0)
          ok=0;
    return ok;
}
int main()
{
  int i,j,d,k;
  int n,t;
  scanf("%d",&t);
  while(t--)
  {scanf("%d",&n);
   for(i=0;i<=n;i++)
        {a1[i]=0;
         a2[i]=0;
         }
   if(n==2)
        {printf("1\n");
         continue;
         }
   for(i=0;i<=n;i+=2)
        a1[i]=1;
   d=2;
   for(i=1;i<n;i++)
    { d++;
      if(prime(d))
      {for(j=0;j<=n;j++)
          for(k=0;k+j<=n;k+=d)
              a2[k+j]+=a1[j];
       for(j=0;j<=n;j++)
             {a1[j]=a2[j];
              a2[j]=0;
              }
         }
     }
     printf("%d\n",a1[n]);
     }
     return 0;
     }


