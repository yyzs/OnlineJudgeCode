#include "stdio.h"
#include "algorithm"
#define MAX 100001
using namespace std;
int a[MAX];
int main()
{
   int t,n,k;
   int i,j;
   long long ans;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d%d",&n,&k);
       for(i=0;i<n;i++)
            scanf("%d",&a[i]);
       sort(a,a+n);
       ans=0;
       for(i=0;i<n;i++)
       {
           int temp=upper_bound(a,a+n,a[i]+k)-a;
           temp-=1;
           if(a[temp]>a[i]+k)
                ans+=temp-1-i;
           else
                ans+=temp-i;
       }
       printf("%I64d\n",ans);
   }
}

