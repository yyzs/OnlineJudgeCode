#include "stdio.h"
#include "stdlib.h"
int main()
{
    int i,m,n,x,y,j[1000],f[1000];
    double lev,now,s,r[1000];
    while(scanf("%d%d",&m,&n))
    {
        if(m==-1&&n==-1)
          break;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&j[i],&f[i]);
            r[i]=(double)j[i]/(double)f[i];
        }
        for(x=0;x<n-1;x++)
           for(y=x+1;y<n;y++)
           {
               if(r[y]>r[x])
                 {s=r[y];r[y]=r[x];r[x]=s;
                  s=j[y];j[y]=j[x];j[x]=s;
                  s=f[y];f[y]=f[x];f[x]=s;
                 }
           }
        now=0;
        lev=m;
        for(i=0;i<n;i++)
        {
            if(lev>=f[i])
            {
                now+=j[i];
                lev-=f[i];
            }
            else
            {
                now+=lev*r[i];
                   lev=0;
            }
        }
        printf("%.3lf\n",now);
    }
    return 0;
}

