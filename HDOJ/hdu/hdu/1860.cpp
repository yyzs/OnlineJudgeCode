#include "stdio.h"
#include "string.h"
char a[10],b[90];
int n[10];
int main()
{int i,j;
  int len1,len2;
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  while(gets(a))
  {if(strchr(a,'#')!=NULL)
              break;
    gets(b);
    if(strchr(a,'#')!=NULL||strchr(b,'#')!=NULL)
                     break;
     len1=strlen(a);
     len2=strlen(b);
     for(i=0;i<len1;i++)
     {n[i]=0;
       for(j=0;j<len2;j++)
              if(a[i]==b[j])
                  n[i]++;
       }
       for(i=0;i<len1;i++)
               printf("%c %d\n",a[i],n[i]);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        }
        return 0;
}

