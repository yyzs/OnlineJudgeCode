#include "stdio.h"
int main()
{
    int a[77][77];
    int w,h,i,j;
    while(scanf("%d%d",&w,&h)==2)
    {
      for(i=0;i<=h+1;i++)
          {for(j=0;j<=w+1;j++)
          {
              if((i==0||i==h+1)&&(j==0||j==w+1))
                  printf("+");
            else
               if((i==0||i==h+1)&&j!=0&&j!=w+1)
                 printf("-");
            else
               if((j==0||j==w+1)&&i!=0&&i!=h+1)
                 printf("|");
            else
               printf(" ");
               }    
         printf("\n");
          }
         printf("\n");
    }
    return 0;
}
