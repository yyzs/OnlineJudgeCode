#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
int a[110];
long long num[10000];
int main()
{
    long long sum;
    int n,i,j,m;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        m=0;
        for(i=0;i<n;i++)
            for(j=0;j<i;j++)
                num[m++]=a[i]+a[j];
        sort(num,num+m);
        sum=num[0];
        for(i=1;i<m;i++)
            if(num[i]!=num[i-1])
                 sum+=num[i];
        printf("%I64d\n",sum);
    }
    return 0;
}

