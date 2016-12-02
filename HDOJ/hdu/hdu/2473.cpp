#include "stdio.h"
#include "string.h"
int bin[11000000];
int flag[1100000];
char a[20];
int n,m;
int id;
int find(int x)
{
  if(x!=bin[x])
      bin[x]=find(bin[x]);
  return bin[x];
}
int merge(int fx,int fy)
{
  bin[fx]=fy;
}
int del(int x)
{
    bin[x]=id++;
}
int main()
{int i,j,ans;
 int x,y;
 int cas=0;
 while(scanf("%d%d",&n,&m)==2)
 {id=n+n;
  if(n==0&&m==0)
        break;
  for(i=0;i<=n-1;i++)
         bin[i]=i+n;
  for(i=n;i<=n+n+m;i++)
         bin[i]=i;
  while(m--)
  {memset(a,0,sizeof(a));
   scanf("%s",a);
   if(a[0]=='M')
         {scanf("%d%d",&x,&y);
          if(find(x)!=find(y))
                 merge(find(x),find(y));
          }
   else
         {scanf("%d",&x);
          del(x);
          }
   }
   ans=0;
   memset(flag,0,sizeof(flag));
   for(i=0;i<n;i++)
   {x=find(i);
    if(!flag[x])
         {ans++;
          flag[x]=1;
          }
    }
    cas++;
    printf("Case #%d: %d\n",cas,ans);
   }
    return 0;
}

