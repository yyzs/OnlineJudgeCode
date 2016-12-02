#include "stdio.h"
#include "string.h"
#define MAX 110
int hash[MAX];
int main()
{
    int t,n,i,j,x;
    int max,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(hash,0,sizeof(hash));
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            hash[x]++;
        }
        max=0;
        for(i=0;i<=100;i++)
            if(hash[i]>max)
              {
                  max=hash[i];
                  ans=i;
              }
        printf("%d\n",ans);
    }
    return 0;
}

