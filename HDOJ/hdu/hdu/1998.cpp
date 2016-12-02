#include "stdio.h"
#include "string.h"
#define MAX 25
int g[MAX][MAX];
int main()
{
    int temp=0;
    int n,i,j;
    int x,y1,y,x1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(g,0,sizeof(g));
        temp=0;
        x=0;
        y=n/2;
        while(1)
        {
            g[x][y]=temp+1;
            temp++;
            if(temp==n*n)
                break;
            y1=y;
            x1=x;
            x=((x-1)%n+n)%n;
            y=(y+1)%n;
            if(g[x][y])
            {
                y=y1;
                x=x1;
            }
            while(g[x][y])
                x=(x+1)%n;
           // printf("%d %d\n",x,y);
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                printf("%4d",g[i][j]);
            printf("\n");
        }
    }
    return 0;
}

