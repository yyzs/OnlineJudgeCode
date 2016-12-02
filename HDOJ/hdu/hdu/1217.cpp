#include "stdio.h"
#include "string.h"
char c[1000][32],a[32],b[32];
double g[32][32],dis[32];
int n;
double max(double a,double b)
{
    return a>b?a:b;
}
void floyd(int n)
{
   int i,j,k;
   for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                g[i][j]=max(g[i][j],g[i][k]*g[k][j]);
                if(g[0][0]>1)
                     break;
            }
}
int find(char a[])
{
    int i;
    for(i=0;i<n;i++)
        if(strcmp(c[i],a)==0)
            return i;
}
int main()
{
  int cas=0;
  int i,j,k;
  int m;
  double x;
  int  s,t;
   while(scanf("%d",&n)==1&&n)
  {
    memset(c,0,sizeof(c));
    for(i=0;i<n;i++)
          scanf("%s",c[i]);
    scanf("%d",&m);
    for(i=0;i<n;i++)
          for(j=0;j<n;j++)
              g[i][j]=0;
    while(m--)
    {
          memset(a,0,sizeof(a));
          memset(b,0,sizeof(b));
          scanf("%s%lf%s",a,&x,b);
          s=find(a);
          t=find(b);
          g[s][t]=x;
     }
     floyd(n);
     cas++;
     if(g[0][0]>1)
           printf("Case %d: Yes\n",cas);
     else
           printf("Case %d: No\n",cas);
    }
    return 0;
}

