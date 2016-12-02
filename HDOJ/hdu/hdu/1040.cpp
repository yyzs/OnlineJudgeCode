#include "stdio.h"
#include "stdlib.h"
int cmp(const int *a,const int  *b)
{if(*a>*b)
  return 1;
 if(*a<*b)
   return -1;
 return 0;
 }
int main()
{int t,n,a[1000];
 int i,j;
 while(scanf("%d",&t)==1)
 {
  for(i=0;i<t;i++)
  {scanf("%d",&n);
   for(j=0;j<n;j++)
     scanf("%d",&a[j]);
   qsort(a,n,sizeof(a[0]),cmp);
   for(j=0;j<n-1;j++)
     printf("%d ",a[j]);
   printf("%d\n",a[n-1]);
   }
  }
  return 0;
}

