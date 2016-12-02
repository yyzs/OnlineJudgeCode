#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "vector"
#define MAX  22
#define INF 100010
using namespace std;
int b[22];
int ans,n,a;
void dfs(int s,int u,int num)
{
     //   printf("s,u:%d %d\n",s,u);
        if(s==0)
                {
                        ans=min(ans,num);
                        return;
                }
        if(u==n-1)
                return;
        dfs(s%b[u+1],u+1,num+1);
        dfs(s,u+1,num);
}
int cmp(int a,int b)
{
        return a>b;
}
int main()
{
        int t;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d%d",&n,&a);
                for(int i=0;i<n;i++)
                        scanf("%d",&b[i]);
                sort(b,b+n,cmp);
                ans=INF;
                dfs(a,-1,0);
                ans=ans==INF?-1:ans;
                printf("%d\n",ans);
        }
        return 0;
}

