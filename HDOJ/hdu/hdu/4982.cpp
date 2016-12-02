#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "stdlib.h"
#define MAX 200010
using namespace std;
int a[MAX];
int vis[MAX];
int temp;
int dfs(int n,int k)
{
   int i;
   int t=0;
   if(!k)
        return !n;
   if(k==1)
        return !vis[n];
   int sum=0;
   for(i=1;;i++)
         {
             if(t>=k)
                    break;
             if(!vis[i])
                   { sum+=i;t++;}
         }
    if(sum>n)
         return 0;
    if(sum==n)
         return 1;
    for(i=n-1;i>0;--i)
    {
        if(vis[i])
               continue;
        vis[i]=1;
        if(dfs(n-i,k-1))
              {vis[i]=0; return 1;}
        vis[i]=0;
    }
    return 0;
}
int main()
{
    int n,i,j;
    int k;
    int t;
    int ok;
    while(scanf("%d%d",&n,&k)==2)
    {
        ok=0;
        memset(vis,0,sizeof(vis));
        for(i=1;i*i<n;i++){
                   vis[n-i*i]=1;
                   temp=n-i*i;
                   if(dfs(i*i,k-1)){
                      ok=1;
                      break;
             }
             vis[n-i*i]=0;
        }
        if(ok)
              puts("YES");
        else
              puts("NO");
    }
    return 0;
}

