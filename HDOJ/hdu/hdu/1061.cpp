#include "stdio.h"
int main()
{int a[]={1,4,7,6,5,6,3,6,9,0,1,6,3,6,5,6,7,4,9,0};
 long t,n,i;
 while(scanf("%d",&t)==1)
  {  
    for(i=0;i<t;i++)
      {   scanf("%ld",&n);
         if(n!=0)
          printf("%d\n",n%20?a[n%20-1]:0);
      }
  }
  return 0;
}
