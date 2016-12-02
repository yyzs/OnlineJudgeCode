#include "stdio.h"
int sum(int a)
{int j,s;
 s=0;
 for(j=1;j<a;j++)
   if(a%j==0)
     s+=j;
  return s;
 }
int main()
{int m,a,b;
 int i;
 while(scanf("%d",&m)!=EOF)
  {for(i=0;i<m;i++)
    {scanf("%d%d",&a,&b);
     if(sum(a)==b&&sum(b)==a)
        printf("YES\n");
     else
       printf("NO\n");
     }
  }
   return 0;
 }



