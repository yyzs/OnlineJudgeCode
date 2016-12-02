#include "stdio.h"
int s[1001],d[1001],vis[1001];
int main()
{
  int i,j;
  int n,t,rdu,ok;
  scanf("%d",&t);
  while(t--)
  {
      scanf("%d",&n);
      for(i=1;i<=n;i++)
        {scanf("%d",&d[i]);
         vis[i]=0;
        }
    for(i=1;i<=n;i++)
      scanf("%d",&s[i]);
    for(i=1;i<=n-1;i++)
      for(j=i+1;j<=n;j++)
       if(s[j]>s[i])
       {
           s[j]^=s[i]^=s[j]^=s[i];
           d[j]^=d[i]^=d[j]^=d[i];
       }
    rdu=0;
    for(i=1;i<=n;i++)
      {ok=0;
       for(j=d[i];j>=1;)
         {
           if(!vis[j])
             {
                 vis[j]=1;
                 ok=1;
                 break;
             }    
            else
             j--;
         }
       if(!ok) rdu+=s[i];   
      }
    printf("%d\n",rdu);
  }    
  return 0;
}
