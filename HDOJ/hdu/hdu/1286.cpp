#include "stdio.h"
#include "string.h"
int ans[40000];
int main()
{
    int i,j,cn,n,sum=0;
    scanf("%d",&cn);
    while(cn--)
    {   
        memset(ans,1,sizeof(ans));
        sum=0;
        scanf("%d",&n);
        for(i=2;i<=n/2;i++)
             if(n%i==0)
                for(j=i;j<n;j+=i)
                   ans[j]=0;
        for(i=1;i<n;i++)
            if(ans[i])
                sum++;
        printf("%d\n",sum);
    }
    return 0;
}
