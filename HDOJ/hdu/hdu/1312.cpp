#include "stdio.h"
#include "string.h"
int ans;
char map[25][25];
int n,m;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
void dfs(int x,int y)
{int nx,ny;
 int i,j;
 ans++;
 map[x][y]='#';
 for(i=0;i<4;i++)
      {nx=x+dir[i][0];
       ny=y+dir[i][1];
       if(nx>=0&&nx<n&&ny>=0&&ny<m)
            {if(map[nx][ny]=='.')
                {
                 dfs(nx,ny);
                }
             }
        }
}
int main()
{int i,j;
 int sx,sy;
 while(scanf("%d%d",&m,&n)==2)
 {if(n==0||m==0)
      break;
  memset(map,0,sizeof(map));
  for(i=0;i<n;i++)
          scanf("%s",map[i]);
  for(i=0;i<n;i++)
          for(j=0;j<m;j++)
             if(map[i][j]=='@')
                {sx=i;
                 sy=j;
                 }
  ans=0;
  dfs(sx,sy);
  printf("%d\n",ans);
  }
  return 0;
}

