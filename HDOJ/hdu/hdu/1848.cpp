#include "stdio.h"
#include "string.h"
int fib[15]={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987};
int sg[1050];
int makesg(int x)
{int i;
  int appear[105];
  if(x==0)
              return 0;
  else
              if(sg[x])
                      return sg[x];
   memset(appear,0,sizeof(appear));
   for(i=0;(i<15)&&(fib[i]<=x);i++)
              appear[makesg(x-fib[i])]=1;
    for(i=0;i<=100;i++)
               if(!appear[i])
                {sg[x]=i;
                  return i;
                  }
}
int main()
{int i,m,n,p;
  int ans;
  memset(sg,0,sizeof(sg));
  sg[0]=0;
  for(i=1000;i>=1;i--)
             sg[i]=makesg(i);
   while(scanf("%d%d%d",&m,&n,&p)==3,m+n+p)
   {        ans=sg[m]^sg[n]^sg[p];
             if(ans)
                           printf("Fibo\n");
             else
                            printf("Nacci\n");
     }
     return 0;
}

