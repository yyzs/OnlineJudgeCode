#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
int main()
{int n,i,j,max;
 int a[3010];
 int temp;
 int ok;
 while(scanf("%d",&n)==1)
 {max=0;
  temp=0;
  for(i=0;i<n;i++)
       scanf("%d",&a[i]);
  sort(a,a+n);
  for(i=0;i<n;i++)
       {if(i==0)
               continue;
        if(a[i]==a[i-1])
               temp++;
        else
               {if(temp>max)
                    max=temp;
                temp=0;
               }
        }
  if(temp>max)
       max=temp;
  printf("%d\n",max+1);
  }
  return 0;
}

