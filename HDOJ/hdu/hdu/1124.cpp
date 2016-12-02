#include<stdio.h>
int ans(int n)
{
    int sum=0;
    while(n)
    {
        sum+=n/5;
        n/=5;
    }
    return sum;
}
int main()

{
    int m,n;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&n);
        printf("%d\n",ans(n));
    }
    return 0;
}
