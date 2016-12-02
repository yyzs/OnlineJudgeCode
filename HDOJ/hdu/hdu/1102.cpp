#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 5010
using namespace std;
int g[MAX][MAX];
int bin[MAX];
struct node
{
  int u,v,w;
}n1[MAX];
int find(int x)
{
    int r=x;
    while(r!=bin[r])
          r=bin[r];
    return r;
}
int merge(int x,int y)
{
   bin[x]=y;
}
int cmp(struct node a,struct node b)
{
   return a.w<b.w;
}
int main()
{
  int n,m;
  int q,i,j;
  int a,b,x;
  int ans;
  int fx,fy;
  while(scanf("%d",&n)==1)
  {
    m=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            {
              scanf("%d",&x);
              if(j<i)
                {
                  n1[m].u=i;
                  n1[m].v=j;
                  n1[m].w=x;
                  m++;
                 }
             }
    for(i=1;i<=n;i++)
             bin[i]=i;
    sort(n1,n1+m,cmp);
    scanf("%d",&q);
    while(q--)
       {
           scanf("%d%d",&a,&b);
           fx=find(a);
           fy=find(b);
           if(fx!=fy)
                merge(fx,fy);
        }
   ans=0;
   for(i=0;i<m;i++)
       {
         fx=find(n1[i].u);
         fy=find(n1[i].v);
         if(fx!=fy)
                {merge(fx,fy);
                 ans+=n1[i].w;
                 }
        }
   printf("%d\n",ans);
   }
   return 0;
}

