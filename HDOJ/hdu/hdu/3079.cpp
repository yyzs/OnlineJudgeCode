#include "stdio.h"
#include "string.h"
char a[55];
int main()
{int len,i,t;
  memset(a,0,sizeof(a));
  scanf("%d",&t);
  while(t--)
  {scanf("%s",a);
    len=strlen(a);
    for(i=0;i<len;i++)
    {if(a[i]>='A'&&a[i]<='Z'&&a[i]!='A'&&a[i]!='E'&&a[i]!='O'&&a[i]!='U'&&a[i]!='I')
                 a[i]='a'-'A'+a[i];
     else
                 {if(a[i]>='a'&&a[i]<='z'&&(a[i]=='a'||a[i]=='e'||a[i]=='o'||a[i]=='u'||a[i]=='i'))
                          a[i]=a[i]-'a'+'A';
                 }
      }
      for(i=0;i<len;i++)
                  printf("%c",a[i]);
      printf("\n");
      memset(a,0,sizeof(a));
    }
    return 0;
    }

