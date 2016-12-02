#include "stdio.h"
#include "string.h"
const int MAXN=250;
const int INF=0x3f3f3f3f;
bool vis[MAXN];
int pre[MAXN];
int temp[MAXN];
int dijkstra(int cost[][MAXN],int lowcost[],int n,int beg)
{
    for(int i=0;i<n;i++)
    {
        lowcost[i]=INF;
        vis[i]=false;
        pre[i]=-1;
    }
    lowcost[beg]=0;
    for(int j=0;j<n;j++)
    {
        int k=-1;
        int min=INF;
        for(int i=0;i<n;i++)
            if(!vis[i]&&lowcost[i]<min)
        {
            min=lowcost[i];
            k=i;
        }
        if(k==-1) break;
        vis[k]=true;
        for(int i=0;i<n;i++)
            if(!vis[i]&&lowcost[k]+cost[k][i]<lowcost[i])
                 {lowcost[i]=lowcost[k]+cost[k][i];
                  pre[i]=k;
                 }
    }
   // if(lowcost[n-1]==INF)
     //   return -1;
    return lowcost[n-1];
}
int main()
{
     int a,b,c;
     int n,m,i,j,k;
     int max;
     int cost[MAXN][MAXN],lowcost[MAXN];
     while(scanf("%d%d",&n,&m)==2,n+m)
     {
         for(i=0;i<n;i++)
              for(j=0;j<n;j++)
         {
                  cost[i][j]=INF;
         }
         while(m--)
         {
             scanf("%d%d%d",&a,&b,&c);
             a-=1;b-=1;
             if(cost[a][b]>c)
                 {cost[a][b]=c;
                  cost[b][a]=c;
                 }
         }
         max=0;
         for(i=1;i<n-1;i++)
         {
             for(j=0;j<n;j++)
             {
                 temp[j]=cost[i][j];
                 cost[i][j]=INF;
                 cost[j][i]=INF;
             }
             int res=dijkstra(cost,lowcost,n,0);
             if(res>max)
                max=res;
             for(j=0;j<n;j++)
                 cost[j][i]=cost[i][j]=temp[j];
         }
         if(max==INF)
            puts("Inf");
         else
            printf("%d\n",max);
     }
     return 0;
}

