#include "stdio.h"
#include "string.h"
int main()
{int i,j,n,m,ans;
 int t,a;
 scanf("%d",&t);
 while(t--)
 {scanf("%d%d",&n,&m);
   ans=0;
   for(i=0;i<n;i++)
       for(j=0;j<m;j++)
           {scanf("%d",&a);
             if(a==1)
                    ans++;
            }
      printf("%d\n",ans);
     }
     return 0;
    }

