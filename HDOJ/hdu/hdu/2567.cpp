#include "stdio.h"
#include "string.h"
char a[55],b[55];
int main()
{int t,lena,lenb;
 int i;
  scanf("%d",&t);
  while(t--)
  {memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%s%s",a,b);
    lena=strlen(a);
    lenb=strlen(b);
    for(i=0;i<lena/2;i++)
            printf("%c",a[i]);
    printf("%s",b);
    for(i=lena/2;i<lena;i++)
             printf("%c",a[i]);
    printf("\n");
    }
    return 0;
}

