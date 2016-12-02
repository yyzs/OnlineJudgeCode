#include "stdio.h"
#include "string.h"
int a[100010],n;
int lowbit(int x)
{
     return x&(-x);
}
void modify(int p,int del)
{
    while(p<=n)
    {
       a[p]+=del;
       p+=lowbit(p);
    }
}
int sum(int p)
{
    int res=0;
    while(p)
        {
          res+=a[p];
          p-=lowbit(p);
          }
    return res;
}
int main()
{
   int i,j;
   int x,b;
   while(scanf("%d",&n)==1&&n)
   {
      memset(a,0,sizeof(a));
         for(j=1;j<=n;j++)
      {
        scanf("%d%d",&x,&b);
        modify(x,1);
        modify(b+1,-1);
       }
      for(i=1;i<=n;i++)
             {
               if(i==1)
                    printf("%d",sum(i));
               else
                    printf(" %d",sum(i));
              }
       printf("\n");
    }
    return 0;
}

