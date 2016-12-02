#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 510
using namespace std;
int a[MAX],hash[MAX];
int main()
{
    int n,t,k;
    int i,j;
    int temp=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(i=1;i<=n;i++)
             scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        memset(hash,0,sizeof(hash));
        temp=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                 if(!hash[j]&&a[j]<=i&&(i-a[j])%k==0)
            {
                 hash[j]=1;
                 temp++;
                 break;
            }
        }
        if(temp==n)
               puts("Jerry");
        else
               puts("Tom");
    }
    return 0;
}

