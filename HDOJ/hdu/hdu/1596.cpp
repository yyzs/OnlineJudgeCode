#include "stdio.h"
#include "string.h"
#include "math.h"
#define MAX 1010
#define INF 10000;
double g[MAX][MAX];
int n;
void floyd()
{
    int i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(g[i][j]<g[i][k]*g[k][j])
                    g[i][j]=g[i][k]*g[k][j];
            }
        }
    }
}
int main()
{
    int i,j;
    double ans;
    int q,s,t;
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
               scanf("%lf",&g[i][j]);
        scanf("%d",&q);
        floyd();
        while(q--)
        {
            scanf("%d%d",&s,&t);
            if(g[s][t])
                 printf("%.3lf\n",g[s][t]);
            else
                printf("What a pity!\n");
        }
    }
    return 0;
}

