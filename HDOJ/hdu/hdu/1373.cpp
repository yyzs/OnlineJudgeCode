#include "stdio.h"
#include "string.h"
#include "algorithm"
#define MAX 55
int g[MAX][MAX];
int p,e,bestn,cn;
int use[MAX];
char input[30];
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
   int len=strlen(input);
   while(scanf("%d",&p)==1&&p)
   {
      memset(g,0,sizeof(g));
      memset(use,0,sizeof(use));
      for(i=1;i<=p;i++)
            {
               memset(input,0,sizeof(input));
               scanf("%s",input);
               len=strlen(input);
               if(len==2)
                         continue;
               for(j=2;j<len;j++)
                         {g[i][input[j]-'A'+1]=1;
                          g[input[j]-'A'+1][i]=1;
                         }
              }
      cn=bestn=0;
      dfs(1);
      if(bestn==1)
              printf("1 channel needed.\n");
       else
              printf("%d channels needed.\n",bestn);
    }
    return 0;
}

