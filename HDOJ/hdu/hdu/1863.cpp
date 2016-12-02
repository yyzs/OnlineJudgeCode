#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
int n,m;
struct road
{int a,b,w;
}r[110];
int cmp(struct road a,struct road b)
{
   return a.w<b.w;
}
int bin[100];
int find(int x)
{int r=x;
  while(r!=bin[r])
        r=bin[r];
  return r;
}
int merge(int fx,int fy)
{
   bin[fx]=fy;
}
int main()
{int i,j;
  int ans;
  int fx,fy;
  int num;
  while(scanf("%d%d",&n,&m)==2&&n)
  {for(i=0;i<n;i++)
              scanf("%d%d%d",&r[i].a,&r[i].b,&r[i].w);
    for(i=0;i<m;i++)
              bin[i]=i;
    sort(r,r+n,cmp);
    ans=0;
    for(i=0;i<n;i++)
    {fx=find(r[i].a);
      fy=find(r[i].b);
      if(fx!=fy)
            {merge(fx,fy);
              ans+=r[i].w;
              }
        }
        num=0;
        for(i=0;i<m;i++)
               if(bin[i]==i)
                      num++;
        if(num>1)
                 printf("?\n");
        else
                 printf("%d\n",ans);
      }
      return 0;
    }






