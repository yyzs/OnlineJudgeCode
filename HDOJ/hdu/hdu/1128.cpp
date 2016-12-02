#include "stdio.h"
#include "math.h"
#include "string.h"
int c[1000001];
int main()
{int sum,i,j,len;
 memset(c,0,sizeof(c));
 for(i=1;i<=1000000;i++)
 {
     j=i;
     for(sum=j;j;j/=10)
          sum+=(j%10);
     c[sum]=1;
     if(!c[i])
          printf("%d\n",i);
 }
  return 0;
}


