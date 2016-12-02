#include "stdio.h"
#include <algorithm>
using namespace std;
int bin[102];
struct poi
{int a,b,r,ok;
}p[5000];
int  cmp(struct poi a,struct poi b)
{return a.r<b.r;
}
int find(int x)
{int r=x;
  while(r!=bin[r])
          r=bin[r];
 return r;
}
int uni(int a,int b)
{
  bin[b]=a;
}
int main()
{int n,i,ans;
int fa,fb;
 while(scanf("%d",&n)==1&&n)
 {for(i=1;i<=100;i++)
       bin[i]=i;
  ans=0;
  for(i=0;i<n*(n-1)/2;i++)
            { scanf("%d%d%d%d",&p[i].a,&p[i].b,&p[i].r,&p[i].ok);
             if(p[i].ok==1)
                    {fa=find(p[i].a);
                     fb=find(p[i].b);
                     uni(fa,fb);
                    }
            }
  sort(p,p+n*(n-1)/2,cmp);
  for(i=0;i<n*(n-1)/2;i++)
         {if(p[i].ok!=1)
             {fa=find(p[i].a);
              fb=find(p[i].b);
              if(fa!=fb)
               {uni(fa,fb);
                ans=ans+p[i].r;}
             }
         }
    printf("%d\n",ans);
  }
return 0;
}




