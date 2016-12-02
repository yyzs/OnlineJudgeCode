#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
int a[1000001];
int main()
{int i,n;
 memset(a,0,sizeof(a));
 while(scanf("%d",&n)==1)
 {for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  sort(a,a+n);
  printf("%d\n",a[(n-1)/2]);
  }
  return 0;
  }

