#include "stdio.h"
#include "stdio.h"
char a[10010];
int main()
{int t,len=0;
 int i,j,count;
 scanf("%d",&t);
 while(t--)
 {memset(a,0,sizeof(a));
 scanf("%s",a);
  len=strlen(a);
  count=1;
  if(len==1)
     printf("%c\n",a[0]);
  else
  {
  for(i=1;i<len;i++)
    if(a[i]==a[i-1])
       {count++;
        if(i==len-1)
          printf("%d%c",count,a[i-1]);
       }
    else
      {if(count==1)
           printf("%c",a[i-1]);
       else
           {printf("%d%c",count,a[i-1]);
            count=1;
           }
        if(i==len-1)
            printf("%c",a[i]);
       }
   printf("\n");
   }
 }
   return 0;
   }

