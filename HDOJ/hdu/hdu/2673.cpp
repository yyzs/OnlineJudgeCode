#include "stdio.h" 
#include <algorithm>
using namespace std;
int a[10011];
int main()
{
    int n,i;
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++)
           scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        if(n%2==0)
          {
              for(i=n;i>n/2;i--)
                {
                    printf("%d %d",a[i],a[n-i+1]);
                    if(i!=n/2+1)
                      printf(" ");
                }
             printf("\n");
          }    
         else
         {
             for(i=n;i>n/2+1;i--)
               {
                   printf("%d %d ",a[i],a[n-i+1]);
               }
               printf("%d\n",a[i]);
         }
      }
        return 0;
}
