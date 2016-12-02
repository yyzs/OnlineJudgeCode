#include "stdio.h"
#include "string.h"
int gcd(int a,int b)
{
     if(a%b==0)
                 return b;
    else
                 return gcd(b,a%b);
}
int main()
{int n,m;
 while(scanf("%d%d",&n,&m)==2)
 {if(n==-1&&m==-1)
          break;
   if(gcd(n,m)==1)
            printf("YES\n");
   else
            printf("POOR Haha\n");
 }
 return 0;
}

