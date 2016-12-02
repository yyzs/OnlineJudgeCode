#include "stdio.h"
char a[7]={'Z','J','U','T','A','C','M'};
int main()
{int i,j,m;
 int c,d;
 int t;
 char s;
 scanf("%d",&t);
 while(t--)
 {scanf("%d",&m);
  while(m--)
   {scanf("%d%d",&c,&d);
    s=a[d-1];
    a[d-1]=a[c-1];
    a[c-1]=s;
    }
  for(i=0;i<7;i++)
     if(a[i]=='J')
         {printf("%d\n",i+1);
          break;
          }
    a[0]='Z';
    a[1]='J';
    a[2]='U';
    a[3]='T';
    a[4]='A';
    a[5]='C';
    a[6]='M';
   }
   return 0;
   }

