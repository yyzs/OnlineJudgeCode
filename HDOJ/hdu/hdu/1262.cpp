#include "stdio.h"
#include "string.h"
int vis[10010];
int min(int x,int y)
{
    return x<y?x:y;
}
int max(int x,int y)
{
    return x>y?x:y;
}
int main()
{
    int i,j;
    int n;
    int flag;
    int m,x,y,c,d;
    memset(vis,0,sizeof(vis));
    vis[2]=1;
    for(i=2;i<=10000;i++)
       if(!vis[i])
          for(j=i+i;j<=10000;j+=i)
             vis[j]=1;
    while(scanf("%d",&n)==1)
    {
        flag=0;
        for(i=2;i<=n/2;i++)
        {
            if(!vis[i]&&!vis[n-i])
            {
                if(!flag)
                  {
                      x=min(i,n-i);
                      y=max(i,n-i);
                      m=y-x;
                      flag=1;
                      continue;
                  }
                c=min(i,n-i);
                d=max(i,n-i);
                if(d-c<m)
                   {
                       x=c;
                       y=d;
                       m=y-x;
                   }
            }
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}

