#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
struct wooden
{int l,w;
  int flag;
  }wood[5010];
int cmp(struct wooden a,struct wooden b)
{if(a.l==b.l)
        return a.w<b.w;
  return a.l<b.l;
  }
int main()
{int i,j,t,n;
  int ans;
  int temp;
  scanf("%d",&t);
  while(t--)
  {scanf("%d",&n);
    for(i=0;i<n;i++)
            {scanf("%d%d",&wood[i].l,&wood[i].w);
              wood[i].flag=0;
            }
     sort(wood,wood+n,cmp);
     ans=0;
     for(i=0;i<n;i++)
              if(!wood[i].flag)
                 {ans++;
                   temp=wood[i].w;
                   for(j=i+1;j<n;j++)
                      if(wood[j].w>=temp&&!wood[j].flag)
                            {wood[j].flag=1;
                              temp=wood[j].w;
                              }
                      }
        printf("%d\n",ans);
        }
     return 0;
    }

