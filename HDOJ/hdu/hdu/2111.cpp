#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
struct cherish
{int p,m;
}c[110];
int cmp(struct cherish a,struct cherish b)
{
     return a.p>b.p;
}
int main()
{int n,m,i,j,v;
  int  sum,lev;
  while(scanf("%d%d",&v,&n)==2&&v)
  {for(i=0;i<n;i++)
           {scanf("%d%d",&c[i].p,&c[i].m);
             }
    sort(c,c+n,cmp);
    sum=0;
    lev=v;
    for(i=0;i<n;i++)
    {if(lev<c[i].m)
         {sum+=c[i].p*lev;
           break;
           }
      else
            {sum+=c[i].p*c[i].m;
              lev-=c[i].m;
              }
     }
     printf("%d\n",sum);
     }
     return 0;
}

