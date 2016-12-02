#include "stdio.h"
#include "string.h"
int main()
{int a[5010],num[5010];
 int n,i,j,k;
 int sum=0;
 int ok;
 int t;
 scanf("%d",&t);
 while(t--)
 {scanf("%d",&n);
  for(i=1;i<=n;i++)
       {a[i]=0;
        num[i]=1;
        }
  sum=n;
  ok=1;
  while(sum>3)
  {if(ok)
       {j=0;
        for(i=1;i<=n;i++)
             {if(num[i])
                 {j++;
                  if(j%2==0)
                       num[i]=0;
                  }
              }
        ok=0;
        }
   else
       {j=0;
        for(i=1;i<=n;i++)
                {if(num[i])
                 {j++;
                  if(j%3==0)
                       num[i]=0;
                  }
             }
        ok=1;
        }
   sum=0;
   for(i=1;i<=n;i++)
         if(num[i]==1)
            sum++;
     }
    ok=0;
    for(i=1;i<=n;i++)
         {if(num[i]==1&&!ok)
               {printf("%d",i);
                ok=1;
                }
          else
             if(num[i]==1&&ok)
               printf(" %d",i);
         }
    printf("\n");
  }
  return 0;
  }

