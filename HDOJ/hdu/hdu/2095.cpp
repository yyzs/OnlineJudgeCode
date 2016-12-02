#include "stdio.h"
int main()
{
    int a,s,n;
    int i;
    while(scanf("%d",&n)&&n)
    {
        s=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            s=s^a;
        }
        printf("%d\n",s);
    }
    return 0;
}

