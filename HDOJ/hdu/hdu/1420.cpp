#include "stdio.h"
int main()
{
    long long a,b,c,sum=0;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        sum=1;
        a%=c;
        while(b>0)
        {
            if(b%2==0)
            {
                a=a*a;
                a=a%c;
                b/=2;
            }
            else
            {
            sum=sum*a%c;
            b--;
            }
        }
        printf("%I64d\n",sum%c);
    }
}

