#include "stdio.h"
#include "map"
#include "algorithm"
#define MAX 1000010
using namespace std;
int a[MAX];
map<int,int> vis;
inline void scan_d(int &ret)
{
    char c;
    ret=0;
    while((c=getchar())<'0'||c>'9');
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
}
int main()
{
    int n,i,j,ans,m,x;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=0;i<MAX;i++)
            vis[i]=0;
        for(i=0;i<n;i++)
        {
            scan_d(x);
            vis[x]+=1;
        }
        for(i=0;i<m;i++)
        {
            scan_d(x);
            printf("%d\n",vis[x]);
            vis[x]=0;
        }
    }
    return 0;
}

