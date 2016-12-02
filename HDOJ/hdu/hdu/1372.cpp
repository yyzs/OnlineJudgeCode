#include "stdio.h"
#include "string.h"
#include "queue"
using namespace std;
int vis[30][30];
int dir[8][2]={1,2,2,1,2,-1,1,-2,-1,-2,-2,-1,-2,1,-1,2};
int sx,sy,ex,ey;
char s_x,e_x;
struct node
{int x,y,step;
};
queue<node>q;
int inmap(int x,int y)
{
   if(x<1||x>8||y<1||y>8)
          return 0;
   return 1;
}
void bfs(int x,int y)
{int i;
 while(!q.empty())
         q.pop();
 node start;
 start.x=x;
 start.y=y;
 start.step=0;
 vis[x][y]=1;
 q.push(start);
 while(!q.empty())
 {node now=q.front();
  q.pop();
  if(now.x==ex&&now.y==ey)
          {printf("To get from %c%d to %c%d takes %d knight moves.\n", s_x, sy, e_x, ey, now.step);
            return;
          }
  node next;
  for(i=0;i<8;i++)
          {next.x=now.x+dir[i][0];
           next.y=now.y+dir[i][1];
           if(!inmap(next.x,next.y))
                       continue;
           if(!vis[next.x][next.y])
            {
            next.step=now.step+1;
            q.push(next);
            if(next.x==ex&&next.y==ey)
                 {
                    printf("To get from %c%d to %c%d takes %d knight moves.\n", s_x, sy, e_x, ey, next.step);
                    return;
                  }
             }
           }
    }
}
int main()
{  while(scanf("%c%d%*c%c%d%*c",&s_x,&sy,&e_x,&ey)!=EOF)
  {memset(vis,0,sizeof(vis));
   sx=s_x-'a'+1;
   ex=e_x-'a'+1;
   bfs(sx,sy);
   }
   return 0;
}



