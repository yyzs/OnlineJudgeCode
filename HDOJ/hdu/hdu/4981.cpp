#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 1010
using namespace std;
int a[MAX];
int main()
{
    int n,i;
    int sum;
    double ave;
    while(scanf("%d",&n)==1)
    {
        sum=0;
        for(i=1;i<=n;i++)
            {scanf("%d",&a[i]);
              sum+=a[i];
            }
        ave=(double)sum/(double)n;
        sort(a+1,a+n+1);
        if(ave>=a[(n+1)/2])
               puts("NO");
        else
              puts("YES");
    }
    return 0;
}

