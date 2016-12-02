#include "stdio.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "algorithm"
#define MAX 13
using namespace std;
int a[MAX];
double max1;
int n;
int judge(int a,int b,int c)
{
    if(a+b>c)
        return 1;
    return  0;
}
double s(int a,int b,int c)
{
    double p=(double)(a+b+c)/2.0;
    return sqrt(p*(p-(double)a)*(p-(double)b)*(p-(double)c));
}
void dfs(int vis[],double temp,int res)
{
    int i,j,k;
    if(temp>max1)
        max1=temp;
    if(res>=n/3*3)
        return;
    for(i=0; i<n; i++)
    {
        if(vis[i])
            continue;
        for(j=i+1; j<n; j++)
        {
            if(vis[j])
                continue;
            for(k=j+1; k<n; k++)
            {
                if(!vis[i]&&!vis[j]&&!vis[k])
                {
                    if(judge(a[i],a[j],a[k]))
                    {
                        vis[i]=1;
                        vis[j]=1;
                        vis[k]=1;
                        dfs(vis,temp+s(a[i],a[j],a[k]),res+3);
                        vis[i]=0;
                        vis[j]=0;
                        vis[k]=0;
                    }
                }
            }
        }
    }
}
int main()
{
    int vis[MAX];
    int i;
    while(scanf("%d",&n)==1,n)
    {
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        memset(vis,0,sizeof(vis));
        max1=0;
        dfs(vis,0,0);
        printf("%.2f\n",max1);
    }
    return 0;
}

