#include "stdio.h"
#include "string.h"
long long a,b,c;
int main()
{
    int i;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        if(c==a||c==b)
        {
            puts("Yes");
            continue;
        }
        int ok=0;
        long long temp=a+b;
        while(temp<=c)
        {
            if(temp==c)
            {ok=1;
             break;
            }
            a=b;
            b=temp;
            temp=a+b;
        }
        if(ok)
           puts("Yes");
        else
           puts("No");
    }
    return 0;
}

