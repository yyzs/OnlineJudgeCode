#include "stdio.h"
#include "string.h"
char a[1001];
int main()
{int t,cas,i,j,len;
 scanf("%d",&t);
 cas=1;
 int ok=0;
 while(cas<=t)
 {memset(a,0,sizeof(a));
  scanf("%s",a);
  printf("Case #%d: ",cas);
  cas++;
  len=strlen(a);
  ok=0;
  if(a[len-1]=='u'&&a[len-2]=='s'&&a[len-3]=='e'&&a[len-4]=='d')
               ok=1;
  if(ok)
        {for(i=0;i<len-4;i++)
                  printf("%c",a[i]);
         printf("nanodesu");
         printf("\n");
         }
   else
         printf("%snanodesu\n",a);
   }
   return 0;
   }

