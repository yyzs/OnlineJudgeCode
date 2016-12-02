#include "stdio.h"
int a[100001];
int main()
{
    int n,m;
    int i,j,ans,num;
    int t,cas;
    scanf("%d",&t);
    cas=1;
    while(cas<=t)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        ans=0;
        for(i=0;i<n;i++)
            {
              num=a[i];
              for(j=i;j<n;j++)
                   {num=a[j]|num;
                    if(num<m)
                       ans++;
                    else
                       break;
                   }
            }
        printf("Case #%d: %d\n",cas,ans);
        cas++;
    }
    return 0;
}

