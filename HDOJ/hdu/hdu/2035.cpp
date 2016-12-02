#include "math.h"
#include "stdio.h"
int main()
{
    int a,b,i,res;
    while(scanf("%d %d",&a,&b)==2)
    {
        if(a==0&&b==0)
           break;
        res=1;
        for(i=1;i<=b;i++)
          res=(res*a)%1000;
         printf("%d\n",res);
    }
    return 0;
}
