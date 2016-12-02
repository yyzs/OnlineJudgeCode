#include "stdio.h"
int main()
{int m,n;
  while(scanf("%d%d",&m,&n)==2&&m&&n)
  {if(m%2==1&&n%2==1)
             printf("What a pity!\n");
    else
              printf("Wonderful!\n");
    }
    return 0;
    }
