#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int a[100001];
int main()
{int n,m,i;
 while(scanf("%d%d",&n,&m)==2)
 {if(n==0&&m==0)
     break;
  for(i=0;i<n;i++)
     scanf("%d",&a[i]);
  sort(a,a+n,cmp);
  for(i=0;i<m;i++)
     {if(i==0)
         printf("%d",a[i]);
      else
         printf(" %d",a[i]);
      }
  printf("\n");
  }
  return 0;
  }

