#include "stdio.h"
int main()
{double ans;
 long long n;
 long long i,k;
 while(scanf("%I64d",&n)==1&&n)
 {
    ans=0;
    ans=(double)n*(double)(n+1)*(double)(n+2)/6;
    k=0;
    while(ans>=10)
      {
          ans/=10;
          k++;
      }
    printf("%.2lfE%I64d\n",ans,k);
 }
 return 0;
}

