#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
int b[4500010];
int a[3500];
int cmp(int a,int b)
{
   return a>b;
}
int main()
{
  int n,m,i,j;
  int t=0;
  while(scanf("%d%d",&n,&m)==2)
  {
     memset(a,0,sizeof(a));
     memset(b,0,sizeof(b));
     t=0;
     for(i=0;i<n;i++)
         scanf("%d",&a[i]);
     for(i=0;i<n;i++)
          for(j=i+1;j<n;j++)
              b[t++]=a[i]+a[j];
    sort(b,b+t,cmp);
    for(i=0;i<m;i++)
          if(i==0)
              printf("%d",b[i]);
          else
              printf(" %d",b[i]);
    printf("\n");
  }
  return 0;
}

