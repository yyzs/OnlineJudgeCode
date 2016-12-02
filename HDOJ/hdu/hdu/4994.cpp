#include "stdio.h"
#include "string.h"
int a[1010];
int main()
{
    int t,n;
    int i,num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        if(n==1)
        {
            puts("Yes");
            continue;
        }
        num=0;
        for(i=0;i<n;i++)
            {if(a[i]==1)
                num++;
             else
                break;
            }
        if(num==n)
        {
            if(num%2==1)
                   puts("Yes");
            else
                   puts("No");
            continue;
        }
        if(num%2==0)
              puts("Yes");
        else
              puts("No");
    }
    return 0;
}

