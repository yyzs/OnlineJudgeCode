#include "stdio.h"
int main()
{
    int c,n,m,p[1000],h[1000];
    int i,j;
    double lev,now;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
             scanf("%d%d",&p[i],&h[i]);
        for(i=0;i<n-1;i++)
          for(j=i+1;j<n;j++)
           if(p[j]<p[i])
              {
                  p[j]^=p[i]^=p[j]^=p[i];
                 h[j]^=h[i]^=h[j]^=h[i];
              }
        lev=n;now=0;
          for(i=0;i<n;i++)
            {
                if(lev<p[i])
                   break;
              else
                if(lev/p[i]>h[i])
                   {now+=h[i];lev-=h[i]*p[i];}
                 else
                   {
                       now+=(double)(lev)/(p[i]);lev=0;
                   }
            }
            printf("%.2lf\n",now);
    }
    return 0;
}
