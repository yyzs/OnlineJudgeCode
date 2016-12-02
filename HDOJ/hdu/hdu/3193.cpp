#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "vector"
#define MAX 10010
#define INF 10010
using namespace std;
vector<int> v;
int a[MAX];
int d[MAX][20];
int b[MAX];
struct node
{
     int x,y;
}node[MAX];
void RMQ_init(int n)
{
    for(int i=0; i<n; i++)
    {
        d[i][0]=a[i];
    }
    for(int j=1; (1<<j)<=n; j++)
        for(int i=0; i+(1<<j)-1<n; i++)
        {
            d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
        }
}
int RMQ(int L,int R)
{
    int k=0;
    while((1<<(k+1))<=R-L+1)  k++;
    return min(d[L][k],d[R-(1<<k)+1][k]);
}
int cmp(struct node a,struct node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    int sum;
    int n,k;
    int maxnum=0;
    while(scanf("%d",&n)==1)
    {
          for(int i=0;i<=10000;i++)
               a[i]=INF;
         for(int i=0;i<n;i++)
         {
               scanf("%d%d",&node[i].x,&node[i].y);
               if(a[node[i].x]>node[i].y)
                     a[node[i].x]=node[i].y;
         }
         int ans=0;
         RMQ_init(10001);
         memset(b,0,sizeof(b));
         sort(node,node+n,cmp);
         for(int i=0;i<n;i++)
         {
             if(node[i].x==0)
             {
                  b[i]=1;
                  ans++;
                  continue;
             }
             if(RMQ(0,node[i].x-1)>=node[i].y)
             {
                 b[i]=1;
                 ans++;
             }
         }
         printf("%d\n",ans);
         for(int i=0;i<n;i++)
         {
              if(b[i])
                 printf("%d %d\n",node[i].x,node[i].y);
         }
    }
    return 0;
}

