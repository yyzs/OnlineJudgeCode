#include "stdio.h"
int a[100001];
int main()
{
  int i,n;
  while(scanf("%d",&n)==1)
  {
    for(i=0;i<=100000;i++)
      a[i]=0;
    for(i=1;i<=n;i++)
      if(n%i==0)
        a[n]=!a[n];
    printf("%d\n",a[n]);    
  }      
}
