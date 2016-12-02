#include "stdio.h"
#include "string.h"
#include "math.h"
int mod(int a,int b,int c)
{
    long long ans=1;
    while(b)
    {
        if(b%2==1)
            ans=ans*a%c;
        b/=2;
        a=a*a%c;
    }
    return ans;
}
int main()
{int n,i;
 while(scanf("%d",&n)==1)
 {
     if(n%2==0||n<=1)
         {
             printf("2^? mod %d = 1\n",n);
             continue;
         }
     for(i=1;;i++)
         {
            if(mod(2,i,n)==1)
                 {
                     printf("2^%d mod %d = 1\n",i,n);
                     break;
                 }
         }
  }
  return 0;
}

