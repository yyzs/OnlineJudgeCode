#include "stdio.h"
#include "string.h"
char a[100];
int main()
{int odd,even,len;
 int i,j;
 int sum;
 while(scanf("%s",a)!=EOF&&a[0]!='#')
  {len=strlen(a);
   sum=0;
   for(i=0;i<len-1;i++)
    if(a[i]=='1')
       sum+=1;
   if(a[len-1]=='e'&&sum%2==0)
      {a[len-1]='0';
       puts(a);
       }
   if(a[len-1]=='e'&&sum%2==1)
      {a[len-1]='1';
       puts(a);
       }
   if(a[len-1]=='o'&&sum%2==0)
      {a[len-1]='1';
       puts(a);
       }
    if(a[len-1]=='o'&&sum%2==1)
      {a[len-1]='0';
       puts(a);
       }
    }
    return 0;
    }

