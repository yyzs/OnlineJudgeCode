#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
int hash[1000000],a[1000000];
int main()
{
    int t,n,i,j;
    int max;
    scanf("%d",&t);
    int ans;
    while(t--)
    {
        scanf("%d",&n);
        memset(hash,0,sizeof(hash));
        max=0;
        for(i=1;i<=n;i++)
            {scanf("%d",&a[i]);
             if(a[i]>max)
                 max=a[i];
             hash[a[i]]=1;
            };
        ans=0;
        int flag=0;
        for(i=1;i<=max;i++)
        {
            if(!hash[i])
            {
                if(!flag)
                    printf("%d",i);
                else
                    printf(" %d",i);
                flag=1;
                ans++;
            }
        }
        if(ans==1)
            printf(" %d\n",max+1);
        else
            if(ans==0)
                printf("%d %d\n",max+1,max+2);
        else
            printf("\n");
    }
    return 0;
}

