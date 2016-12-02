#include "stdio.h"
#include "string.h"
#include "stdlib.h"
char d[10][20]={"zero","one","two","three","four","five","six","seven","eight","nine"};
char input[50],c[50];
int main()
{int i,j,a,b;
  int len;
  int m;
  int ok;
  memset(input,0,sizeof(input));
  while(gets(input))
  {len=strlen(input);
    memset(c,0,sizeof(c));
    a=0;
    b=0;
    m=0;
    ok=0;
    for(i=0;i<len;i++)
    {
      if(input[i]==' '||input[i]=='+'||input[i]=='=')
                    {for(j=0;j<10;j++)
                              if(strcmp(d[j],c)==0)
                                     {if(ok)
                                            b=b*10+j;
                                       else
                                            a=a*10+j;
                                        }
                       if(input[i]=='+')
                                  ok=1;
                     memset(c,0,sizeof(c));
                     m=0;
                     }
      else
                   c[m++]=input[i];
        }
     if(a==0&&b==0)
                    break;
     printf("%d\n",a+b);
     memset(input,0,sizeof(input));
     }
     return 0;
}



