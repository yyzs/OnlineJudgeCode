#include "stdio.h"
#include "string.h"
#define MIN -10000000
int dp[10010];
int a[10010];
int ma(int a,int b)
{
    return a>b?a:b;
}
int main()
{int end;
 int k;
 int i;
 int max;
 int ans;
 int ok;
 while(scanf("%d",&k)==1&&k)
 {ok=0;
  for(i=0;i<k;i++)
        {scanf("%d",&a[i]);
         if(a[i]>=0)
            ok=1;
        }
  if(!ok)
       {
           printf("0 %d %d\n",a[0],a[k-1]);
           continue;
       }
  memset(dp,0,sizeof(dp));
  for(i=0;i<k;i++)
        {if(i==0)
               {dp[i]=a[i];
                 continue;
                }
         dp[i]=ma(dp[i-1]+a[i],a[i]);
         }
    max=MIN;
    for(i=0;i<k;i++)
         if(dp[i]>max)
             {max=dp[i];
              end=i;
              }
     ans=max;
     for(i=end;;i--)
          {if(end==0)
                 {printf("%d %d %d\n",ans,a[0],a[0]);
                  break;
                  }
           max-=a[i];
           if(max==0)
                   {printf("%d %d %d\n",ans,a[i],a[end]);
                    break;
                   }
           }
  }
  return 0;
}


