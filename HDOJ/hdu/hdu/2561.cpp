#include "stdio.h"
#include "string.h"
#include <algorithm>
int a[12];
using namespace std;
int main()
{int i,t,n;
  memset(a,0,sizeof(a));
  scanf("%d",&t);
  while(t--)
  {scanf("%d",&n);
    for(i=0;i<n;i++)
          scanf("%d",&a[i]);
    sort(a,a+n);
     printf("%d\n",a[1]);
    }
    return 0;
}

