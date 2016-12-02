#include "stdio.h"
#include "string.h"
#define F 500001
int hash[1000010];
int main()
{int n,m;
 int i,j;
 int flag=0;
 int x;
 int max;
 int num;
  while(scanf("%d%d",&n,&m)==2)
 {flag=0;
  memset(hash,0,sizeof(hash));
  max=-F;
  for(i=0;i<n;i++)
       {scanf("%d",&x);
        if(x>max)
            max=x;
        hash[x+F]++;
        }
  num=0;
  for(i=max+F;i>=0;i--)
        {if(hash[i])
               {if(flag==0)
                   {printf("%d",i-F);
                    flag=1;
                   }
                else
                   printf(" %d",i-F);
                num++;
                }
         if(num==m)
                break;
         }
  printf("\n");
  }
  return 0;
}

