#include "stdio.h"
int bin[1002];
int find(int x)
{int r=x;
 while(bin[r]!=r)
          r=bin[r];
 return r;
}
int merge(int fx,int fy)
{if(fx!=fy)
       bin[fx]=fy;
}
int main()
{int n,m;
 int i;
 int a,b,fa,fb,count;
 while(scanf("%d%d",&n,&m)==2&&n)
 {for(i=1;i<=n;i++)
         bin[i]=i;
  for(i=1;i<=m;i++)
        {scanf("%d%d",&a,&b);
         fa=find(a);
         fb=find(b);
         merge(fa,fb);
        }
    count=0;
    for(i=1;i<=n;i++)
         if(bin[i]==i)
                    count++;
   printf("%d\n",count-1);
 }
 return 0;
}

