#include "stdio.h"
#include "math.h"
#include "string.h"
int a[1010];
int main()
{
   int t,n;
   int i,j;
   int ans;
   ans=0;
   memset(a,0,sizeof(a));
   for(j=2;j<=800000;j++)
    {ans=0;
     for(i=1;i*i<=j;i++)
          if(j%i==0)
             {if(i*i==j||i==1)
                    ans+=i;
              else
                    ans=ans+i+j/i;
              if(ans>1000)
                   break;
              }
    if(ans<=1000)
           a[ans]=1;
    }
   scanf("%d",&t);
   while(t--)
     {
         scanf("%d",&n);
         if(a[n])
              printf("no\n");
         else
              printf("yes\n");
     }
   return  0;
}

