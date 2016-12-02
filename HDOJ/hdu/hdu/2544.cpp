#include "stdio.h"
#include "string.h"
#define MAX 200
#define INF 1000000
int n,m;
int min(int a,int b);
int d[MAX][MAX];
void floyd()
{
     int i,j,k;
     for(k=1;k<=n;k++)
           for(i=1;i<=n;i++)
                 for(j=1;j<=n;j++)
                     d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
}
int min(int a,int b)
{
       return a<b?a:b;
}
int main()
{
   int i,j,k;
   int a,b,c;
   while(scanf("%d%d",&n,&m)==2)
   {
      if(n==0&&m==0)
               break;
       for(i=1;i<=n;i++)
               for(j=1;j<=n;j++)
                    if(i==j)
                         d[i][j]=0;
                    else
                         d[i][j]=INF;
      while(m--)
      {
               scanf("%d%d%d",&a,&b,&c);
               d[a][b]=c;
               d[b][a]=c;
        }
        floyd();
        printf("%d\n",d[1][n]);
     }
     return 0;
}

