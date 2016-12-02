#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
int c[105],j[105];
int main()
{int n;
 int sum1,sum2;
 int i;
 while(scanf("%d",&n)==1&&n)
 {memset(c,0,sizeof(c));
  memset(j,0,sizeof(j));
  for(i=0;i<n;i++)
        scanf("%d",&c[i]);
  for(i=0;i<n;i++)
        scanf("%d",&j[i]);
  sort(c,c+n);
  sort(j,j+n);
  sum1=0;
  sum2=0;
  for(i=0;i<n;i++)
        {if(c[i]>j[i])
                sum1+=2;
         if(c[i]==j[i])
                {sum1+=1;
                 sum2+=1;
                 }
          if(c[i]<j[i])
                 sum2+=2;
        }
  printf("%d vs %d\n",sum1,sum2);
  }
  return 0;
  }

