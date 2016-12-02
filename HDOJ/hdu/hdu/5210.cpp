#include "stdio.h"
#include "algorithm"
#include "string.h"
using namespace std;
int a[110],has[110],b[110];
int main()
{
    int n,k,i,j,ans,temp;
    while(scanf("%d",&n)==1)
    {
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        scanf("%d",&k);
        memset(has,0,sizeof(has));
        for(i=1; i<n; i++)
        {
            if(a[i]==a[i-1])
            {
                has[i]=1;
                k--;
            }
            if(k==0)
                break;
        }
        if(k>0)
        {
            for(i=1; i<n; i++)
            {
                if(!has[i])
                {
                    has[i]=1;
                    k--;
                }
                if(k==0)
                    break;
            }
        }
        ans=1;
        temp=0;
        for(i=1; i<n; i++)
        {
            if(!has[i])
            {
                if(a[i]!=a[temp])
                    ans++;
                temp=i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

