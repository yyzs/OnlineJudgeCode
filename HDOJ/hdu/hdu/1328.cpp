#include "stdio.h"
#include "string.h"
char a[55];
int main()
{int t,cas,i,len;
 scanf("%d",&t);
 cas=0;
 while(t--)
 {cas++;
  memset(a,0,sizeof(a));
  scanf("%s",a);
  len=strlen(a);
  for(i=0;i<len;i++)
      {if(a[i]=='Y')
              a[i]='Z';
       else
              a[i]=(a[i]-64+1)%26+64;
      }
  printf("String #%d\n",cas);
  for(i=0;i<len;i++)
       printf("%c",a[i]);
  printf("\n\n");
  }
  return 0;
}
