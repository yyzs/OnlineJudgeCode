#include "stdio.h"
#include "string.h"
#define MAX 60
#include "algorithm"
using namespace std;
int vis1[MAX][MAX],vis2[MAX][MAX];
int ans1[MAX][MAX],ans2[MAX][MAX];
int dis[2][2]= {1,1,1,-1};
char g[MAX][MAX];
int main()
{
    int ans=0;
    int n,m;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%s",g[i]);
            m=strlen(g[i]);
        }
        int ans1=0;
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(g[i][j]=='.')
                    continue;
                //printf("i,j,vis1,vis2:%d %d %d %d\n",i,j,vis1[i][j],vis2[i][j]);
                if(g[i][j]!='B'&&!vis1[i][j])
                {
                    ans1++;
                    int nowx=i;
                    int nowy=j;
                    int tempx;
                    int tempy;
                    while(1)
                    {
                         tempx=nowx+dis[0][0];
                         tempy=nowy+dis[0][1];
                      //  printf("tempx,tempy:%d %d\n",tempx,tempy);
                        if(tempx<0||tempx>=n||tempy<0||tempy>=m)
                            break;
                        if(g[tempx][tempy]=='B'||g[tempx][tempy]=='.')
                            break;
                        vis1[tempx][tempy]=1;
                        nowx=tempx;
                        nowy=tempy;
                    }
                }
                if(g[i][j]!='R'&&!vis2[i][j])
                {
                    ans1++;
                    int nowx1=i;
                    int nowy1=j;
                    int tempx1,tempy1;
                    while(1)
                    {
                        tempx1=nowx1+dis[1][0];
                        tempy1=nowy1+dis[1][1];
                   //     printf("tempx1,tempy1:%d %d\n",tempx1,tempy1);
                        if(tempx1<0||tempx1>=n||tempy1<0||tempy1>=m)
                            break;
                        if(g[tempx1][tempy1]=='R'||g[tempx1][tempy1]=='.')
                            break;
                        vis2[tempx1][tempy1]=1;
                        nowx1=tempx1;
                        nowy1=tempy1;
                    }
                }
            }
        printf("%d\n",ans1);
    }
    return 0;
}

