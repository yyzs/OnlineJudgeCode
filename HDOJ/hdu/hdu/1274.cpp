#include "stdio.h"
#include "string.h"
char s[300];
int isnumber(char c)
{
    if(c>='0'&&c<='9')
           return 1;
    return 0;
}
int doit(int pos)
{int k,p;
  while(s[pos]!=')'&&pos<strlen(s))
  {k=0;p=-1;
    while(isnumber(s[pos]))
    {k=k*10+s[pos]-'0';
      pos++;
     }
     if(k==0)  k=1;
     while(k--)
        if(s[pos]=='(')
              p=doit(pos+1);
        else
              printf("%c",s[pos]);
      if(p!=-1)
               pos=p;
       pos++;
     }
     return pos;
}
int main()
{int i,t;
  scanf("%d\n",&t);
  while(t--)
  {gets(s);
    doit(0);
    printf("\n");
    }
  return 0;
}

