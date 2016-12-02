#include "stdio.h"
#include "string.h"
#include "math.h"
#include "algorithm"
#define MAX 55
using namespace std;
int a[MAX];
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,i,j;
    double ans;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
                scanf("%d",&a[i]);
        sort(a+1,a+1+n,cmp);
        ans=0;
        for(i=1;i<=n;i++)
               ans=ans+(double)a[i]*pow(2.718281828459,(double)(i-1)*log(0.95));
        printf("%.10f\n",ans);
    }
    return 0;
}

