#include "stdio.h"
#include "string.h"
char a[300];
int main()
{int sum,i,len;
  memset(a,0,sizeof(a));
  while(gets(a))
  {
    if(strcmp(a,"#")==0)
           break;
    len=strlen(a);
    sum=0;
    for(i=0;i<len;i++)
         if(a[i]!=' ')
             {sum=sum+(i+1)*(a[i]-'A'+1);
             }
    printf("%d\n",sum);
    memset(a,0,sizeof(a));
    }
    return 0;
    }

