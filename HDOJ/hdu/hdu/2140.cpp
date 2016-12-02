#include "stdio.h"
#include "string.h"
char a[10010];
char b[9]={'b','q','t','m','i','c','a','e','l'};
char c[9]={' ',',','!','l','e','a','c','i','m'};
int main()
{int len,i,j;
  memset(a,0,sizeof(a));
  while(scanf("%s",a)!=EOF)
  {len=strlen(a);
    for(i=0;i<len;i++)
        for(j=0;j<9;j++)
           if(a[i]==b[j])
               {a[i]=c[j];
                 break;
               }
     for(i=0;i<len;i++)
         printf("%c",a[i]);
     printf("\n");
     memset(a,0,sizeof(a));
     }
     return 0;
}

