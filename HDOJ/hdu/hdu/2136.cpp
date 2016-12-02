#include "stdio.h"
#include "string.h"
int a[1000001];
int main()
{int locate;
  int i,j,n;
  locate=0;
  memset(a,0,sizeof(a));
  for(i=2;i<1000001;i++)
    {if(a[i]!=0)
                continue;
      locate++;
      for(j=i;j<1000001;j+=i)
                a[j]=locate;
        }
  while(scanf("%d",&n)==1)
  {a[1]=-1;
    if(n==1)
           printf("0\n");
    else
            printf("%d\n",a[n]);
    }
    return 0;
}
