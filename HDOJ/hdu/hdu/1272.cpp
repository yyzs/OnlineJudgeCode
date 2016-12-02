#include "stdio.h"
#include "string.h"
int bin[100002],vis[100002];
int find(int x)
{int r=x;
 while(bin[r]!=r)
          r=bin[r];
  return r;
}
int uni(int a,int b)
{
    bin[a]=b;
}
int main()
{int i;
 int ok=1,num=0;
 int a,b,fa,fb,m,n,fm,fn;
 memset(vis,0,sizeof(vis));
 for(i=0;i<=100000;i++)
          bin[i]=i;
while(scanf("%d%d",&a,&b)==2)
{if(a==-1&&b==-1)
        break;
 if(a==0&&b==0)
      {printf("Yes\n");
       continue;
      }
 ok=1;
 num=0;
 fa=find(a);
 fb=find(b);
 vis[a]=1;
 vis[b]=1;
 uni(fa,fb);
 while(scanf("%d%d",&m,&n)==2)
 {fm=find(m);
   fn=find(n);
   if(m==0&&n==0)
          break;
    vis[m]=1;
    vis[n]=1;
    if(fm==fn)
           ok=0;
    else
           uni(fm,fn);
   }
   for(i=0;i<=100000;i++)
         if(vis[i]==1&&bin[i]==i)
                num++;
    if(num>1||ok==0)
               printf("No\n");
    else
              printf("Yes\n");
    memset(vis,0,sizeof(vis));
   for(i=0;i<=100000;i++)
             bin[i]=i;
    }
    return 0;
}



