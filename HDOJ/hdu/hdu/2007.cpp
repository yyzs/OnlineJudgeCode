#include "stdio.h"
#include "math.h"
main()
{int m,n,x,y,i,s=0;
 while(scanf("%d %d",&m,&n)!=EOF)
  {x=0;y=0;
   if(m>n) {
       s=m;m=n;n=s;
   }
   for(i=m;i<=n;i++)
    if(i%2==0) x+=pow(i,2);
     else y+=pow(i,3);
    printf("%d %d\n",x,y);    
  }
  return 0;
}

