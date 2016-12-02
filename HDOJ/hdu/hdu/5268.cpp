#include "stdio.h"
int main()
{
   int a[4]={1000,1500,2000,2500};
   int t,i;
   int b[4],cnt[4];
   int ans=0,cas=0;
   scanf("%d",&t);
   while(t--)
   {
       for(i=0;i<4;i++)
           scanf("%d%d",&b[i],&cnt[i]);
        ans=0;
        for(i=0;i<4;i++)
        {
            int temp=(250-b[i])*a[i]/250-cnt[i]*50;
            if(temp<a[i]*0.4)
                  temp=a[i]*0.4;
            ans+=temp;
        }
        cas++;
        printf("Case #%d: %d\n",cas,ans);
   }
   return 0;
}

