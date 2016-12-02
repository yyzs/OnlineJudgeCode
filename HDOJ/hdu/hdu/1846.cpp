#include "stdio.h"
#include "string.h"
int main()
{int n,m;
 int ok,t,i,j;
 scanf("%d",&t);
 while(t--)
 {scanf("%d%d",&n,&m);
   if(n<=m||(n%(m+1)!=0))
        printf("first\n");
   else
        printf("second\n");
  }
  return 0;
  }

