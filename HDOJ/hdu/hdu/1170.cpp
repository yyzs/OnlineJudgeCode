#include "stdio.h"
int main()
{int a,b,t=0;
 char c;
 scanf("%d",&t);
 while(t--)
 {  getchar();
     scanf("%c%d%d",&c,&a,&b);
    if(c=='+')
        printf("%d\n",a+b);
  if(c=='-')
        printf("%d\n",a-b);
  if(c=='*')
        printf("%d\n",a*b);
  if(c=='/')
        {if(a%b==0)
               printf("%d\n",a/b);
        else
              printf("%.2lf\n",(double)a/(double)b);
        }
 }
 return 0;
}

