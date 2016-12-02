#include "stdio.h"
int main()
{int n,res,i;
  int h[1010];
  while(scanf("%d",&n)&&n)
  {res=0;
    for(i=0;i<n;i++)
          {scanf("%d",&h[i]);
            res^=h[i];
            }
    if(res==0)
            printf("Grass Win!\n");
    else
            printf("Rabbit Win!\n");
     }
     return 0;
    }

