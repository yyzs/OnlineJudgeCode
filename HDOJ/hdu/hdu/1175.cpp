#include "stdio.h"
#include "string.h"
#include "queue"
#include "algorithm"
#define MAX 1010
#define INF 10001
using namespace std;
int g[MAX][MAX];
int dis[4][2]={0,1,0,-1,1,0,-1,0};
int vis[MAX][MAX];
int n,m;
struct node
{
    int x,y;
    int num;
    int temp;
};
void bfs(int x1,int y1,int x2,int y2)
{
    int i,j;
    int recent;
    queue<node>que;
    node start;
    start.x=x1;
    start.y=y1;
    start.num=0;
    start.temp=-1;
    que.push(start);
    for(i=0;i<n;i++)
         for(j=0;j<m;j++)
           vis[i][j]=INF;
    vis[x1][y1]=1;
    while(!que.empty())
    {
          node p=que.front();
          que.pop();
          if(p.x==x2&&p.y==y2)
          {
              printf("YES\n");
              return;
          }
          for(i=0;i<4;i++)
          {
              int nx=p.x+dis[i][0];
              int ny=p.y+dis[i][1];
              if(i==p.temp)
                     recent=p.num;
              else
                     recent=p.num+1;
              if(recent<vis[nx][ny])
                     vis[nx][ny]=recent;
              else
                     continue;
              if((g[nx][ny]==0||(nx==x2&&ny==y2))&&(nx>=0&&nx<n&&ny>=0&&ny<m))
                              if(i==p.temp||p.num+1<=3)
              {
                        node now;
                        now.x=nx;
                        now.y=ny;
                        if(i==p.temp)
                                now.num=p.num;
                        else
                                now.num=p.num+1;
                        now.temp=i;
                        if(now.x==x2&&now.y==y2)
                                        {printf("YES\n");
                                          return;
                                        }
                        que.push(now);
              }
          }
    }
    printf("NO\n");
}
int main()
{
    int q,i,j;
    int x1,y1,x2,y2;
    while(scanf("%d%d",&n,&m)==2,n+m)
    {
         for(i=0;i<n;i++)
               for(j=0;j<m;j++)
                     scanf("%d",&g[i][j]);
         scanf("%d",&q);
         while(q--)
         {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                if(g[x1-1][y1-1]==0||g[x2-1][y2-1]==0)
                {
                    printf("NO\n");
                    continue;
                }
                if(x1==x2&&y1==y2)
                {
                    printf("NO\n");
                    continue;
                }
                if(g[x1-1][y1-1]==g[x2-1][y2-1])
                       bfs(x1-1,y1-1,x2-1,y2-1);
                else
                       printf("NO\n");
         }
    }
    return 0;
}

