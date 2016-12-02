#include "stdio.h"
#include "string.h"
int main()
{
    long long ans,temp1,temp2,i,n,k,temp1n,temp2n;
    int cas=0;
    int ok;
    while(scanf("%I64d%I64d",&n,&k)==2,n+k)
    {
        ok=1;
        temp1=-100000;
        temp2=-100000;
        temp1n=0;
        temp2n=0;
        for(i=1;i<=k;i++)
        {if(n%i==0)
                      continue;
         else
         {
             temp1n=n%i;
             temp2n=i-n%i;
             n+=temp2n;
             if(temp1n-temp1==1&&temp2n==temp2&&i>=10000)
                    {ok=0;break;}
             temp1=temp1n;
             temp2=temp2n;
         }
        }
        if(ok)
        { cas++;
           ans=n;
           printf("Case #%d: %I64d\n",cas,ans);
           continue;
        }
       // printf("%d\n",i);
        ans=n+temp2n*(k-i);
        cas++;
        printf("Case #%d: %I64d\n",cas,ans);
    }
    return 0;
}
