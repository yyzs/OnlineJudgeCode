#include "stdio.h"
long long fab(int n)
{
    if(n==1)
      return 1;
    else
     return fab(n-1)*n;
}
int main()
{
    double a[40];
    int m,n,i;
    a[1]=0;
    a[2]=1;
    for(i=3;i<=20;i++)
      a[i]=(i-1)*(a[i-2]+a[i-1]);
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
    scanf("%d",&n);
    printf("%.2lf%%\n",100.0*a[n]/fab(n));
    }
    return 0;
}
