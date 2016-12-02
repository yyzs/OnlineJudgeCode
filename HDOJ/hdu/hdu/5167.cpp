#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "map"
using namespace std;
int f[100000];
int ok=0;
map<int,int> vis;
void init()
{
    int i;
    f[0]=0;
    f[1]=1;
    vis[0]=1;
    vis[1]=1;
    for(i=2;;i++)
        {f[i]=f[i-1]+f[i-2];
         vis[f[i]]=1;
         if(f[i]>1000000000)
              break;
        }
}
int dfs(int n)
{
    int i;
    if(vis[n]==1)
        return 1;
    if(vis[n]==-1)
        return 0;
    int pos=lower_bound(f,f+46,n)-f;
    if(f[pos]==n)
        return 1;
    for(i=3;i<=45&&f[i]<=n;i++)
    {
        if(n%f[i]==0)
        {
            int pos=lower_bound(f+3,f+46,n/f[i])-f;
            if(f[pos]==n/f[i])
               {
                 vis[n]=1;
                 return 1;
               }
            if(dfs(n/f[i]))
                {
                 vis[n]=1;
                 return 1;
                }
        }
    }
    vis[n]=-1;
    return 0;
}
int main()
{
    int t;
    int ok;
    int i,j,n;
    init();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==0)
        {
            puts("Yes");
            continue;
        }
        if(dfs(n))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}

