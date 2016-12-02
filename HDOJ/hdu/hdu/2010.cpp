#include "stdio.h"
#include "math.h"
int main()
{
    int m,n,i;
    int count,flag;
    while(scanf("%d %d\n",&m,&n)!=EOF)
    {
        count=0;
        flag=0;
        for(i=m;i<=n;i++)
         {
             if(i==pow(i/100,3)+pow(i%100/10,3)+pow(i%10,3))
               {flag++;
                if(flag==1) {printf("%d",i);count=1;}
                 else printf(" %d",i);
                 }
          }
          if(!count) 
            printf("no\n");
          else
           printf("\n");
    }
    return 0;
}
