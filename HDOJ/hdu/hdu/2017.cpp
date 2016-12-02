#include "stdio.h"
#include "ctype.h"'
#include "string.h"
int main()
{int i,j,n,len,count=0;
 char s[10000];
 memset(s,0,sizeof(s));
 while(scanf("%d\n",&n)!=EOF)
 {for(i=0;i<n;i++)
   {gets(s);
    count=0;
    len=strlen(s);
    for(j=0;j<len;j++)
     if(!isalpha(s[j]))
       count++;
     printf("%d\n",count);
    }
  }
  return 0;
}
                                                                                                                                                                                                                               
   
