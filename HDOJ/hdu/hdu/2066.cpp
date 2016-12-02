#include "stdio.h"
#include "string.h"
#define MAX 1010
#define INF  100000000
int map[MAX][MAX],dis[MAX];
int vis[MAX];
int dijkstra(int a,int b,int n)
{
    int i,j,temp,t;
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    for(i=0; i<=1001; i++)
        dis[i]=(i==0?0:map[0][i]);
    for(i=0; i<=1001; i++)
    {
        temp=INF;
        t=a;
        for(j=0; j<=1001;j++)
        {
            if(!vis[j]&&dis[j]<temp)
            {
                temp=dis[j];
                t=j;
            }
        }
        if(t==a)
            break;
        vis[t]=1;
        for(j=0; j<=1001; j++)
            if(!vis[j]&&map[t][j]<INF&&dis[j]>(dis[t]+map[t][j]))
                dis[j]=dis[t]+map[t][j];
    }
    return dis[b];
}
int main()
{
    int n,m,i,j;
    int a,b,x;
    int t,s,d;
    while(scanf("%d%d%d",&m,&s,&d)==3)
    {
        n=1002;
        for(i=0; i<=1001; i++)
            for(j=0; j<=1001; j++)
            {
                if(i!=j)
                    map[i][j]=INF;
                else
                    map[i][j]=0;
            }

        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&a,&b,&x);
            if(map[a][b]>x)
            {
                map[a][b]=x;
                map[b][a]=x;
            }
        }
        for(i=0; i<s; i++)
        {
            scanf("%d",&x);
            map[0][x]=0;
            map[x][0]=0;
        }
        for(i=0; i<d; i++)
        {
            scanf("%d",&x);
            map[1001][x]=0;
            map[x][1001]=0;
        }
        printf("%d\n",dijkstra(0,1001,1001));
    }
    return 0;
}

