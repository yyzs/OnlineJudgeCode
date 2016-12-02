#include "stdio.h"
#include <algorithm>
using namespace std;
int bin[10002];
struct lian
{int a,b,r;
}ton[10002];
int find(int x)
{int r=x;
 while(r!=bin[r])
      r=bin[r];
return r;
}
int cmp(struct lian a,struct lian b)
{
   return  a.r<b.r;
}
int merge(int fx,int fy)
{
bin[fx]=fy;
}
int main()
{int  n,i,j,ans=0;
 int fx,fy;
 while(scanf("%d",&n)==1&&n!=0)
 {for(i=1;i<=n;i++)
          bin[i]=i;
  for(i=1;i<=n*(n-1)/2;i++)
           scanf("%d%d%d",&ton[i].a,&ton[i].b,&ton[i].r);
  sort(ton+1,ton+1+n*(n-1)/2,cmp);
  ans=0;
  for(i=1;i<=n*(n-1)/2;i++)
    {fx=find(ton[i].a);
     fy=find(ton[i].b);
     if(fx!=fy)
        {merge(fx,fy);
         ans=ans+ton[i].r;
        }
     }
 printf("%d\n",ans);
 }
 return 0;
}





