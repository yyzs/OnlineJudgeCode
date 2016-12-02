#include "stdio.h"
#include "string.h"
char a[220];
int main()
{
  int n;
  int r1,r2,r3,m1,m2,m3;
  int len,i;
  while(scanf("%d%d",&m1,&m2)==2)
  {
     r1=0;r2=0;r3=0;
     memset(a,0,sizeof(a));
     scanf("%s",a);
     len=strlen(a);
     for(i=0;i<len;i++)
        {
           if(a[i]=='A')
                {
                   r1=m1;
                 }
           if(a[i]=='B')
                {
                  r2=m2;
                  }
           if(a[i]=='C')
                {
                  m1=r3;
                  }
           if(a[i]=='D')
                 {
                  m2=r3;
                  }
           if(a[i]=='E')
                 {
                    r3=r1+r2;
                  }
          if(a[i]=='F')
                 r3=r1-r2;
        }
     printf("%d,%d\n",m1,m2);
    }
    return 0;
}

