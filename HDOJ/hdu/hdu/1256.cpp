#include "stdio.h"
#include "string.h"
int main()
{int w,h;
 char c;
 int n,t,i,j;
 int flag=0,hs,hx;
 scanf("%d",&t);
 while(t--)
 {if(flag)
        printf("\n");
  else
        flag=1;
  getchar();
  scanf("%c %d",&c,&n);
  w=n/6+1;
  hs=(n-3)/2;
  hx=n-hs-3;
  for(i=1;i<=n;)
  {if(i==n)
        {for(j=1;j<=hx+2*w;j++)
             {if(j>w&&j<=hx+2*w-w)
                 printf("%c",c);
              else
                if(j<=w)
                 printf(" ");
              }
         printf("\n");
         i++;
         }
   else
        if(i==1||i==1+hs+1)
        {for(j=1;j<=hx+2*w;j++)
             {if(j>w&&j<=hx+2*w-w)
                 printf("%c",c);
              else
                if(j<=w)
                 printf(" ");
              }
         printf("\n");
         i++;
         }
    else
       if(i>1&&i<=1+hs)
          {for(j=1;j<=hx+2*w;j++)
              {if(j>w&&j<=hx+2*w-w)
                 printf(" ");
              else
                 printf("%c",c);
               }
           printf("\n");
           i++;
           }
    else
        if(i>2+hs&&i<=n-1)
           {for(j=1;j<=hx+2*w;j++)
              {if(j>w&&j<=hx+2*w-w)
                 printf(" ");
              else
                 printf("%c",c);
               }
           printf("\n");
           i++;
           }
    }
   }
   return 0;
}

