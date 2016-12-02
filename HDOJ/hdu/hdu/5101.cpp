#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
int a[100010],b[110];
int main()
{
    int len;
    int i,j;
    int n,k,t,m;
    long long sum1,sum2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        sum1=0;sum2=0;
        len=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
                 {scanf("%d",&b[j]);
                  a[len++]=b[j];
                 }
            sort(b,b+m);
            for(j=0;j<m;j++)
            {
              int temp=upper_bound(b,b+m,k-b[j])-b;
              if(temp<=m-1)
                  sum2+=m-temp;
            }
        }
        sort(a,a+len);
        for(j=0;j<len;j++)
            {
              int temp=upper_bound(a,a+len,k-a[j])-a;
              if(temp<=len-1)
                  sum1+=len-temp;
            }
        printf("%I64d\n",(sum1-sum2)/2);
    }
    return 0;
}

