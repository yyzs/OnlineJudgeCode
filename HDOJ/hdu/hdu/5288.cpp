#include "stdio.h"
#include "vector"
#include "math.h"
#include "string.h"
#define INF 10000000
#define MOD 1000000007
#define MAX 100010
using namespace std;
vector<int> v[MAX],g[MAX];
int a[MAX];
int L[MAX];
int R[MAX];
int judge1[MAX],judge2[MAX];
void init()
{
    for(int i=1; i<=100000; i++)
    {
        v[i].clear();
        v[i].push_back(1);
    }
    for(int i=2; i<=100000; i++)
    {
        for(int j=i; j<=100000; j+=i)
        {
            v[j].push_back(i);
        }
    }
}
int main()
{
    int n;
    init();
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=100000;i++)
            g[i].clear();
        memset(judge1,0,sizeof(judge1));
        memset(judge2,0,sizeof(judge2));
        for(int i=0; i<n; i++)
        {
            L[i]=0;
            R[i]=n-1;
        }
        long long ans=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            for(int j=0; j<v[a[i]].size(); j++)
            {
                if(g[v[a[i]][j]].size()==0)
                    continue;
                int len=g[v[a[i]][j]].size();
                int num=g[v[a[i]][j]][len-1];
                if(num>=L[i])
                    {judge1[i]=1;L[i]=num;}
            }
            g[a[i]].push_back(i);
        }
        for(int i=100000; i>=1; i--)
            g[i].clear();
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<v[a[i]].size(); j++)
            {
                if(g[v[a[i]][j]].size()==0)
                    continue;
                int len=g[v[a[i]][j]].size();
                int num=g[v[a[i]][j]][len-1];
                if(num<=R[i])
                    {R[i]=num;judge2[i]=1;}
            }
            g[a[i]].push_back(i);
        }
        ans=0;
        for(int i=0;i<n;i++)
        {
             if(judge1[i])
                L[i]+=1;
             if(judge2[i])
                R[i]-=1;
             ans=(ans%MOD+1+((long long)(i-L[i])%MOD*(long long)(R[i]-i)%MOD)%MOD+i-L[i]+R[i]-i)%MOD;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

