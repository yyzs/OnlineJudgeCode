#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
int ans[1000002];
int main()
{
    char a[8];
    int n,m,len=0;
    int i,j,ok=1,sum=0;
    for(i=1;i<=1000000;i++)
           {itoa(i,a,10);
            len=strlen(a);
            ok=1;
              for(j=0;j<len-1;j++)
                if(a[j]=='6'&&a[j+1]=='2')
                   {
                       ok=0;
                       break;
                   }      
             if(ok&&strchr(a,'4')==NULL)
                 ans[i]=1;
              else
                 ans[i]=0;    
            }
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)
          break;
         sum=0;
         for(i=n;i<=m;i++)
            sum+=ans[i];
         printf("%d\n",sum);   
    }
    return 0;
}
