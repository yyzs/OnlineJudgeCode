#include<stdio.h>
int main()
{
    int i,n,x,a[100];
    while(scanf("%d",&n),n)
    {
        x=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            x=x+a[i]/100+a[i]%100/50+a[i]%100%50/10+a[i]%100%50%10/5+a[i]%100%50%10%5/2+a[i]%100%50%10%5%2;
        }
        printf("%d\n",x);
    }
    return 0;
}
