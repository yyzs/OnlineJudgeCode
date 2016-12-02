#include "stdio.h"
#include "string.h"
int judge(int n)
{
        if(n==2)
                return 1;
        for(int i=2;i*i<=n;i++)
        {
                if(n%i==0)
                        return 0;
        }
        return 1;
}
int main()
{
        int t,n;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d",&n);
                if(n==4)
                        {
                                puts("2");
                                continue;
                        }
                if(judge(n))
                        printf("%d\n",n-1);
                else
                        puts("0");
        }
        return 0;
}

