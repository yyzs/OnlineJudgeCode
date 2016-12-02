#include "stdio.h"
int bin[10000002],ans[10000002];
int find(int x)
{
    int r=x;
    while(r!=bin[r])
       r=bin[r];
     return r;
}
int uni(int a,int b)
{
    if(ans[a]>ans[b])
      {
          bin[b]=a;
          ans[a]+=ans[b];
      }
      else
         {
             bin[a]=b;
             ans[b]+=ans[a];
         }
}
int main()
{
    int max,a,b,fa,fb;
    int n,i;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
           {
               printf("1\n");
               continue;
           }
        for(i=1;i<=10000000;i++)
           {
               bin[i]=i;
            ans[i]=1;
             }
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            fa=find(a);
            fb=find(b);
            if(fa!=fb)
                uni(fa,fb);
        }
        
         max=ans[1];
         for(i=1;i<=10000000;i++)
             if(ans[i]>max)
                  max=ans[i];
          printf("%d\n",max);
     }
     return 0;
}
