#include "stdio.h"
#include "ctype.h"
int main()
{
    int y,t,i;
    char c;
    scanf("%d",&t);    
    for(i=0;i<t;i++)
      { scanf("%s%d",&c,&y);
       if(c>='a'&&c<='z')
         printf("%d\n",-1*c+y+96);
       else
        printf("%d\n",c+y-64);
         }
      return 0;
}
