#include "stdio.h"
#include "string.h"
#include "math.h"
int main()
{
    int n,i;
    while(scanf("%d",&n)==1)
    {
        if(!n)
            {
                printf("NO!\n");
                continue;
            }
         else
           {
             n+=1;
              while(n%2==0||n%3==0)
                   {
                       if(n%2==0)
                            n/=2;
                        else
                            n/=3;
                   }
               if(n==1)
                     printf("YES!\n");
               else
                     printf("NO!\n");
           }
    }
    return 0;
}

