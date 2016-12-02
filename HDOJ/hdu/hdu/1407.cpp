#include "stdio.h"
#include "string.h"
int main()
{int num,i,j,k;
 int ok;
 while(scanf("%d",&num)==1)
 {ok=0;
  for(i=1;i*i<num;i++)
      {for(j=1;j*j<num;j++)
            {if(j*j+i*i>=num)
                   break;
              else
                for(k=1;k*k<num;k++)
                 {if(i*i+j*j+k*k>num)
                        break;
                  if(i*i+j*j+k*k==num)
                    {printf("%d %d %d\n",i,j,k);
                     ok=1;
                     break;
                     }
                   }
                if(ok)
                     break;
              }
          if(ok)
              break;
        }
     }
     return 0;
    }


