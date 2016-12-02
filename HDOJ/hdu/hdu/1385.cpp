#include"stdio.h"
#include"string.h"
#define MAX 150
#define INF 100000000
int n;
int tax[MAX];
int g[MAX][MAX];
int path[MAX][MAX];
void floyd()
{
    int temp;
    int k,i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            path[i][j]=j;
    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                temp=g[i][k]+g[k][j]+tax[k];
                if(temp<g[i][j])
                {
                    g[i][j]=temp;
                    path[i][j]=path[i][k];
                }
                else if(temp==g[i][j])
                {
                    if(path[i][j]>path[i][k])
                        path[i][j]=path[i][k];
                }
            }
        }
    }
}
int main()
{
    int i,j;
    int temp;
    int s,e;
    while(scanf("%d",&n),n)
    {
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
            {
                scanf("%d",&temp);
                if(temp==-1)    
                    g[i][j]=INF;
                else        
                    g[i][j]=temp;
            }
        for(i=1; i<=n; i++)    
             scanf("%d",&tax[i]);
        floyd();
        while(scanf("%d%d",&s,&e)==2)
        {
            if(s==-1 && e==-1)    break;
            printf("From %d to %d :\n",s,e);
            printf("Path: %d",s);
            temp=s;
            while(temp!=e)
            {
                printf("-->%d",path[temp][e]);
                temp=path[temp][e];
            }
            printf("\n");
            printf("Total cost : %d\n\n",g[s][e]);
        }
    }
    return 0;
}

