#include "stdio.h"
#include <algorithm>
using namespace std;
int a[40];
int main()
{
 int t,n,m;
 int ans,i;
 scanf("%d",&t);
 while(t--)
 {
   scanf("%d%d",&n,&m);
   for(i=0;i<n;i++)
           scanf("%d",&a[i]);
    sort(a,a+n);
    ans=0;
    ans=(100-a[0])*(100-a[0]);
    printf("%d\n",ans);
 }
 return 0;
}
