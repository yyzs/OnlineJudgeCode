#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
int a[30];
int main()
{int n,i;
 int t;
 scanf("%d",&t);
 while(t--)
 {scanf("%d",&n);
  for(i=0;i<n;i++)
              scanf("%d",&a[i]);
  sort(a,a+n);
  printf("%d\n",(a[n-1]-a[0])*2);
  }
  return 0;
  }

