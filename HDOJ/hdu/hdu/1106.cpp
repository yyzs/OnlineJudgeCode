#include "stdlib.h"
#include "stdio.h"
#include <algorithm>
using namespace std;
char a[1002],*temp;
int main()
{int d[1002];
 int i,j;
 int count;
 while(scanf("%s",a)!=EOF)
 {temp=strtok(a,"5");
  count=0;
  while(temp)
  {d[count++]=atoi(temp);
    temp=strtok(NULL,"5");
  }
  sort(d,d+count);
  for(i=0;i<=count-2;i++)
        printf("%d ",d[i]);
  printf("%d\n",d[count-1]);
 }
 return 0;
}
