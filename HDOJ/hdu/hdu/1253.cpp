#include "stdio.h"
#include <queue>
#include "string.h"
#include <algorithm>
#define MAX 55
#define INF 10000000
using namespace std;
int g[MAX][MAX][MAX];
int d[MAX][MAX][MAX];
int dis[6][3]={1,0,0,-1,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1};
int a,b,c,t;
struct node
{
  int x,y,z;
};
void bfs()
{
   int i,j,k;
   int sx=0,sy=0,sz=0;
   queue<node>que;
   for(i=0;i<a;i++)
       for(j=0;j<b;j++)
            for(k=0;k<c;k++)
                d[i][j][k]=INF;
  node start;
  start.x=0;
  start.y=0;
  start.z=0;
  que.push(start);
  d[0][0][0]=0;
  while(!que.empty())
  {
       node p=que.front();
       que.pop();
       for(i=0;i<6;i++)
       {int nx=p.x+dis[i][0];
        int ny=p.y+dis[i][1];
        int nz=p.z+dis[i][2];
        if(nx>=0&&nx<a&&ny>=0&&ny<b&&nz>=0&&nz<c&&d[nx][ny][nz]==INF&&g[nx][ny][nz]==0)
                 {
                    node q;
                    q.x=nx;
                    q.y=ny;
                    q.z=nz;
                    que.push(q);
                    d[nx][ny][nz]=d[p.x][p.y][p.z]+1;
                    if(nx==a-1&&ny==b-1&&nz==c-1)
                        break;
                  }
        }
   }
   if(d[a-1][b-1][c-1]>t)
         printf("-1\n");
   else
         printf("%d\n",d[a-1][b-1][c-1]);
}
int main()
{
   int i,j,k;
   int sum;
   int cas;
   scanf("%d",&cas);
   while(cas--)
   {
    scanf("%d%d%d%d",&a,&b,&c,&t);
    memset(g,0,sizeof(g));
    sum=0;
    for(i=0;i<a;i++)
         for(j=0;j<b;j++)
            for(k=0;k<c;k++)
               {scanf("%d",&g[i][j][k]);
                if(g[i][j][k]==0)
                     sum++;
               }
    bfs();
    }
    return 0;
}

