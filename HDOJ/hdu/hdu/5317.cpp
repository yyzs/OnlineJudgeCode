#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "vector"
#define MAX  1000010
using namespace std;
int ans[MAX];
vector<int> p;
int v[1000001][10];
int len[10];
int f[MAX],vis[MAX];
const int MAXN=1000010;
void getPrime()
{
    for(int i=2; i<=MAXN; i++)
    {
        if(vis[i])
            continue;
        for(int j=i; j<=MAXN; j+=i)
        {
            vis[j]=1;
            f[j]+=1;
        }
    }
}
void inita()
{
    getPrime();
    memset(len,0,sizeof(len));
    for(int i = 1; i <= MAXN; i++)
    {
        for(int j=1; j<=7; j++)
        {
            if(j==f[i])
                v[i][j]=v[i-1][j]+1;
            else
                v[i][j]=v[i-1][j];
        }
    }
}
int getans(int maxnum,int l,int r)
{
    if(v[r][7]-v[l-1][7]>=2)
        return 7;
    if(v[r][6]-v[l-1][6]>=2)
        return 6;
    if(v[r][5]-v[l-1][5]>=2)
        return 5;
    if(v[r][4]-v[l-1][4]>=2)
        return 4;
    if(v[r][6]-v[l-1][6]==1&&v[r][3]-v[l-1][3]==1)
        return 3;
    if(v[r][3]-v[l-1][3]>=2)
        return 3;
    if(v[r][6]-v[l-1][6]==1&&v[r][4]-v[l-1][4]==1)
        return 2;
    if(v[r][2]-v[l-1][2]==1&&v[r][4]-v[l-1][4]==1)
        return 2;
    if(v[r][2]-v[l-1][2]>=2)
        return 2;
    return 1;
}
int main()
{
    inita();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int maxnum=1;
        maxnum=getans(maxnum,l,r);
        printf("%d\n",maxnum);
    }
    return 0;
}

