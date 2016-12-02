#include "stdio.h"
#include "string.h"
#define MAX 100011
#include "vector"
#include "algorithm"
using namespace std;
vector<int> g[MAX];
long long b[MAX],c[MAX],a[MAX];
int hash[MAX];
void make()
{
    int i,j;
    for(i=1;i<=100000;i++)
    {
        for(j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                g[i].push_back(j);
                if(i/j!=j)
                      g[i].push_back(i/j);
            }
        }
    }
}
int main()
{
    int i,j;
    int n;
    long long ans;
    int len;
    for(i=1;i<=100000;i++)
         g[i].clear();
    make();
    while(scanf("%d",&n)==1&&n)
    {
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        memset(hash,0,sizeof(hash));
        for(i=1;i<=n;i++)
        {
            if(hash[a[i]])
                  c[i]=a[hash[a[i]]];
            else
                  c[i]=a[i];
            len=g[a[i]].size();
            for(j=0;j<len;j++)
                  hash[g[a[i]][j]]=i;
        }
        memset(hash,0,sizeof(hash));
        for(i=n;i>=1;i--)
        {
            if(hash[a[i]])
                  b[i]=a[hash[a[i]]];
            else
                  b[i]=a[i];
            len=g[a[i]].size();
            for(j=0;j<len;j++)
                  hash[g[a[i]][j]]=i;
        }
        ans=0;
        //for(i=1;i<=n;i++)
           //printf("%d %d\n",c[i],b[i]);
        for(i=1;i<=n;i++)
            ans=ans+b[i]*c[i];
        printf("%I64d\n",ans);
    }
    return 0;
}

