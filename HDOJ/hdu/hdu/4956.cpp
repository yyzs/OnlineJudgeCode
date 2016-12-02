#include "stdio.h"
#include "string.h"
int ok(long long r)
{
    int sum1=0,sum2=0;
    int m=0;
    while(r)
    {
        int  temp=r%10;
        if(m%2==0)
            sum1+=temp;
        else
            sum2+=temp;
        m++;
        r/=10;
    }
    if(sum1-sum2==3)
        return 1;
    return 0;
}
int main()
{
    long long l,r,R;
    long long  num,i,j;
    int m=0;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d",&l,&r);
        for(i=l;i<=r;i++)
            {
                if(i%11==3&&!ok(i))
                    break;
            }
        if(i==r+1)
            printf("-1\n");
        else
            printf("%I64d\n",i);
    }
    return 0;
}

