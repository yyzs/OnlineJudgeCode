#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
#define clr(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;

vector<int> e[105];
int vis[110],ans[110];
int dfs(int u)
{
    int ans1=1;
    vis[u]=1;
    if(e[u].size()==0)
    {
        ans[u]=0;
        return 1;
    }
    for(int i=0; i<e[u].size(); i++)
    {
        int v=e[u][i];
        ans1+=dfs(v);
    }
    ans[u]=ans1-1;
    return ans1;
}
int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        for(int i = 1; i <= n; i++) e[i].clear();
        for(int i =1; i <= n-1; i++)
        {
            int u,v;;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
        }
        int ans1=0;
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        for(int i=1; i<=n; i++)
        {
            if(vis[i])
            {
                if(ans[i]==k)
                    ans1++;
                continue;
            }
           int temp=dfs(i);
           if(ans[i]==k)
                ans1++;
        }
        printf("%d\n",ans1);
    }
    return 0;
}

