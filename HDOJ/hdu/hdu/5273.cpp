#include "stdio.h"
#include "math.h"
#define MAX 1010
int a[MAX],cnt[MAX][MAX],sum[MAX][MAX];
int n;
int lowbit(int x)
{
    return x&(-x);
}
void update(int l,int r,int val)
{
      while(l<=n)
      {
               sum[l][r]+=val;
               l+=lowbit(l);
      }
}
int getsum(int x,int y)
{
      int s=0;
      while(x)
      {
           s+=sum[x][y];
           x-=lowbit(x);
      }
      return s;
}
int main()
{
     int q,i,j;
     int x,y;
     while(scanf("%d%d",&n,&q)==2)
     {
          for(i=1;i<=n;i++)
               scanf("%d",&a[i]);
          for(i=1;i<=n;i++)
               for(j=1;j<=n;j++)
                    {
                        cnt[i][j]=0;
                        sum[i][j]=0;
                    }
          for(i=1;i<=n;i++)
               for(j=i+1;j<=n;j++)
               {
                    if(a[j]<a[i])
                          cnt[i][j]=cnt[i][j-1]+1;
                    else
                          cnt[i][j]=cnt[i][j-1];
                    update(i,j,cnt[i][j]);
               }
           while(q--)
           {
               scanf("%d%d",&x,&y);
               printf("%d\n",getsum(y,y)-getsum(x-1,y));
           }
     }
     return 0;
}

