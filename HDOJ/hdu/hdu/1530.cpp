#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 55
int g[MAX][MAX];
int p,e,bestn,cn;
int use[MAX];
using namespace std;
void  dfs(int i)
{
    int flag,j;
    if(i>p)
           {if(cn>bestn)
                  bestn=cn;
             return;
            }
    flag=1;
    for(j=0;j<i;j++)
           {if(use[j]&&!g[j][i])
                {
                  flag=0;
                  break;
                  }
            }
    if(flag)
          {
           cn++;
           use[i]=1;
           dfs(i+1);
           use[i]=0;
           cn--;
           }
    if(cn+p-i>bestn)
           {
            dfs(i+1);
            }
}
int main()
{
   int i,j;
   while(scanf("%d",&p)==1&&p)
   {
      memset(g,0,sizeof(g));
      memset(use,0,sizeof(use));
      for(i=1;i<=p;i++)
            for(j=1;j<=p;j++)
                {scanf("%d",&g[i][j]);
                 }
      cn=bestn=0;
      dfs(1);
      printf("%d\n",bestn);
    }
    return 0;
}

