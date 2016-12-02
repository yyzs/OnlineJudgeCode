#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 1000010
using namespace std;
int a[MAX],b[MAX];
int cmp1(int a,int b)
{
        return a<b;
}
int cmp2(int a,int b)
{
        return a>b;
}
int main()
{
        int n,m;
        int t;
        scanf("%d",&t);
        while(t--)
        {
                int sum1=0;
                int sum2=0;
                scanf("%d%d",&n,&m);
                for(int i=0;i<n;i++)
                        scanf("%d",&a[i]);
                for(int i=0;i<n;i++)
                        scanf("%d",&b[i]);
                sort(a,a+n,cmp1);
                sort(b,b+n,cmp2);
                for(int i=0;i<m;i++)
                        sum1+=a[i];
                for(int i=0;i<m;i++)
                        sum2+=b[i];
                if(sum1<=sum2)
                        puts("NO");
                else
                        puts("YES");
        }
        return 0;
}

