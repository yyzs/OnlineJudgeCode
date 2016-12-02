#include "stdio.h"
main()
{char a,b,c;
 while(scanf("%c%c%c\n",&a,&b,&c)!=EOF)
  {if(a<b&&a<c)
    if(b<c)     
     printf("%c %c %c\n",a,b,c);
    else
     printf("%c %c %c\n",a,c,b);
   if(b<a&&b<c)
      if(a<c)
          printf("%c %c %c\n",b,a,c);
     else
       printf("%c %c %c\n",b,c,a);
   if(c<a&&c<b)
      if(a<b)
        printf("%c %c %c\n",c,a,b);
      else
        printf("%c %c %c\n",c,b,a);
    }
    return 0;
}
