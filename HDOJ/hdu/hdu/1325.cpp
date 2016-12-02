#include "stdio.h"
#include "string.h"
int bin[22],vis[22];
int uni(int a,int b)
{
   bin[b]=a;
}
int find(int x)
{int r=x;
 while(bin[r]!=r)
          r=bin[r];
 return r;
}
int main()
{int i,n,a,b,fa,fb;
 int ok,num,t=0;
 for(i=1;i<=20;i++)
               bin[i]=i;
 memset(vis,0,sizeof(vis));
 while(scanf("%d%d",&a,&b)==2)
 {ok=1;
  num=0;
  t++;
  if(a<0&&b<0)
                  break;
  if(a==0&&b==0)
          {printf("Case %d is a tree.\n",t);
           continue;
          }
   fa=find(a);
   fb=find(b);
   vis[a]=1;
   vis[b]=1;
   if(fa==fb)
            ok=0;
    else
            uni(fa,fb);
   while(scanf("%d%d",&a,&b)==2)
   {if(a==0&&b==0)
              break;
    vis[a]=1;
    vis[b]=1;
    fa=find(a);
    fb=find(b);
    if(fa==fb||fb!=b)
          ok=0;
    else
           uni(fa,fb);
   }
   for(i=1;i<=20;i++)
         if(vis[i]==1&&bin[i]==i)
                            num++;
    if(num>1||ok==0)
                      printf("Case %d is not a tree.\n",t);
    else
                      printf("Case %d is a tree.\n",t);
    for(i=1;i<=20;i++)
               bin[i]=i;
    memset(vis,0,sizeof(vis));
 }
 return 0;
}


