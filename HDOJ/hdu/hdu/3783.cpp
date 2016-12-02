#include "stdio.h"
#include "string.h"
char a[1000];
int main()
{int z,o,j;
 int len;
 int i;
 memset(a,0,sizeof(a));
 while(gets(a))
 {if(a[0]=='E')
           break;
   len=strlen(a);
   z=0;
   o=0;
   j=0;
   for(i=0;i<len;i++)
    {if(a[i]=='Z')
             z++;
      if(a[i]=='O')
             o++;
      if(a[i]=='J')
              j++;
      }
      for(i=0;i<len;i++)
      {if(z!=0)
             {printf("Z");
               z--;
               }
        if(o!=0)
              {printf("O");
                o--;
                }
        if(j!=0)
               {printf("J");
                 j--;
                 }
         }
         printf("\n");
        }
        return 0;
}

