#include "algorithm"
#include "stdio.h"
#include "string.h"
#define MAX 200005
using namespace std;
int num[MAX],hash[MAX];
int main()
{
    int n,m1,m;
    int t,x,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m1);
        m=0;
        memset(hash,0,sizeof(hash));
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            hash[x]=1;
        }
        for(i=1;i<=200000;i++)
        {
            if(!hash[i])
            {
                  num[m]=i;
                  m++;
            }
        }
        while(m1--)
        {
               scanf("%d",&x);
               int ans=lower_bound(num,num+m,x)-num;
               printf("%d\n",num[ans]);
        }
    }
    return 0;
}

