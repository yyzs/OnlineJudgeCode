#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 120
#define INF 1000000
using namespace std;
int g[MAX][MAX];
int path[MAX][MAX];
int tax[MAX];
int n;
void floyd()
{
    int temp;
    int k,i,j;
    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                temp=g[i][k]+g[k][j];
                if(temp<g[i][j])
                {
                    g[i][j]=temp;
                    path[i][j]=path[i][k];
                }
            }
        }
    }
}
int main()
{
    int m;
    int cas=0;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        if(cas!=0)
            puts("");
        scanf("%d",&n);
        n+=1;
        for(int i=1;i<=n-1;i++)
           {scanf("%d",&tax[i]);
            tax[i]*=-1;
            }
        tax[n]=tax[1];
        for(int i=1;i<=n;i++)
           for(int j=1;j<=n;j++)
           {
               if(i==j)
                   g[i][j]=0;
                else
                   g[i][j]=INF;
                path[i][j]=j;
           }
        scanf("%d",&m);
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a][b]=tax[b];
        }
        floyd();
        cas++;
        printf("CASE %d#\n",cas);
        printf("points : %d\n",-g[1][n]);
        printf("circuit : 1");
        int temp=1;
        while(temp!=n)
        {
            temp=path[temp][n];
            printf("->%d",temp==n?1:temp);
        }
        printf("\n");
    }
    return 0;
}

