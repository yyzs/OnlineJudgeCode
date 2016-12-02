#include "stdio.h"
int main()
{
    int m,n,i,j,ach=1;
    double s=0;
    while(scanf("%d\n",&m)!=EOF)
     {
         for(i=1;i<=m;i++)
           { 
               scanf("%d",&n);
                s=0;
                ach=1;
                for(j=1;j<=n;j++)
                {
                    s+=ach*(1.0/(j*1.00));
                    ach=-ach;
                }
              printf("%.2lf\n",s);
           }
     }
     return 0;
}

