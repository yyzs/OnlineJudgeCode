#include "stdio.h"
#include "string.h"
#include "iostream"
#define MOD 1000000007
#define MAX 110
#define LL  long long
using namespace std;
int a[MAX][MAX];
int vis[MAX];
int b[MAX],c[MAX];
long long fac[110];
LL mod(LL a,LL b,LL c)
{
        LL ans=1;
        while(b)
        {
                if(b&1)
                        ans=ans*a%MOD;
                a=a*a%MOD;
                b/=2;
        }
        return ans;
}
void init()
{
    fac[0]=1;
    fac[1]=1;
    for(int i=2; i<=100; i++)
    {
        fac[i]=fac[i-1]*(LL)i%MOD;
    }
}
int main()
{
    int n,m;
    int ok;
    init();
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(a,0,sizeof(a));
        for(int i=0; i<n; i++)
        {
            a[0][i]=i+1;
            a[m+1][i]=i+1;
            b[i]=i+1;
        }
        int sign=0;
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&a[i][0]);
            if(a[i][0]!=-1)
                for(int j=1; j<n; j++)
                   {scanf("%d",&a[i][j]);
                     }
            else
                sign=1;
        }
        ok=1;
        if(!sign)
        {
            for(int i=m; i>=1; i--)
            {
                for(int j=0; j<n; j++)
                    {c[a[i][j]-1]=b[j];
                   }
                for(int j=0; j<n; j++)
                    {
                        b[j]=c[j];
                    }
            }
            for(int i=0; i<n; i++)
            {
                if(b[i]!=i+1)
                {
                    ok=0;
                    break;
                }
            }
        }
        for(int i=m; i>=1; i--)
        {
            memset(vis,0,sizeof(vis));
            if(a[i][0]==-1)
                continue;
            for(int j=0; j<n; j++)
            {
                if(vis[a[i][j]])
                        {
                                ok=0;
                                break;
                        }
                vis[a[i][j]]++;
            }
            if(!ok)
                break;
        }
        if(!ok)
        {
            puts("0");
            continue;
        }
        LL pos=0,ans=1;
        for(int i=m; i>=0; i--)
        {
            if(a[i][0]==-1)
                pos++;
        }
        if(pos!=0)
                ans=ans*mod(fac[n],pos-1,MOD)%MOD;
       cout<<ans<<endl;
    }
    return 0;
}

