#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
struct fatmouse
{int w,s,dp,pos,point;
}f[10010];
int ans[10010];
int cmp(struct fatmouse a,struct fatmouse b)
{
  return a.s>b.s;
}
int main()
{int i,j,m,n;
 int rel,max;
 i=0;
 while(scanf("%d%d",&f[i].w,&f[i].s)==2)
 {f[i].pos=i+1;
  f[i].dp=0;
  i++;
  }
 n=i-1;
 sort(f,f+n,cmp);
 for(i=0;i<n;i++)
    {if(i==0)
            {f[i].dp=1;
             f[i].point=i;
             continue;
             }
    m=0;
    f[i].point=i;
    for(j=0;j<i;j++)
            if(f[j].w<f[i].w&&f[j].dp>m)
               {m=f[j].dp;
                f[i].point=j;
                }
     f[i].dp=m+1;
     }
 max=0;
 rel=0;
 for(i=0;i<n;i++)
    if(f[i].dp>max)
      {max=f[i].dp;
       rel=i;
       }
 printf("%d\n",max);
 memset(ans,0,sizeof(ans));
 j=f[rel].dp;
 i=rel;
 while(f[i].point!=i)
         {ans[j]=f[i].pos;
          i=f[i].point;
          j--;
           }
 ans[j]=f[i].pos;
 for(i=1;i<=f[rel].dp;i++)
          printf("%d\n",ans[i]);
 return 0;
 }

