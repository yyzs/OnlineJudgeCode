#include "stdio.h"
#include "math.h"
#include "stdlib.h"
int a1[10001],a2[10001];
int b[101];
int main()
{
 int n,i,j,k;
 int sum,ans,ok;
 while(scanf("%d",&n)==1)
 {sum=0;
  for(i=0;i<n;i++)
      {scanf("%d",&b[i]);
       sum+=b[i];
       }
  for(i=0;i<=sum;i++)
      {a1[i]=0;
       a2[i]=0;}
 a1[0]=1;
 a1[b[0]]=1;
  for(i=1;i<n;i++)
      {for(j=0;j<=sum;j++)
          for(k=0;k<=b[i];k+=b[i])
               {a2[k+j]+=a1[j];
                a2[abs(k-j)]+=a1[j];
               }
       for(j=0;j<=sum;j++)
          {a1[j]=a2[j];
           a2[j]=0;
           }
       }
  ans=0;
  for(i=1;i<=sum;i++)
        if(a1[i]==0)
         ans++;
  printf("%d\n",ans);
  if(ans!=0)
     {ok=0;
      for(i=1;i<=sum;i++)
        {if(a1[i]==0)
            {if(ok==0)
               {printf("%d",i);ok=1;}
             else
                printf(" %d",i);
            }
         }
      printf("\n");
      }
  }
  return 0;
  }

