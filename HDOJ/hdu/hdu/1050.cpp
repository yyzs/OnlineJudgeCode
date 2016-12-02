#include "stdio.h"
int main()
{
    int s[201],t[201],ans[201]={0};
    int begin,end;
    int T,n,i,j,max;
    scanf("%d",&T);
    while(T--)
    {   scanf("%d",&n);
        for(i=0;i<201;i++)
          ans[i]=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&s[i],&t[i]);
            s[i]=(s[i]+1)/2;
            t[i]=(t[i]+1)/2;
            if(s[i]>t[i])
               s[i]^=t[i]^=s[i]^=t[i];
            begin=s[i];
            end=t[i];
            for(j=begin;j<=end;j++)
               ans[j]++;
        }
       max=0;
           for(i=1;i<=200;i++)
             if(ans[i]>max)
               max=ans[i];
          printf("%d\n",max*10);
    }
    return 0;
}
