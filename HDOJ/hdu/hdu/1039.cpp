#include "stdio.h"
#include "string.h"
char a[30];
int b[30];
int main()
{int i,j,ok;
 int len;
 memset(a,0,sizeof(a));
 memset(b,0,sizeof(b));
 while(scanf("%s",a))
 {if(strcmp(a,"end")==0)
         break;
  len=strlen(a);
  ok=1;
  if(len==1)
      if(a[0]=='a'||a[0]=='e'||a[0]=='i'||a[0]=='o'||a[0]=='u')
                 {printf("<%s> is acceptable.\n",a);
                  continue;
                  }
       else
                {printf("<%s> is not acceptable.\n",a);continue;}
  for(i=0;i<len-1;i++)
      if(a[i]==a[i+1]&&a[i]!='e'&&a[i]!='o')
           ok=0;
  if(!ok)
                 {printf("<%s> is not acceptable.\n",a);
                  continue;
                  }
  for(i=0;i<len;i++)
       if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
                   b[i]=1;
       else
                   b[i]=0;
  ok=0;
  for(i=0;i<len;i++)
               if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
                       ok=1;
   if(!ok)
                 {printf("<%s> is not acceptable.\n",a);continue;}
  ok=1;
  for(i=0;i<len-2;i++)
       if(b[i]==b[i+1]&&b[i+1]==b[i+2])
                  ok=0;
  if(!ok)
                 printf("<%s> is not acceptable.\n",a);
   else
                 printf("<%s> is acceptable.\n",a);
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
  }
  return 0;
  }

