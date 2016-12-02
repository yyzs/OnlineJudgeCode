#include "stdio.h"
int main()
{int a,b;
 int i;
 int flag=1;
 while(scanf("%d%d",&a,&b)==2)
 {if(a==0&&b==0)
      break;
  flag=1;
  for(i=0;i<=99;i++)
     if((a*100+i)%b==0)
        {if(!flag)
              printf(" ");
         else
              flag=0;
         printf("%02d",i);
        }
    printf("\n");
   }
   return 0;
}
