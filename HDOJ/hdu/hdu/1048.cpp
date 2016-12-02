#include "stdio.h"
#include "string.h"
char c[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char ans[]="VWXYZABCDEFGHIJKLMNOPQRSTU";
char a[250];
int main()
{int i,n,len,j;
 memset(a,0,sizeof(a));
 while(scanf("%s",a)!=EOF&&strcmp(a,"ENDOFINPUT")!=0)
 {getchar();
  memset(a,0,sizeof(a));
  gets(a);
  len=strlen(a);
  for(i=0;i<len;i++)
  {for(j=0;j<26;j++)
       {if(a[i]==c[j])
             {a[i]=ans[j];
              break;
             }
       }
  }
  puts(a);
  scanf("%s",a);
  memset(a,0,sizeof(a));
  }
  return 0;
}

