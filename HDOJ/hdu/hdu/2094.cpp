#include "stdio.h"
#include "string.h"
char a[1001][20],b[1001][20];
int main()
{
  int i,j,n,ans[20];
  int yes=1,ok;
  while(scanf("%d",&n)==1&&n)
  {
    for(i=0;i<n;i++)
                            {memset(a[i],0,sizeof(a[i]));
                             memset(b[i],0,sizeof(b[i]));
                             }
    memset(ans,0,sizeof(ans));
    for(i=0;i<n;i++)
                            scanf("%s%s",a[i],b[i]);
    ok=0;
    for(i=0;i<n;i++)
             {yes=0;
              for(j=0;j<n;j++)
                   {if(strcmp(a[i],b[j])==0)
                           {yes=1;break;}
                    }
                if(yes==0)
                       {if(!ok)
                           {ok=1;strcpy(ans,a[i]);}
                        else
                        {if(strcmp(a[i],ans)!=0)
                            {ok=0;break;}
                        }
                       }
                }
    if(ok==1)
                  printf("Yes\n");
    else
                  printf("No\n");
      }
      return 0;
      }

