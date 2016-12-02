#include "stdio.h"
#include "string.h"
#include "math.h"
long long gcda[100000];
long long gcdb[100000];
long long res[100001];
int main()
{
    long long i,a,b,k,temp,ana,j;
    int t;
    int da,xiao;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d",&a,&b,&k);
        if(k>a||k>b)
        {
            puts("-1");
            continue;
        }
        if(a>b)
            a^=b^=a^=b;
        da=1;
        xiao=1;
        for(i=1; i*i<=a; i++)
        {
            if(!(a%i))
            {
                if(!(b%i))
                      gcda[xiao++]=i;
                ana=a/(long long)i;
                if(ana!=i&&!(b%ana))
                    gcdb[da++]=ana;
                continue;
            }
        }
        da-=1;
        xiao-=1;
        temp=da+xiao;
        if(temp<k)
        {
            puts("-1");
            continue;
        }
        if(k<=da)
        {
            printf("%I64d\n",gcdb[k]);
            continue;
        }
        printf("%I64d\n",gcda[xiao-(k-da)+1]);
    }
    return 0;
}



