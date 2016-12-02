#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "queue"
#define MAX 1000
#define INF 100000000
using namespace std;
char g[2][MAX][MAX];
int d[2][MAX][MAX];
int vis[2][MAX][MAX];
int begx,begy,begz,endx,endy,endz;
int t,n,m;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
struct node
{
    int x,y,z;
};
void bfs()
{
    int i,j,k;
    queue<node> que;
    while(!que.empty())
        que.pop();
    struct node beg;
    beg.x=begx;
    beg.y=begy;
    beg.z=begz;
    que.push(beg);
    for(k=0;k<2;k++)
        for(i=0;i<n;i++)
           for(j=0;j<m;j++)
             d[k][i][j]=INF;
    memset(vis,0,sizeof(vis));
    d[begz][begx][begy]=0;
    vis[begz][begx][begy]=1;
    while(!que.empty())
    {
        struct node now=que.front();
        que.pop();
        if(now.x==endx&&now.y==endy&&now.z==endz)
            break;
        struct node p;
        for(i=0;i<4;i++)
        {
            int nowx=now.x+dir[i][0];
            int nowy=now.y+dir[i][1];
            int nowz=now.z;
            if(nowx<0||nowx>=n||nowy<0||nowy>=m)
                 continue;
            if(g[nowz][nowx][nowy]=='#')
                 nowz^=1;
            if(g[nowz][nowx][nowy]!='*'&&!vis[nowz][nowx][nowy]&&g[nowz][nowx][nowy]!='#')
            {
                p.x=nowx;
                p.y=nowy;
                p.z=nowz;
                vis[nowz][nowx][nowy]=1;
                d[nowz][nowx][nowy]=d[now.z][now.x][now.y]+1;
                que.push(p);
            }
        }
    }
    if(d[endz][endx][endy]<=t)
         puts("YES");
    else
         puts("NO");
}
int main()
{
    int cas;
    int i,j,k;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d%d",&n,&m,&t);
        for(i=0;i<2;i++)
            for(j=0;j<n;j++)
               scanf("%s",g[i][j]);
        for(k=0;k<2;k++)
            for(i=0;i<n;i++)
               for(j=0;j<m;j++)
        {
            if(g[k][i][j]=='S')
            {
                begx=i;
                begy=j;
                begz=k;
            }
            if(g[k][i][j]=='P')
            {
                endx=i;
                endy=j;
                endz=k;
            }
        }
        bfs();
    }
    return 0;
}

