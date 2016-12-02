#include "stdio.h"
main()
{
    int a,b,c;
    int n,i;
    float e;
    while(scanf("%d",&n)!=EOF)
     {  a=0;b=0;c=0;
        if(n==0) break;
         for(i=1;i<=n;i++)
          {
              scanf(" %f",&e);
              if(e<0) a++;
              if(e==0) b++;
              if(e>0) c++;
          }  
          printf("%d %d %d\n",a,b,c);     
     }
}
